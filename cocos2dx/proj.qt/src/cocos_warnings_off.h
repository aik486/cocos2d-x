#if defined(__clang__)

#pragma clang diagnostic push

#pragma clang diagnostic ignored "-Wignored-qualifiers"
#pragma clang diagnostic ignored "-Woverloaded-virtual"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Winconsistent-missing-override"

#elif defined(__GNUC__)

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wignored-qualifiers"
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#elif defined(_MSC_VER)

#pragma warning(push)

#pragma warning(disable : 4251)
#pragma warning(disable : 4005)

#endif
