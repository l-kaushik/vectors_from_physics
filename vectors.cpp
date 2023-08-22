#include <iostream>

using namespace std;

class Vector
{
    int x, y, z;

    public:
        Vector(){}
        Vector(int, int,int);

};

Vector :: Vector(int i, int j, int k){
    x = i;
    y = j;
    z = k;
}

int main()
{
    return 0;
}