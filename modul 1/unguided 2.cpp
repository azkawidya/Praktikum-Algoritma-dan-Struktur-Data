// class
#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float calculateArea() {
        return length * width;
    }
};

int main()
{
    Rectangle rect(8, 2);
    std::cout << "Luas persegi panjang: " << rect.calculateArea() << std::endl;
    return 0;
}

// struck
#include <iostream>
using namespace std;

struct Point
{
    float x;
    float y;
};

int main()
{
    Point p;
    p.x = 3.5;
    p.y = 6.0;
    std::cout << "Koordinat titik: (" << p.x << ", " << p.y << ")" << std::endl;
    return 0;
}
