#ifndef Q1_H
#define Q1_H
#include <cmath>
#include <functional>
#include <iostream>

namespace q1 {
template <typename T, typename Comp>
T gradient_descent(T a, T b, Comp comp)
{
    // std::cout << comp((1 / 2)) << std::endl;
    T current_pnt { a };
    T return_pnt { comp(current_pnt) };
    std::less<> less;
    // std::cout << less(1, 2) << std::endl;
    if (less(comp(current_pnt + b), comp(current_pnt)) == 1) {
        while (less(comp(current_pnt + b), comp(current_pnt))) {
            // std::cout << return_pnt << "    " << comp(current_pnt + b) << "    " << comp(current_pnt) << "   " << less(comp(current_pnt + b), comp(current_pnt)) << std::endl;

            return_pnt = comp(current_pnt + b);
            current_pnt = current_pnt + b;
        }
    } else {
        while (less(comp(current_pnt - b), comp(current_pnt))) {
            // std::cout << return_pnt << "    " << comp(current_pnt + b) << "    " << comp(current_pnt) << "   " << less(comp(current_pnt + b), comp(current_pnt)) << std::endl;

            return_pnt = comp(current_pnt - b);
            current_pnt = current_pnt - b;
        }
    }

    std::cout << current_pnt << std::endl;
    return current_pnt;
};
}

#endif // Q1_H