#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
    float i, j, k;

public:
    Vector(float x = false, float y = false, float z = false) : i(x), j(y), k(z) {}

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

        if (angle_xz != false)
            z = (mag * cos(angle_xz * (M_PI / 180.0)));
        else
            z = 0;

        return Vector(round(x * 100.0) / 100.0, round(y * 100.0) / 100.0, round(z * 100.0) / 100.0);
    }

    static float angle_between(Vector vec1, Vector vec2)
    {
        float vector_product = vec1.dot_product(vec2);
        float magnitude_product = vec1.magnitude() * vec2.magnitude();
        float angle_in_degree = (acos(vector_product / magnitude_product) * 180.0 / M_PI);

        return round(angle_in_degree *100.0)/100.0;
    }

    static bool is_negative(Vector vec1, Vector vec2){
        if(vec1.to_negative() == vec2)
            return true;
        return false;
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

    //operator definitions
    bool operator==(const Vector& other) const {
        return (i == other.i) && (j == other.j) && (k == other.k);
    }
};

int main()
{
    Vector a(1,2,3), b(-1,2,-3);
    cout<<Vector::is_negative(a,b);
    return 0;
}