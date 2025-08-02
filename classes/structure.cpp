// Треба компілювати з C++20: наприклад g++ -std=c++20 point.cpp -o point
#include <iostream>
#include <iomanip>
#include <cmath>

struct Point {
    double x = 0;
    double y = 0;

    bool is_origin() const { return x == 0.0 && y == 0.0; }

    double distance_to(const Point& o) const {
        return std::hypot(x - o.x, y - o.y);
    }

    // Автоматичне порівняння (C++20)
    bool operator==(const Point& o) const = default;
    bool operator!=(const Point& o) const = default;
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

int main() {
    std::cout << std::fixed << std::setprecision(4) << std::boolalpha;

    Point p1; // за замовчуванням (0,0)
    Point p2{1.5, -2.0};
    Point p3 = {.x = 1.5, .y = -2.0}; // designated initializer (C++20)

    std::cout << "p1 = " << p1 << ", is origin? " << p1.is_origin() << '\n';
    std::cout << "p2 = " << p2 << ", is origin? " << p2.is_origin() << '\n';

    std::cout << "p2 == p3: " << (p2 == p3) << '\n';
    std::cout << "Distance p1->p2: " << p1.distance_to(p2) << '\n';

    auto [x, y] = p2; // структурне розпакування
    std::cout << "Structured binding of p2: x=" << x << ", y=" << y << '\n';

    Point input{};
    std::cout << "Enter coordinates (x y): ";
    if (std::cin >> input.x >> input.y) {
        std::cout << "You entered " << input
                  << ", distance to origin: " << input.distance_to(p1)
                  << ", is origin? " << input.is_origin() << '\n';
    } else {
        std::cerr << "Invalid input\n";
    }

    return 0;
}