//대입 연산자 오버로딩
#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
	char* _chars;
public:
	Vector() {}
	Vector(float x, float y, float z, const char* chars) 
		:x{ x }, y{ y }, z{ z }, _chars{new char[strlen(chars)+1]} 
	{
		strcpy_s(_chars, strlen(chars)+1,chars);
	}
	//복사 생성자
	Vector(Vector& v)
		:Vector(v.x, v.y, v.z, v._chars)//위임 생성자
	{
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		cout << "copy" << endl;
	}
	~Vector() {
		delete[]_chars;
	}

	Vector &operator=(Vector& v) { //대입 연산은 const 불가능, = 자체가 값을 바꾸는 행위
		x = v.x;
		y = v.y;
		z = v.z;

		delete[]_chars;
		_chars = new char[strlen(v._chars) + 1];
		strcpy_s(_chars, strlen(v._chars) + 1, v._chars);
		return *this;
	}
	friend ostream& operator<<(ostream& os, Vector& v) {
		os << v.x << " " << v.y << " " << v.z ;
		return os;
	}
};

int main() {
	//복사와 대입의 차이
	/**int a = 1;
	int b = a; //복사
	int c;
	c = a; //대입
	*/
	Vector v0{ 1,2,3, "abc"};
	Vector v1 = v0;  //복사 -> 얕은 복사
	Vector v2;
	v2 = v0; //대입, v2.operator = (v0)

	cout << v0 << endl;
	cout << v1 << endl;
	cout << v2 << endl;
}