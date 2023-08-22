#include <iostream>

using namespace std;

class Vector
{
    int x, y, z;

    public:
        // Vector(){}
        Vector(int, int,int);
        void display();

};

Vector :: Vector(int i = 0, int j = 0, int k = 0){
    x = i;
    y = j;
    z = k;
}

void Vector :: display(){
    cout<<x<<"i"<<", "<<y<<"j"<<", "<<z<<"k"<<endl;
}


int main()
{
    Vector a;
    a = Vector(3,5,6);
    a.display();
    return 0;
}