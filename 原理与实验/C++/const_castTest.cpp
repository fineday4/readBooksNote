#include <iostream>

using namespace std;

void printTest(const char* buf)
{
    cout << buf << endl;
    char* tmpBuf = const_cast<char*>(buf);
    tmpBuf[0] = 'T'; 
    cout << buf << endl;
}

int main(int argc, char* argv[])
{
    if(1  == argc) {
        const char buf[] = "XHH test";
        printTest(buf);
    } else {
        const char *buf = "XHH test";
        printTest(buf);
    }
    return 0;
}
