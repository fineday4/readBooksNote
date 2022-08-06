#include<iostream>

using namespace std;

class A
{
public:
    int id;
    A():id(0){cout << "ctor.this = " << this << "id = " << id << endl; }
    A(int i):id(i){cout << "ctor.this = " << this << " id = " << id << endl; }
    ~A(){ cout << "dtor.this= " << this << endl;}
};

int main()
{
    A* pA = new A(1);
    delete pA;
    A* buf = new A[3];
    A* tmp = buf;
    for(int i = 0; i < 3; ++i) {
        new(tmp++)A(i);
    }
    delete[] buf;
}
