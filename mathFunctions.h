#pragma once 

namespace mathOperations{

constexpr int INT_MAX_VALUE = 2147483647;
constexpr int INT_MIN_VALUE =  -2147483648;



inline int sum(const int a, const int b, int &res)
{
    if ((b > 0 && a > INT_MAX_VALUE - b) ||
        (b < 0 && a < INT_MIN_VALUE - b)) {
        return -2;
    }
    res = a + b;
    return 0;

}

inline int subtract(const int a, const int b, int &res)
{
    if ((b < 0 && a > INT_MAX_VALUE + b) ||
        (b > 0 && a < INT_MIN_VALUE + b)) {
        return -2; 
    }
    res = a - b;
    return 0;

}

inline int multiply(const int a, const int b, int &res)
{
    if (a > 0) {
        if (b > 0 && a > INT_MAX_VALUE / b) return -2;
        if (b < 0 && b < INT_MIN_VALUE / a) return -2;
    } else if (a < 0) {
        if (b > 0 && a < INT_MIN_VALUE / b) return -2;
        if (b < 0 && b < INT_MAX_VALUE / a) return -2;
    }
    res = a * b;
    return 0;

}


inline int divide(const int a, const int b, int &res)
{
    if (b == 0) return -1; 
    
    if (a == INT_MIN_VALUE && b == -1) return -2;
    
    res = a / b;
    return 0;

}

inline int pow(const int a, const int b, int &res)
{
    if(b < 0)
{
	return -1;
}

    if(b == 0 || a == 1)
{
	res = 1;
	return 0;

}

if(a ==0)
{
	if(b ==0) return -3
	res = 0;
	return 0;
}

if(b == 0)
{
res = 0;
return 0;
}

    res = a;

    for(size_t rateIndex = 1; rateIndex < b; rateIndex++)
	{
	// оба положительные
        if(res > 0 && a > 0) {
            if(res > INT_MAX_VALUE / a) {
                return -2;  
            }
        }
        // оба отрицательные
        else if(res < 0 && a < 0) {
   
            if(res == INT_MIN_VALUE || a == INT_MIN_VALUE) {
                return -2;  
            }
            
            if(-res > INT_MAX_VALUE / -a) {
                return -2;  
            }
        }
        // разные знаки (результат отрицательный)
        else if((res > 0 && a < 0) || (res < 0 && a > 0)) {
            // Проверка для отрицательного результата
            if(a < 0 && a == INT_MIN_VALUE) {
                return -2;
            }
            if(res < 0 && res == INT_MIN_VALUE) {
                return -2;
            }
            // res > 0, a < 0
            if(res > 0 && a < 0) {
                if(res > -(INT_MIN_VALUE / a)) {
                    return -2;
                }
            }
            // res < 0, a > 0
            if(res < 0 && a > 0) {
                if(-res > -(INT_MIN_VALUE / a)) {
                    return -2;
                }
            }
        }
        res = res * a;
    }
    return 0;

	}
}

inline int factorial(const int a, int &res)
{
    if (a < 0) return -1;
    if (a == 0 || a == 1) {
        res = 1;
        return 0;
    }

    // предыдущее значение
    if (factorial(a - 1, res) != 0) return -1;

    // Проверка на переполнение
    if (res > INT_MAX_VALUE / a) return -2;

    res = res*a;
    return 0;
}

}    
