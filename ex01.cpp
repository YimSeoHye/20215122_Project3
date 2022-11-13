//산술 연산자 오버로딩
#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}  //기본 생성자
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}  //파라미터가 있는 생성자
	//이항 연산자 +
	Vector operator+(const Vector v)const   //멤버 변수를 이용할 때 값이 변하지 않는다. 코딩의 오류를 줄인다.
	{
		return Vector{this->x + v.x, this->y + v.y, this->z + v.z }; //this = v0, Vector = 임시객체
	}
	//단항 연산자 -
	Vector operator-() {
		return Vector{ -x,-y,-z };
	}

	//이항연산자 * (내적 곱하기)
	float operator*(const Vector &v)const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}
	//이항연산자 * (상수 곱하기)
	Vector operator*(const float n)const {
		return Vector{ x * n, y * n,z * n };
	}
	//전위 증감 연산자
	Vector& operator++() {
		++x;
		++y;
		++z;
		return *this;
	}
	//후위 증감연산자
	Vector& operator++(int) // int = 의미없는 자료형, 컴파일러에게 후위연산자임을 알려줌
	{
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}

	//단항연산자 +
	Vector operator+() const{
		return Vector{ +x,+y,+z };
	}
	//이항연산자 -
	Vector operator-(const Vector v) const{
		return Vector{ x - v.x, y - v.y, z - v.z };
	}
	
	//이항연산자 /
	Vector operator/(const float n)const {
		return Vector{ x / n, y / n, z / n };
	}

	void print() {
		cout << x << " " << y << " " << z << " " << endl;
	}
};

int main() {
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1; //이항연산자 +, v0.operator+(v1), Vector v2 = v0.operator+(v1) 
	v2.print();

	Vector v3 = -v1; //단항연산자-, v1.operator-()
	v3.print();

	//이항연산자 *
	//벡터연산, 내적계산 -> (v0.x * v1.x) + (v0,y * v1.y) = float
	//벡터 * 실수값 -> 벡터
	float v4 = v0 * v1; // v0.operator*(v1)
	cout << v4 << endl;
	
	Vector v5 = v1 * 3.0f; // v1.operator*(3.0f)
	v5.print();

	//전위 증감 연산자 ++v1
	Vector v6 = ++v1; //v1.operator++()
	v6.print();
	//후위 증감 연산자 v1++
	Vector v7 = v1++;
	v7.print();
	v1.print();

	//단항연산자 +
	Vector v8 = +v1;
	v8.print();

	//이항연산자 -
	Vector v9 = v1 - v0;
	v9.print();

	//이항연산자 /
	Vector v10 = v1 / 3.0f;
	v10.print();
}