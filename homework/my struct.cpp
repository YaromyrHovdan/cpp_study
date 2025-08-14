#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Tochka {
    double x = 0;
    double y = 0;
    
    bool origin() const {return x == 0.0 && y == 0.0;}
    
    double distance(const Tochka& o) const {
        return hypot( x - o.x, y - o.y);
    }
    
    bool operator==(const Tochka& o) const = default;
    bool operator!=(const Tochka& o) const = default;
};

ostream& operator<<(ostream& os, const Tochka& p ){
    os << '(' << p.x << ", " << p.y << ')';
    return os;
    }
    
int main(){
    cout << fixed << setprecision(4) << boolalpha;
    
    Tochka p1;
    Tochka p2{1.5, -2.0};
    Tochka p3 = {.x = 1.5, .y = -2.0};
    
    cout << "p1 = " << p1 << ", is origin? " << p1.origin() << '\n';
    cout << "p2 = " << p2 << ", is origin? " << p2.origin() << '\n';
    
    cout << "p2 == p3" << (p2 == p3) << '\n';
    cout << "Distance p1->p2: " << p1.distance(p2) << '\n';
    
    auto[x, y] = p2;
    cout << "Structured binding of p2: x=" << x << ", y=" << y << '\n';
    
    Tochka input{};
    cout << "enter coordinates x y: ";
    if(cin >> input.x >> input.y){
        cout << "You entered " << input
                  << ", distance to origin: " << input.distance(p1)
                  << ", is origin? " << input.origin() << '\n';
    } else {
         cerr << "Invalid input\n";
    }

    return 0;
        
        
    }   
    
