#include "Vector3.h"
#include <cmath>

//�R���X�g���N�^
Vector3::Vector3()
	:Vector3(0, 0, 0)
{
}

// �l��p���Ă̏�����
Vector3::Vector3(float x, float y, float z)
	: DirectX::XMFLOAT3{ x,y,z }
{
}

// �x�N�g���̑傫��
float Vector3::length() const {
	return float(sqrt(x * x + y * y + z * z));
}

// �x�N�g���̐��K��
Vector3& Vector3::normalize() {
	float len = length();
	if (len != 0)
	{
		*this /= len;
	}
	return *this;
}

// �x�N�g���̓���
float Vector3::dot(const Vector3& v) const {
	return x * v.x + y * v.y + z * v.z;
}

//�x�N�g���̊O��
Vector3 Vector3::cross(const Vector3& v) const {
	Vector3 temp;
	temp.x = this->y * v.z - this->z * v.y;
	temp.y = this->z * v.x - this->x * v.z;
	temp.z = this->x * v.y - this->y * v.x;
	return temp;
}

float Vector3::angle(const Vector3& v) const
{
	//�@���x�N�g���̒�����0���Ɠ������o�܂���̂Œ��ӂ��Ă��������B

	//�x�N�g��A��B�̒������v�Z����
	float length_A = powf((this->x * this->x) + (this->y * this->y) + (this->z * this->z), 0.5);
	float length_B = powf((v.x * v.x) + (v.y * v.y) + (v.z * v.z), 0.5);

	//���ςƃx�N�g���������g����cos�Ƃ����߂�
	float cos_sita = this->dot(v) / (length_A * length_B);

	//cos�Ƃ���Ƃ����߂�
	float radian = acos(cos_sita);

	return DirectX::XMConvertToDegrees(radian);
}

Vector3 Vector3::DirectXVector3Transform(const DirectX::XMMATRIX& v) const
{
	DirectX::XMVECTOR XMv = { this->x,this->y,this->z };
	DirectX::XMVECTOR transv = DirectX::XMVector3Transform(XMv, v);

	return Vector3(transv.m128_f32[0], transv.m128_f32[1], transv.m128_f32[2]);
}

//�P�����Z�q+�̒ǉ�
Vector3 Vector3::operator+() const {
	return *this;
}

//�P�����Z�q+�̒ǉ�
Vector3 Vector3::operator-() const {
	return Vector3(-x, -y, -z);
}

//+=�̒ǉ�
Vector3& Vector3:: operator+=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

//-=�̒ǉ�
Vector3& Vector3::operator-=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

//*=�̒ǉ�
Vector3& Vector3::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

// /=�̒ǉ�
Vector3& Vector3::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

// �x�N�g���̉��Z
const Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	Vector3 temp(v1);
	return temp += v2;
}

// �x�N�g���̌��Z
const Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	Vector3 temp(v1);
	return temp -= v2;
}

const Vector3 operator*(const Vector3& v, float s) {
	Vector3 temp(v);
	return temp *= s;
}

//�x�N�g���̏�Z
const Vector3 operator*(float s, const Vector3& v) {
	return v * s;
}

// �x�N�g���̏��Z
const Vector3 operator/(const Vector3& v, float s) {
	Vector3 temp(v);
	return temp /= s;
}

//���`���
const Vector3 lerp(const Vector3& start, const Vector3& end, const float time) {
	return start * (1.0f - time) + end * time;
}

const Vector3 easeIn(const Vector3& start, const Vector3& end, const float time) {
	float t = time * time;
	return start * (1.0f - t) + end * t;
}

const Vector3 easeOut(const Vector3& start, const Vector3& end, const float time) {
	float t = time * (2 - time);
	return start * (1.0f - t) + end * t;
}

const Vector3 easeInOut(const Vector3& start, const Vector3& end, const float time) {
	float t = time * time * (3 - (2 * time));
	return start * (1.0f - t) + end * t;
}
