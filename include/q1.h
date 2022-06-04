#ifndef Q1_H
#define Q1_H
#include <cmath>
#include <functional>
#include <iostream>

namespace q1 {
template <typename T, typename Func>
T gradient_descent(T a, T b, Func func)
{
    T current_pnt { a };
    T return_pnt { func(current_pnt) };
    std::less<> less;
    if (less(func(current_pnt + b), func(current_pnt)) == 1) {
        while (less(func(current_pnt + b), func(current_pnt))) {
            return_pnt = func(current_pnt + b);
            current_pnt = current_pnt + b;
        }
    } else {
        while (less(func(current_pnt - b), func(current_pnt))) {
            return_pnt = func(current_pnt - b);
            current_pnt = current_pnt - b;
        }
    }

    std::cout << current_pnt << std::endl;
    return current_pnt;
};

template <typename T, typename Func>
T gradient_descent(T a, T b)
{
    Func s;
    T current_pnt { a };
    T return_pnt { s(current_pnt) };
    std::less<> less;
    if (less(s(current_pnt + b), s(current_pnt)) == 1) {
        while (less(s(current_pnt + b), s(current_pnt))) {
            return_pnt = s(current_pnt + b);
            current_pnt = current_pnt + b;
        }
    } else {
        while (less(s(current_pnt - b), s(current_pnt))) {
            return_pnt = s(current_pnt - b);
            current_pnt = current_pnt - b;
        }
    }

    std::cout << current_pnt << std::endl;
    return current_pnt;
};
}

#endif // Q1_H