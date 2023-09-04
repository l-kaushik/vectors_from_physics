#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
    float i, j, k;

public:
    
    Vector() : i(0), j(0), k(0) {}

    Vector(float x, float y, float z):i(x), j(y), k(z) {}

    void display()
    {
        cout << i << "i"
             << ", " << j << "j"
             << ", " << k << "k" << endl;
    }

    float magnitude()
    {
        return sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));
    }

    float dot_product(Vector other)
    {
        return i * other.i + j * other.j + k * other.k;
    }

    Vector cross_product(Vector other)
    {
        float new_i = j * other.k - k * other.j;
        float new_j = k * other.i - i * other.k;
        float new_k = i * other.j - j * other.i;

        return Vector(new_i, new_j, new_k);
    }

    Vector to_negative()
    {
        return Vector(i * -1, j * -1, k * -1);
    }
};

int main()
{
    Vector a;
    a = Vector(3, 5, -6);
    a.to_negative().display();
    return 0;
}