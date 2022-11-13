//입출력 연산자 오버로딩
#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	friend ostream& operator<<(ostream& os, Vector& v);

	friend istream& operator>>(istream& is, Vector& v) {
		is >> v.x >> v.y >> v.z;
		return is;
	}
};
ostream& operator<<(ostream& os, Vector& v) {
	os << v.x << " " << v.y << " " << v.z;
	return os;
}
int main() {
	Vector v0{ 1,2,3 };
	cout << v0 << endl; //cout.operator<<(v) -> 안됨. cout은 어딘가 정의되어있음, operator<<(cout,v), 벡터 자체 출력
	//operator<<(cout,v)<void라 반환값 없음 따라서 오류><<endl; ->endl,cout 멤버함수 cout.endl

	Vector v1;
	cin >> v1;
	cout << v1 << endl;
}