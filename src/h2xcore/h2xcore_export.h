#ifndef H2XCORE_EXPORT_H
#define H2XCORE_EXPORT_H

#if defined(H2XCOMPONENT_BUILD)

    #if defined(WIN32) || defined(WIN64)
        // windows platform

        #if defined(H2XCORE_IMPLENT)

            #define H2XCORE_API __declspec(dllexport)
            #define H2XCORE_API_PRIVATE __declspec(dllexport)

        #else   // defined(H2XCORE_IMPLENT)

            #define H2XCORE_API __declspec(dllimport)
            #define H2XCORE_API_PRIVATE __declspec(dllimport)

        #endif  // defined(H2XCORE_IMPLENT)

    #else // defined(WIN32) || defined(WIN64)
        // other platform

        #if defined(H2XCORE_IMPLENT)

            #define H2XCORE_API __attribute__((visibility("default")))
            #define H2XCORE_API_PRIVATE __attribute__((visibility("default")))

        #else // defined(H2XCORE_IMPLENT)

            #define H2XCORE_API
            #define H2XCORE_API_PRIVATE

        #endif // defined(H2XCOMPONENT_BUILD)

    #endif // defined(WIN32) || defined(WIN64)

#else // defined(H2XCOMPONENT_BUILD)

    #define H2XCORE_API
    #define H2XCORE_API_PRIVATE

#endif // defined(H2XCOMPONENT_BUILD)

#endif // H2XCORE_EXPORT_H
