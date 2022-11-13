//��� ������ �����ε�
#include<iostream>
using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}  //�⺻ ������
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}  //�Ķ���Ͱ� �ִ� ������
	//���� ������ +
	Vector operator+(const Vector v)const   //��� ������ �̿��� �� ���� ������ �ʴ´�. �ڵ��� ������ ���δ�.
	{
		return Vector{this->x + v.x, this->y + v.y, this->z + v.z }; //this = v0, Vector = �ӽð�ü
	}
	//���� ������ -
	Vector operator-() {
		return Vector{ -x,-y,-z };
	}

	//���׿����� * (���� ���ϱ�)
	float operator*(const Vector &v)const {
		float dot = (x * v.x) + (y * v.y) + (z * v.z);
		return dot;
	}
	//���׿����� * (��� ���ϱ�)
	Vector operator*(const float n)const {
		return Vector{ x * n, y * n,z * n };
	}
	//���� ���� ������
	Vector& operator++() {
		++x;
		++y;
		++z;
		return *this;
	}
	//���� ����������
	Vector& operator++(int) // int = �ǹ̾��� �ڷ���, �����Ϸ����� �������������� �˷���
	{
		Vector temp = *this;
		++x;
		++y;
		++z;
		return temp;
	}

	//���׿����� +
	Vector operator+() const{
		return Vector{ +x,+y,+z };
	}
	//���׿����� -
	Vector operator-(const Vector v) const{
		return Vector{ x - v.x, y - v.y, z - v.z };
	}
	
	//���׿����� /
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

	Vector v2 = v0 + v1; //���׿����� +, v0.operator+(v1), Vector v2 = v0.operator+(v1) 
	v2.print();

	Vector v3 = -v1; //���׿�����-, v1.operator-()
	v3.print();

	//���׿����� *
	//���Ϳ���, ������� -> (v0.x * v1.x) + (v0,y * v1.y) = float
	//���� * �Ǽ��� -> ����
	float v4 = v0 * v1; // v0.operator*(v1)
	cout << v4 << endl;
	
	Vector v5 = v1 * 3.0f; // v1.operator*(3.0f)
	v5.print();

	//���� ���� ������ ++v1
	Vector v6 = ++v1; //v1.operator++()
	v6.print();
	//���� ���� ������ v1++
	Vector v7 = v1++;
	v7.print();
	v1.print();

	//���׿����� +
	Vector v8 = +v1;
	v8.print();

	//���׿����� -
	Vector v9 = v1 - v0;
	v9.print();

	//���׿����� /
	Vector v10 = v1 / 3.0f;
	v10.print();
}