/* Copyright (c) 2012 Scott Lembcke and Howling Moon Software
 * Copyright (c) 2012 cocos2d-x.org
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "CCDrawNode.h"
#include "support/CCPointExtension.h"
#include "shaders/CCShaderCache.h"
#include "CCGL.h"
#include "support/CCNotificationCenter.h"
#include "CCEventType.h"

NS_CC_BEGIN

// ccVertex2F == CGPoint in 32-bits, but not in 64-bits (OS X)
// that's why the "v2f" functions are needed
static ccVertex2F v2fzero = {0.0f,0.0f};

const ccColor4F CCDrawNode::NO_COLORF{0.f, 0.f, 0.f, 0.f};
const ccColor4B CCDrawNode::NO_COLOR{0, 0, 0, 0};

static inline ccVertex2F v2f(float x, float y)
{
	ccVertex2F ret = {x, y};
	return ret;
}

static inline ccVertex2F v2fadd(const ccVertex2F &v0, const ccVertex2F &v1)
{
	return v2f(v0.x+v1.x, v0.y+v1.y);
}

static inline ccVertex2F v2fsub(const ccVertex2F &v0, const ccVertex2F &v1)
{
	return v2f(v0.x-v1.x, v0.y-v1.y);
}

static inline ccVertex2F v2fmult(const ccVertex2F &v, float s)
{
	return v2f(v.x * s, v.y * s);
}

static inline ccVertex2F v2fperp(const ccVertex2F &p0)
{
	return v2f(-p0.y, p0.x);
}

static inline ccVertex2F v2fneg(const ccVertex2F &p0)
{
	return v2f(-p0.x, - p0.y);
}

static inline float v2fdot(const ccVertex2F &p0, const ccVertex2F &p1)
{
	return  p0.x * p1.x + p0.y * p1.y;
}

static inline ccVertex2F v2fforangle(float _a_)
{
	return v2f(cosf(_a_), sinf(_a_));
}

static inline ccVertex2F v2fnormalize(const ccVertex2F &p)
{
	CCPoint r = ccpNormalize(ccp(p.x, p.y));
	return v2f(r.x, r.y);
}

static inline ccVertex2F __v2f(const CCPoint &v)
{
//#ifdef __LP64__
	return v2f(v.x, v.y);
// #else
// 	return * ((ccVertex2F*) &v);
// #endif
}

static inline ccTex2F __t(const ccVertex2F &v)
{
	return *(const ccTex2F*)&v;
}

// implementation of CCDrawNode

CCDrawNode::CCDrawNode()
: m_uVao(0)
, m_uVbo(0)
, m_nBufferCapacity(0)
, m_nBufferCount(0)
, m_pBuffer(NULL)
, m_bDirty(false)
{
    m_sBlendFunc.src = CC_BLEND_SRC;
    m_sBlendFunc.dst = CC_BLEND_DST;
}

CCDrawNode::~CCDrawNode()
{
    free(m_pBuffer);
    m_pBuffer = NULL;

    glDeleteBuffers(1, &m_uVbo);
    m_uVbo = 0;

#if CC_TEXTURE_ATLAS_USE_VAO
    glDeleteVertexArrays(1, &m_uVao);
    ccGLBindVAO(0);
    m_uVao = 0;
#endif

#if CC_ENABLE_CACHE_TEXTURE_DATA
    CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, EVENT_COME_TO_FOREGROUND);
#endif
}

CCDrawNode* CCDrawNode::create()
{
    CCDrawNode* pRet = new CCDrawNode();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }

    return pRet;
}

void CCDrawNode::ensureCapacity(unsigned int count)
{
    reserve(m_nBufferCount + count);
}

bool CCDrawNode::init()
{
    m_sBlendFunc.src = CC_BLEND_SRC;
    m_sBlendFunc.dst = CC_BLEND_DST;

    setShaderProgram(CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionLengthTexureColor));

    reserve(4);

#if CC_TEXTURE_ATLAS_USE_VAO
    glGenVertexArrays(1, &m_uVao);
    ccGLBindVAO(m_uVao);
#endif

    glGenBuffers(1, &m_uVbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_uVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(ccV2F_C4B_T2F) * m_nBufferCapacity, m_pBuffer, GL_STREAM_DRAW);

    glEnableVertexAttribArray(kCCVertexAttrib_Position);
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, sizeof(ccV2F_C4B_T2F), (GLvoid *)offsetof(ccV2F_C4B_T2F, vertices));

    glEnableVertexAttribArray(kCCVertexAttrib_Color);
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ccV2F_C4B_T2F), (GLvoid *)offsetof(ccV2F_C4B_T2F, colors));

    glEnableVertexAttribArray(kCCVertexAttrib_TexCoords);
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, sizeof(ccV2F_C4B_T2F), (GLvoid *)offsetof(ccV2F_C4B_T2F, texCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

#if CC_TEXTURE_ATLAS_USE_VAO
    ccGLBindVAO(0);
#endif

    CHECK_GL_ERROR_DEBUG();

    m_bDirty = true;

#if CC_ENABLE_CACHE_TEXTURE_DATA
    // Need to listen the event only when not use batchnode, because it will use VBO
    CCNotificationCenter::sharedNotificationCenter()->addObserver(this,
            callfuncO_selector(CCDrawNode::listenBackToForeground),
            EVENT_COME_TO_FOREGROUND,
            NULL);
#endif

    return true;
}

void CCDrawNode::render()
{
    if (m_bDirty)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_uVbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(ccV2F_C4B_T2F)*m_nBufferCount, m_pBuffer, GL_STREAM_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        m_bDirty = false;
    }
    if (m_nBufferCount == 0)
        return;
#if CC_TEXTURE_ATLAS_USE_VAO
    ccGLBindVAO(m_uVao);
#else
    ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);
    glBindBuffer(GL_ARRAY_BUFFER, m_uVbo);
    // vertex
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, sizeof(ccV2F_C4B_T2F), (GLvoid *)offsetof(ccV2F_C4B_T2F, vertices));

    // color
    glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(ccV2F_C4B_T2F), (GLvoid *)offsetof(ccV2F_C4B_T2F, colors));

    // texcood
    glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE, sizeof(ccV2F_C4B_T2F), (GLvoid *)offsetof(ccV2F_C4B_T2F, texCoords));
#endif

    glDrawArrays(GL_TRIANGLES, 0, m_nBufferCount);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    CC_INCREMENT_GL_DRAWS(1);
    CHECK_GL_ERROR_DEBUG();
}

void CCDrawNode::draw()
{
    CC_NODE_DRAW_SETUP();
    ccGLBlendFunc(m_sBlendFunc.src, m_sBlendFunc.dst);

    render();
}

void CCDrawNode::drawDot(const CCPoint &pos, float radius, const ccColor4F &color)
{
    drawDot(pos, radius, ccc4BFromccc4F(color));    
}

void CCDrawNode::drawDot(const CCPoint &pos, float radius, const ccColor4B &color)
{
    unsigned int vertex_count = 2*3;
    ensureCapacity(vertex_count);

	ccV2F_C4B_T2F a = {{pos.x - radius, pos.y - radius}, color, {-1.0, -1.0} };
	ccV2F_C4B_T2F b = {{pos.x - radius, pos.y + radius}, color, {-1.0,  1.0} };
	ccV2F_C4B_T2F c = {{pos.x + radius, pos.y + radius}, color, { 1.0,  1.0} };
	ccV2F_C4B_T2F d = {{pos.x + radius, pos.y - radius}, color, { 1.0, -1.0} };

    ccV2F_C4B_T2F_Triangle *triangles = (ccV2F_C4B_T2F_Triangle *)(m_pBuffer + m_nBufferCount);
    ccV2F_C4B_T2F_Triangle triangle0 = {a, b, c};
    ccV2F_C4B_T2F_Triangle triangle1 = {a, c, d};
    triangles[0] = triangle0;
    triangles[1] = triangle1;

	m_nBufferCount += vertex_count;

	m_bDirty = true;
}

void CCDrawNode::drawSegment(const CCPoint &from, const CCPoint &to, float radius, const ccColor4F &color)
{
	drawSegment(from, to, radius, ccc4BFromccc4F(color));
}

void CCDrawNode::drawSegment(const CCPoint &from, const CCPoint &to, float radius, const ccColor4B &color)
{
	drawSegment(from, to, radius, radius, color);
}

void CCDrawNode::drawSegment(const CCPoint &from, const CCPoint &to, float width, float height, const ccColor4F &color)
{
	drawSegment(from, to, width, height, ccc4BFromccc4F(color));
}

void CCDrawNode::drawSegment(const CCPoint &from, const CCPoint &to, float width, float height, const ccColor4B &color)
{
	if (width != height)
	{		
		bool horizontal;
		if (from.y == to.y)
		{
			horizontal = true;
		} else
		{
			auto p3 = from - to;
			int angle = int(kmRadiansToDegrees(p3.getAngle()));
			if (angle < 0)
				angle = 360 - (-angle % 360);
			else if (angle > 360)
				angle = angle % 360;
		
			horizontal = angle <= 45 || angle >= 360 - 45 ||
				(angle >= 180 - 45 && angle <= 180 + 45);
		}
		if(!horizontal)
		{
			std::swap(width, height);
		}
	}
    
    unsigned int vertex_count = 6*3;
    ensureCapacity(vertex_count);

	ccVertex2F a = __v2f(from);
	ccVertex2F b = __v2f(to);


	ccVertex2F n = v2fnormalize(v2fperp(v2fsub(b, a)));
	ccVertex2F t = v2fperp(n);

	ccVertex2F nw = v2fmult(n, height);
	ccVertex2F tw = v2fmult(t, width);
	ccVertex2F v0 = v2fsub(b, v2fadd(nw, tw));
	ccVertex2F v1 = v2fadd(b, v2fsub(nw, tw));
	ccVertex2F v2 = v2fsub(b, nw);
	ccVertex2F v3 = v2fadd(b, nw);
	ccVertex2F v4 = v2fsub(a, nw);
	ccVertex2F v5 = v2fadd(a, nw);
	ccVertex2F v6 = v2fsub(a, v2fsub(nw, tw));
	ccVertex2F v7 = v2fadd(a, v2fadd(nw, tw));

	ccV2F_C4B_T2F_Triangle *triangles = (ccV2F_C4B_T2F_Triangle *)(m_pBuffer + m_nBufferCount);

	ccVertex2F negn = v2fneg(n);	
	ccVertex2F nplust = v2fadd(n, t);
	ccVertex2F negnplust = v2fneg(nplust);
	ccVertex2F nminust = v2fsub(n, t);
	ccVertex2F tminusn = v2fsub(t, n);
    
    triangles[0]  = {
        {v0, color, __t(negnplust)},
        {v1, color, __t(nminust)},
        {v2, color, __t(negn)},
    };

    triangles[1] = {
        {v3, color, __t(n)},
        {v1, color, __t(nminust)},
        {v2, color, __t(negn)},
    };

   triangles[2] = {
        {v3, color, __t(n)},
        {v4, color, __t(negn)},
        {v2, color, __t(negn)},
    };

    triangles[3] = {
        {v3, color, __t(n)},
        {v4, color, __t(negn)},
        {v5, color, __t(n)},
    };

    triangles[4] = {
        {v6, color, __t(tminusn)},
        {v4, color, __t(negn)},
        {v5, color, __t(n)},
    };

    triangles[5] = {
        {v6, color, __t(tminusn)},
        {v7, color, __t(nplust)},
        {v5, color, __t(n)},
    };

	m_nBufferCount += vertex_count;

	m_bDirty = true;
}

void CCDrawNode::drawPolygon(const CCPoint *verts, unsigned int count, const ccColor4F &fillColor, float borderWidth, const ccColor4F &borderColor)
{
	drawPolygon(verts, count, ccc4BFromccc4F(fillColor), borderWidth, ccc4BFromccc4F(borderColor));
}

void CCDrawNode::drawPolygon(const CCPoint *verts, unsigned int count, const ccColor4B &fillColor, float borderWidth, const ccColor4B &borderColor)
{
	if (count == 0)
		return;
	
	if (count >= 2 && verts[count - 1].equals(verts[0]))
		count--;
	
	bool outline = (borderColor.a > 0 && borderWidth > 0.0f);
	
	auto triangle_count = outline ? (3 * count - 2) : (count - 2);
	auto vertex_count = 3 * triangle_count;
	ensureCapacity(vertex_count);
	
	ccV2F_C4B_T2F_Triangle *triangles = (ccV2F_C4B_T2F_Triangle *)(m_pBuffer + m_nBufferCount);
	ccV2F_C4B_T2F_Triangle *cursor = triangles;
	
	if (count > 2)
	{
		for (unsigned i = 0; i < count - 2; i++)
		{
			auto v1 = __v2f(verts[0]);
			auto v2 = __v2f(verts[i+1]);
			auto v3 = __v2f(verts[i+2]);
			
			*cursor++ = {
			   { v1, fillColor, __t(v2fzero) },
			   { v2, fillColor, __t(v2fzero) },
			   { v3, fillColor, __t(v2fzero) },
			};
		}
	}
	
	if(outline)
	{
		struct ExtrudeVerts {ccVertex2F offset, n;};
		struct ExtrudeVerts* extrude = (struct ExtrudeVerts*)malloc(sizeof(struct ExtrudeVerts)*count);
		memset(extrude, 0, sizeof(struct ExtrudeVerts)*count);
		
		for (unsigned i = 0; i < count; i++)
		{
			auto v0 = __v2f(verts[(i-1+count)%count]);
			auto v1 = __v2f(verts[i]);
			auto v2 = __v2f(verts[(i+1)%count]);
			
			auto n1 = v2fnormalize(v2fperp(v2fsub(v1, v0)));
			auto n2 = v2fnormalize(v2fperp(v2fsub(v2, v1)));
			
			auto offset = v2fmult(v2fadd(n1, n2), 1.0f / (v2fdot(n1, n2) + 1.0f));
			struct ExtrudeVerts tmp = {offset, n2};
			extrude[i] = tmp;
		}
		
		for(unsigned i = 0; i < count; i++)
		{
			int j = (i+1)%count;
			auto v0 = __v2f(verts[i]);
			auto v1 = __v2f(verts[j]);
			
			auto n0 = extrude[i].n;
			
			auto offset0 = extrude[i].offset;
			auto offset1 = extrude[j].offset;
			
			auto inner0 = v2fsub(v0, v2fmult(offset0, borderWidth));
			auto inner1 = v2fsub(v1, v2fmult(offset1, borderWidth));
			auto outer0 = v2fadd(v0, v2fmult(offset0, borderWidth));
			auto outer1 = v2fadd(v1, v2fmult(offset1, borderWidth));
			
			*cursor++ =  {
				{inner0, borderColor, __t(v2fneg(n0))},
				{inner1, borderColor, __t(v2fneg(n0))},
				{outer1, borderColor, __t(n0)}
			};
			
			*cursor++ = {
				{inner0, borderColor, __t(v2fneg(n0))},
				{outer0, borderColor, __t(n0)},
				{outer1, borderColor, __t(n0)}
			};
		}
		
		free(extrude);
	}

	m_nBufferCount += vertex_count;

	m_bDirty = true;
}

void CCDrawNode::drawPolygon(const CCPoint *vert, unsigned int count, float borderWidth, float borderHeight, const ccColor4F &borderColor, const ccColor4F &fillColor)
{
	drawPolygon(vert, count, borderWidth, borderHeight, ccc4BFromccc4F(borderColor), ccc4BFromccc4F(fillColor));	
}

void CCDrawNode::drawPolygon(const CCPoint *vert, unsigned int count, float borderWidth, float borderHeight, const ccColor4B &borderColor, const ccColor4B &fillColor)
{
	if (count == 0)
		return;

	if (count >= 2 && vert[count - 1].equals(vert[0]))
		count--;

	if (fabs(borderWidth - borderHeight) >= FLT_EPSILON)
	{
		if (fillColor.a > 0)
			drawPolygon(vert, count, fillColor, 0.f, borderColor);

		for (unsigned i = 0; i < count; i++)
		{
			unsigned next = i + 1;
			if (next == count)
				next = 0;

			drawSegment(vert[i], vert[next], borderWidth, borderHeight, borderColor);
		}
	} else
	{
		drawPolygon(vert, count, fillColor, borderWidth, borderColor);
	}
}

void CCDrawNode::clear()
{
    if (m_nBufferCount == 0)
        return;
    
    m_nBufferCount = 0;
    m_bDirty = true;
}

void CCDrawNode::shrink()
{
    if (m_nBufferCapacity == m_nBufferCount)
        return;
    
    m_nBufferCapacity = 0;
    reserve(m_nBufferCount);
}

ccBlendFunc CCDrawNode::getBlendFunc() const
{
    return m_sBlendFunc;
}

void CCDrawNode::setBlendFunc(const ccBlendFunc &blendFunc)
{
    m_sBlendFunc = blendFunc;
}

/** listen the event that coming to foreground on Android
 */
void CCDrawNode::listenBackToForeground(CCObject *)
{
    init();
}

void CCDrawNode::reserve(int count)
{
    if (count > m_nBufferCapacity)
    {
        m_nBufferCapacity = count;
        m_pBuffer = (ccV2F_C4B_T2F*)realloc(m_pBuffer, m_nBufferCapacity*sizeof(ccV2F_C4B_T2F));
    }
}

NS_CC_END
