#ifndef Q2_H
#define Q2_H
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
        std::cout << match[0] << std::endl;
        Patient x;
        x.name = (static_cast<std::string>(match[1]) + " " + static_cast<std::string>(match[2]));
        std::cout << x.name << std::endl;
        std::cout << match[3] << std::endl;

        x.age = std::stoi(static_cast<std::string>(match[3]));
        x.smokes = std::stoi(match[4]);
        x.area_q = std::stoi(match[5]);
        x.alkhol = std::stoi(match[6]);

        pat_vec.push_back(x);
        txt = match.suffix().str();
    }
    std::cout << pat_vec[0].name << std::endl;
    std::cout << pat_vec[20].name << std::endl;
    std::cout << pat_vec[58].name << std::endl;

    // std::cout<< txt << std::endl;
    return pat_vec;
};
}
#endif // Q2_H