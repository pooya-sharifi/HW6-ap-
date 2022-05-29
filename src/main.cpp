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
        std::vector<q2::Patient> patients = q2::read_file("lung_cancer.csv");

        // std::cout << patients[0].name << std::endl;
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