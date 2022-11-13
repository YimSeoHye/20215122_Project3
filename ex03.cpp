//����� ������ �����ε�
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
	cout << v0 << endl; //cout.operator<<(v) -> �ȵ�. cout�� ��� ���ǵǾ�����, operator<<(cout,v), ���� ��ü ���
	//operator<<(cout,v)<void�� ��ȯ�� ���� ���� ����><<endl; ->endl,cout ����Լ� cout.endl

	Vector v1;
	cin >> v1;
	cout << v1 << endl;
}