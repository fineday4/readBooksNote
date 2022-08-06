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
    static void* operator new(size_t size);
    static void operator delete(void* phead, size_t size);
    static void* operator new[](size_t size);
    static void operator delete[](void* phead, size_t size);
};

void* Foo::operator new(size_t size) {
    Foo* p = (Foo*)malloc(size);
    cout << "XHH test operator new size " << size << " p = " << hex << p << endl;
    return p;
}

void Foo::operator delete(void* phead, size_t size) {
    free(phead);
    cout << "XHH test operator delete size " << size << " phead = " << hex << phead << endl;
}

void* Foo::operator new[](size_t size) {
    Foo* p = (Foo*)malloc(size);
    cout << "XHH test operator new[] size " << size << " p = " << hex << p << endl;
    return p;
}

void Foo::operator delete[](void* phead, size_t size) {
    free(phead);
    cout << "XHH test operator delete[] size " << size << " phead = " << hex << phead << endl;
}

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
