#ifndef Q3_H
#define Q3_H
#include <queue>
namespace q3 {
struct Flight {
    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};
inline std::priority_queue<Flight> gather_flights(std::string filename)
{
    std::priority_queue<Flight> khers;
    auto a = khers;
    // std::vector<Patient> pat_vec;
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string txt = buffer.str();
    // 1- flight_number:QR492 - duration:11h30m - connections:3 - connection_times:2h,1h30m,4h15m - price:250
    //\d- \w+:\w+ - \w+:\w+
    std::regex pattern(R"(\d- \w+:(\w+) - \w+:(\w+) - \w+:(\w+) - \w+:((\w+)||((\w+,)*\w+)) - \w+:(\w+))");
    std::smatch match;
    while (std::regex_search(txt, match, pattern)) {
        std::cout << match[0] << std::endl;
        std::cout << match[1] << std::endl;
        txt = match.suffix().str();
    }
    return khers;
}
}
#endif // Q3_H