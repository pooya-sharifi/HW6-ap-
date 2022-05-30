#ifndef Q3_H
#define Q3_H
namespace q3 {
struct Flight {
    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};

}
#endif // Q3_H