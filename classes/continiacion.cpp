#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class Shape {
public:
    virtual ~Shape() = default;           // ВАЖЛИВО: віртуальний деструктор
    virtual double area() const = 0;      // чисто віртуальна (абстрактний клас)
    virtual void draw() const { std::cout << "Shape\n"; }
};

class Circle final : public Shape {       // final — забороняє подальше наслідування
    double r_;
public:
    explicit Circle(double r) : r_(r) {}
    double area() const override { return M_PI * r_ * r_; }
    void draw() const override { std::cout << "Circle r=" << r_ << "\n"; }
};

class Rect : public Shape {
    double w_, h_;
public:
    Rect(double w, double h) : w_(w), h_(h) {}
    double area() const override { return w_ * h_; }
    void draw() const override { std::cout << "Rect " << w_ << "x" << h_ << "\n"; }
};

int main() {
    std::vector<std::unique_ptr<Shape>> figs;
    figs.push_back(std::make_unique<Circle>(2.0));
    figs.push_back(std::make_unique<Rect>(3.0, 5.0));

    double total = 0;
    for (const auto& s : figs) {
        s->draw();                 // поліморфний виклик
        total += s->area();        // викликається реалізація відповідного класу
    }
    std::cout << "Total area = " << total << "\n";
}