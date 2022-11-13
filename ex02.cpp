//비교&관계 연산자 오버로딩
#include<iostream>
#include<cstring>  ///strcpy, strcmp
using namespace std;

class String
{
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) :_chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String &str) const {
		return strcmp(_chars,str._chars) == 0;
	}

	bool operator>(const String& str)const {
		return strcmp(_chars, str._chars) > 0;
	}
	bool operator<=(const String& str)const {
		//<=의 반대? >, 정의된 > 함수 이용
		return !(*this > str);
	}
	bool operator!=(const String& str)const {
		return !(*this == str);
	}
	bool operator<(const String& str)const {
		return strcmp(_chars, str._chars) < 0;
	}
	bool operator>=(const String& str)const {
		return !(*this < str);
	 }
};

int main() {
	string str0{ "abc" };
	string str1{ "cde" };

	//비교연산자 ==
	if (str0 == str1)  // bool str1.operator==(str1)
		cout << "equal" << endl;
	//>
	if (str0 > str1) //operator>(str1)
		cout << "str0 > str1" << endl;
	//<=
	if (str0 <= str1)
		cout << "str0 <= str1" << endl;
	//!=
	if (str0 != str1)
		cout << "str0 != str1" << endl;
	//<
	if (str0 < str1)
		cout << "str0 < str1" << endl;
	//>=
	if (str0 >= str1)
		cout << "str0 >= str1" << endl;
}
