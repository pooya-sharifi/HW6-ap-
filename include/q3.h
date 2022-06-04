#ifndef Q3_H
#define Q3_H
#include <queue>
#include <vector>
namespace q3 {
struct Flight {
    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};
struct comp {
    bool operator()(Flight a, Flight b)
    {
        return (a.duration + a.connection_times + (3 * a.price)) > (b.duration + b.connection_times + (3 * b.price));
    }
};
inline std::priority_queue<Flight, std::vector<Flight>, comp> gather_flights(std::string filename)
{
    std::priority_queue<Flight, std::vector<Flight>, comp> khers;

    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string txt = buffer.str();
    // std::regex pattern(R"(\d- \w+:(\w+) - \w+:(\w+) - \w+:(\w+) - \w+:((\w+)||((\w+,)*(\w+))) - \w+:(\w+))");
    // 1- flight_number:QR492 - duration:11h30m - connections:3 - connection_times:2h,1h30m,4h15m - price:250
    // std::regex pattern(R"(\d- \w+:(\w+) - \w+:(\w+) - \w+:(\w+) - \w+:(?:(\d+)h(\d+)?m?,?)+ - \w+:(\w+))");
    std::regex pattern(R"(\d- \w+:(\w+) - \w+:(\d+)?h?(\d+)?m? - \w+:(\w+) - \w+:(\d+)h(\d+)?m?,?(\d+)?h?(\d+)?m?,?(\d+)?h?(\d+)?m?,? - \w+:(\w+))");

    std::smatch match;
    while (std::regex_search(txt, match, pattern)) {
        Flight fl;
        fl.flight_number = match[1];
        fl.duration = stoi(match[2]) * 60;
        if (match[3] != "") {
            fl.duration = fl.duration + stoi(match[3]);
            std::cout << fl.duration << std::endl;
        }
        fl.connections = stoi(match[4]);
        size_t size = match.size();

        fl.connection_times = (stoi(match[5]) * 60);
        if (match[6] != "") {
            fl.connection_times = fl.connection_times + stoi(match[6]);
        }

        if (match[7] != "")
            fl.connection_times = fl.connection_times + stoi(match[7]) * 60;

        if (match[8] != "")
            fl.connection_times = fl.connection_times + stoi(match[8]);

        if (match[9] != "")
            fl.connection_times = fl.connection_times + stoi(match[9]) * 60;

        if (match[10] != "")
            fl.connection_times = fl.connection_times + stoi(match[10]);

        fl.price = stoi(match[11]);
        khers.push(fl);
        txt = match.suffix().str();
    }

    return khers;
}
}
#endif // Q3_H