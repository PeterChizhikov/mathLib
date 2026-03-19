#pragma once
#include <climits>

namespace mathOperations {

constexpr int INT_MAX_VALUE = INT_MAX;
constexpr int INT_MIN_VALUE = INT_MIN;



inline int sum(const int a, const int b, int &res)
{
    if(__builtin_add_overflow(a, b, &res))
    {
        return -2;
    }
    return 0;
}

inline int subtract(const int a, const int b, int &res)
{
    if (__builtin_sub_overflow(a, b, &res)) {
        return -2; 
    }
    return 0;
}

inline int multiply(const int a, const int b, int &res)
{

    if (__builtin_mul_overflow(a, b, &res)) {
        return -2;
    }
    return 0;
}


inline int divide(const int a, const int b, int &res)
{
    if (b == 0) return -1; 
    
    if ((a == INT_MIN_VALUE) && (b == -1)) return -2;
    
    res = a / b;
    return 0;
}

inline int pow(const int a, const int b, int &res)
{
    if (b < 0) return -1;


    if(((b == 0) && (a != 0)) || (a == 1)){
        res = 1;
        return 0;
    }

    if (a == 0) {
        if (b == 0)
        {
            return -3;
        } 
        res = 0;
        return 0;
    }

    res = 1;
    for (int i = 0; i < b; i++) {
        int temp;
        if (__builtin_mul_overflow(res, a, &temp)) {
            return -2;
        }
        res = temp;
    }
    return 0;
}
inline int factorial(const int a, int &res)
{
    if (a < 0) return -1;
    if (a == 0 || a == 1) {
        res = 1;
        return 0;
    }
    if(a > 12)
    {
        return -2;
    }

    if (factorial(a - 1, res) != 0) return -1;


    if (res > INT_MAX_VALUE / a) return -2;

    res = res*a;
    return 0;
}

}    
