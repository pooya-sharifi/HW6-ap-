#ifndef Q4_H
#define Q4_H
// accumilate
#include <numeric>
#include <vector>
namespace q4 {
struct Vector2D {
    double x {};
    double y {};
};

struct Sensor {
    Vector2D pos;
    double accuracy;
};

inline Vector2D kalman_filter(std::vector<Sensor> sensors)
{

    auto lambda_x = [&](double a, Sensor b) { return (a + b.pos.x * b.accuracy); };
    auto lambda_y = [&](double a, Sensor b) { return a + b.pos.y * b.accuracy; };

    auto accuracy = std::accumulate(sensors.begin(), sensors.end(), 0.0, [](double a, Sensor b) { return a + b.accuracy; });
    auto x_new = std::accumulate(sensors.begin(), sensors.end(), 0.0, lambda_x);
    auto y_new = std::accumulate(sensors.begin(), sensors.end(), 0.0, lambda_y);
    Vector2D return_vec;

    x_new = x_new / accuracy;
    return_vec.x = x_new;
    y_new = y_new / accuracy;
    return_vec.y = y_new;
    return return_vec;
}

}

#endif // Q4_H