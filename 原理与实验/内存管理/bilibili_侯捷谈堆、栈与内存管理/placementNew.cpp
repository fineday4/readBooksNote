//#include "gtest/gtest.h"
#include <iostream>

using namespace std;

class Foo {
public:
    int _id;
    long _data;
    string _str;

public:
    Foo():_id(0) {
        cout << "default ctor.this = " << hex << this << " id = " << _id << endl;
    }

    Foo(int id):_id(id)  {
        cout << "ctor.this = " << hex << this << " id = " << _id << endl;
    }

    ~Foo() {
        cout << "dtor.this = " << hex << this << " id = " << _id << endl;
    }

public:
    void* operator new(size_t size) {
        return malloc(size);
    }

    void* operator new(size_t size, void* start) {
        return start;
    }

    void* operator new(size_t size, long extra) {
        return malloc(size + extra); 
    }

    void* operator new(size_t size, long extra, char init) {
        return malloc(size + extra);
    }

    void operator delete(void* p) {
    }

    void operator delete(void* p, void* start) {
    }

    void operator delete(void* p, long extra) {
    }

    void operator delete(void *p, long extra, char init) {
    }
};

 int main()
 {
    cout << "8 + 3*sizeof(Foo) " << hex << 8 + 3*sizeof(Foo) << endl;
    cout << "sizeof(Foo) " << hex << sizeof(Foo) << endl;
    Foo* pNewAr = ::new Foo[3];
    cout << "NewOpDeleOp" << endl;
    ::delete[] pNewAr;
    Foo* pNew = ::new Foo();
    Foo* pNew1 = ::new Foo(1);
    cout << "NewOpDeleOp" << endl;
    ::delete pNew;
    ::delete pNew1;
    return 0;
 }
