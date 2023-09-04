#include <iostream>
#include <math.h>
using namespace std;

class Vector {
    float i, j, k;

public:
    // Constructor with default values (0.0) for x, y, and z components
    Vector(float x = 0.0, float y = 0.0, float z = 0.0) : i(x), j(y), k(z) {}

    // Display the vector components
    void display() {
        cout << i << "i, " << j << "j, " << k << "k" << endl;
    }

    // Calculate the magnitude of the vector
    float magnitude() {
        return sqrt(pow(i, 2) + pow(j, 2) + pow(k, 2));
    }

    // Calculate the dot product with another vector
    float dot_product(const Vector other) {
        return i * other.i + j * other.j + k * other.k;
    }

    // Create a vector from magnitude and angles (in degrees)
    static Vector from_magnitude(float mag, float angle_xy, float angle_xz = 0.0) {
        float x, y, z;

        x = mag * cos(angle_xy * (M_PI / 180.0));
        y = mag * sin(angle_xy * (M_PI / 180.0));

        if (angle_xz != 0.0)
            z = mag * cos(angle_xz * (M_PI / 180.0));
        else
            z = 0;

        return Vector(round(x * 100.0) / 100.0, round(y * 100.0) / 100.0, round(z * 100.0) / 100.0);
    }

    // Calculate the angle between two vectors (in degrees)
    static float angle_between(Vector vec1, Vector vec2) {
        float vector_product = vec1.dot_product(vec2);
        float magnitude_product = vec1.magnitude() * vec2.magnitude();
        float angle_in_degree = (acos(vector_product / magnitude_product) * 180.0 / M_PI);

        return round(angle_in_degree * 100.0) / 100.0;
    }

    // Check if two vectors are negative of each other
    static bool is_negative(Vector vec1, const Vector vec2) {
        if (vec1.to_negative() == vec2)
            return true;
        return false;
    }

    // Check if two vectors are equal
    static bool is_equal(const Vector vec1, const Vector vec2) {
        if (vec1 == vec2)
            return true;
        return false;
    }

    // Calculate the cross product with another vector
    Vector cross_product(Vector other) {
        float new_i = j * other.k - k * other.j;
        float new_j = k * other.i - i * other.k;
        float new_k = i * other.j - j * other.i;

        return Vector(new_i, new_j, new_k);
    }

    // Return the negative of the current vector
    Vector to_negative() {
        return Vector(i * -1, j * -1, k * -1);
    }

    // Operator definitions

    // Check if two vectors are equal
    bool operator==(const Vector &other) const {
        return (i == other.i) && (j == other.j) && (k == other.k);
    }

    // Add two vectors
    Vector operator+(const Vector &other) const {
        return Vector(i + other.i, j + other.j, k + other.k);
    }

    // Subtract two vectors
    Vector operator-(const Vector &other) const {
        return Vector(i - other.i, j - other.j, k - other.k);
    }

    // Multiply a vector by a scalar
    Vector operator*(const float &other) const {
        return Vector(i * other, j * other, k * other);
    }

    // Output stream operator overload
    friend std::ostream &operator<<(std::ostream &os, const Vector vec) {
        os << vec.i << "i, " << vec.j << "j, " << vec.k << "k";
        return os;
    }

    // Input stream operator overload
    friend std::istream &operator>>(std::istream &is, Vector &vec) {
        cout << "i: ";
        is >> vec.i;
        cout << "j: ";
        is >> vec.j;
        cout << "k: ";
        is >> vec.k;
        return is;
    }
};

int main() {
    Vector a, b;
    cin >> a;
    cout << a + (a * 2);  // Display the result of a + (a * 2)
    return 0;
}
