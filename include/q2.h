#ifndef Q2_H
#define Q2_H
#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>
namespace q2 {

struct Patient {
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};
inline std::vector<Patient> read_file(std::string filename)
{
    std::vector<Patient> pat_vec;
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string txt = buffer.str();
    // pattern
    std::regex pattern(R"((\w+) ?,(\w+) ?,(\d+),(\d+),(\d+),(\d+))");
    std::smatch match;

    // std::regex_search(txt, match, pattern)
    while (std::regex_search(txt, match, pattern)) {
        Patient x;
        x.name = (static_cast<std::string>(match[1]) + " " + static_cast<std::string>(match[2]));

        x.age = std::stoi(static_cast<std::string>(match[3]));
        x.smokes = std::stoi(match[4]);
        x.area_q = std::stoi(match[5]);
        x.alkhol = std::stoi(match[6]);

        pat_vec.push_back(x);
        txt = match.suffix().str();
    }

    // std::cout<< txt << std::endl;
    return pat_vec;
};

inline void sort(std::vector<Patient>& vec_p)
{
    auto lambda = [](Patient patient, Patient patient_2) { return (((3 * (patient.age)) + (5 * (patient.smokes)) + (2 * (patient.area_q)) + (4 * (patient.alkhol))) > ((3 * (patient_2.age)) + (5 * (patient_2.smokes)) + (2 * (patient_2.area_q)) + (4 * (patient_2.alkhol)))); };
    // std::cout << lambda(vec_p[0]) << std::endl;
    std::sort(vec_p.begin(), vec_p.end(), lambda);
}

}
#endif // Q2_H