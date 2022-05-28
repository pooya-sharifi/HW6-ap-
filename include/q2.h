#ifndef Q2_H
#define Q2_H
#include <fstream>
#include <sstream>
namespace q2 {

struct Patient {
public:
    friend std::vector<Patient> read_file(std::string filename)
    {
        std::ifstream file("lung_cancer.cvs");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();
    }

private:
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};
}
#endif // Q2_H