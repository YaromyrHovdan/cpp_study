#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Driver {
    protected:
    string name;
    public:
    explicit Driver(string n) : name(std::move(n)) {}
    virtual ~Driver() = default;
    
    void nam() const {               
        std::cout << "I am " << name << "\n";
    }
    
    virtual void info() const = 0;
};    
    class Ham : public Driver {           // публічне наслідування
    public:
    explicit Ham(std::string n) : Driver(std::move(n)) {}
    void info() const override {
        std::cout << "I born 7 January 1985. Competing in Formula One for Ferrari.\n";
    }
};    
    class Lec : public Driver {           // публічне наслідування
    public:
    explicit Lec(std::string n) : Driver(std::move(n)) {}
    void info() const override {
        std::cout << "I born 16 October 1997. Competing in Formula One for Ferrari.\n";
    }
};    
    class Pia : public Driver {           // публічне наслідування
    public:
    explicit Pia(std::string n) : Driver(std::move(n)) {}
    void info() const override {
        std::cout << "I born 6 April 2001. Competing in Formula One for McLaren.\n";
    }
};    
     class Nor : public Driver {           // публічне наслідування
    public:
    explicit Nor(std::string n) : Driver(std::move(n)) {}
    void info() const override {
        std::cout << "I born 13 November 1999. Competing in Formula One for McLaren.\n";
    }
    
};

int main(){
    vector<unique_ptr<Driver>> grid;
    grid.emplace_back(make_unique<Ham>("Sir Lewis Carl Davidson Hamilton"));
    grid.emplace_back(make_unique<Lec>("Charles Marc Hervé Perceval Leclerc"));
    grid.emplace_back(make_unique<Pia>("Oscar Jack Piastri"));
    grid.emplace_back(make_unique<Nor>("Lando Norris"));

    for (const auto& d : grid) {
        d->nam();   // виклик методу базового класу
        d->info();  // поліморфний виклик (у кожного своя реалізація)
    }
    
    }
