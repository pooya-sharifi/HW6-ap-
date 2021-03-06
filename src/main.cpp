#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {

        // debug section
        auto flights = q3::gather_flights("flights.txt");
        std::cout << flights.top().flight_number << std::endl;

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}