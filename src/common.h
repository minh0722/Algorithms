#ifndef COMMON_H
#define COMMON_H

#ifdef ALGO_API_EXPORT

    #if defined(_MSC_VER)
        #define ALGO_API __declspec(dllexport)
    #elif defined(__GNUC__)
        #define ALGO_API __attribute__((visibility("default")))        
    #endif // _MSC_VER

#else

    #if defined(_MSC_VER)        
        #define ALGO_API __declspec(dllimport)
    #elif defined(__GNUC__)
        #define ALGO_API
    #endif // _MSC_VER

#endif // ALGO_API_EXPORT

#endif // COMMON_H