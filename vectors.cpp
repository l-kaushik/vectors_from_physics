#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
    float i, j, k;

public:
    Vector(float x = false, float y = false, float z = false):i(x),j(y),k(z){}

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

   static Vector from_magnitude(float mag, float angle_xy, float angle_xz = false)
    {
        float x, y, z;

        x = (mag * cos(angle_xy * (M_PI / 180.0)));
        y = (mag * sin(angle_xy * (M_PI / 180.0)));

        if(angle_xz != false)
            z = (mag * cos(angle_xz * (M_PI / 180.0)));
        else z = 0;

        return Vector(round(x * 100.0)/100.0, round(y * 100.0)/100.0, round(z * 100.0)/100.0);
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
    a = Vector::from_magnitude(3,50,34.2);
    a.display();
    return 0;
}