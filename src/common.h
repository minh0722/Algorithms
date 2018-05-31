#ifndef COMMON_H
#define COMMON_H

#ifdef ALGO_API_EXPORT
#define ALGO_API __declspec(dllexport)
#else
#define ALGO_API __declspec(dllimport)
#endif

#endif // COMMON_H
