#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Animal {
protected:
    std::string name;                 // спільний стан
public:
    explicit Animal(std::string n) : name(std::move(n)) {}
    virtual ~Animal() = default;      // важливо для коректного видалення через базовий вказівник

    void info() const {               // звичайний (невіртуальний) метод
        std::cout << "I am " << name << "\n";
    }

    virtual void speak() const = 0;   // чисто віртуальний — робить клас абстрактним
};

class Dog : public Animal {           // публічне наслідування
public:
    explicit Dog(std::string n) : Animal(std::move(n)) {}
    void speak() const override {
        std::cout << "Woof! 🐶\n";
    }
};

class Cat : public Animal {
public:
    explicit Cat(std::string n) : Animal(std::move(n)) {}
    void speak() const override {
        std::cout << "Meow! 🐱\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.emplace_back(std::make_unique<Dog>("Brovko"));
    zoo.emplace_back(std::make_unique<Cat>("Murka"));

    for (const auto& a : zoo) {
        a->info();   // виклик методу базового класу
        a->speak();  // поліморфний виклик (у кожного своя реалізація)
    }
}