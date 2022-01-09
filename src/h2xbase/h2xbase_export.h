#ifndef H2XBASE_EXPORT_H
#define H2XBASE_EXPORT_H

#if defined(H2XCOMPONENT_BUILD)

    #if defined(WIN32) || defined(WIN64)
        // windows platform

        #if defined(H2XBASE_IMPLENT)

            #define H2XBASE_API __declspec(dllexport)
            #define H2XBASE_API_PRIVATE __declspec(dllexport)

        #else   // defined(H2XBASE_IMPLENT)

            #define H2XBASE_API __declspec(dllimport)
            #define H2XBASE_API_PRIVATE __declspec(dllimport)

        #endif  // defined(H2XBASE_IMPLENT)

    #else // defined(WIN32) || defined(WIN64)
        // other platform

        #if defined(H2XBASE_IMPLENT)

            #define H2XBASE_API __attribute__((visibility("default")))
            #define H2XBASE_API_PRIVATE __attribute__((visibility("default")))

        #else // defined(H2XBASE_IMPLENT)

            #define H2XBASE_API
            #define H2XBASE_API_PRIVATE

        #endif // defined(H2XCOMPONENT_BUILD)

    #endif // defined(WIN32) || defined(WIN64)

#else // defined(H2XCOMPONENT_BUILD)

    #define H2XBASE_API
    #define H2XBASE_API_PRIVATE

#endif // defined(H2XCOMPONENT_BUILD)


#endif // H2XBASE_EXPORT_H
