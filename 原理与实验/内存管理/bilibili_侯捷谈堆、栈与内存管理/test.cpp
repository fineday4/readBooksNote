#include <iostream>
#include <string>
#include <cstring>


using namespace std;

//NOTE: os << str, operator<<不可以时成员函数，如果是成员函数的话会出现方向相反的情况。
//即str << os;必须是全局的函数
static ostream& operator<<(ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;
}


class String
{
public:
	String(const char* cstr = 0);
	String(const String& str);//NOTE: 拷贝构造，特点：传参是它自己的类型参数
	//NOTE:要在operator=中检查是否存在自我赋值的情况
	String& operator=(const String& str); //NOTE: 拷贝赋值,特点：传参是它自己的类型参数
	~String();
	char* const get_c_str()
	{
		return m_data;
	}
private:
	char* m_data;
};

inline String::String(const char *cstr = 0) {
	if(cstr) {
		m_data = new char[strlen(cstr) + 1];
		strncpy(m_data, cstr, strlen(cstr));
	} else {
		m_data = new char[1];
		m_data[0] = '\0';
	}
}

inline String::String() {
	delete [] m_data;
}

inline String::String(const String& str) {
	if(m_data == str.m_data) {
		return ;
	}
	m_data = new char[strlen(str.m_data) + 1];
	strncpy(m_data, str.m_data, strlen(str.m_data));
}

inline String& String::operator=(const String& str) {
	if(this == &str) {
		return *this;
	}
	delete []m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strncpy(m_data, str.m_data, strlen(str.m_data));
	return *this;
}
int main()
{
	String s1("hello "); 
	cout << s1;
	return 0;
}
