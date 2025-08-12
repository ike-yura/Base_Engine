#pragma once
#include <DirectXMath.h>

class Vector3 : public DirectX::XMFLOAT3
{
public:
	Vector3();
	Vector3(float x, float y, float z);

	float length() const;
	Vector3& normalize();
	float dot(const Vector3& v) const;
	Vector3 cross(const Vector3& v) const;
	float angle(const Vector3& v) const;

	//XMVECTOR�n�̕ϊ��֐�
	Vector3 DirectXVector3Transform(const DirectX::XMMATRIX& v) const;

	//�P�����Z�q�I�[�o�[���[�h
	Vector3 operator+() const;
	Vector3 operator-() const;

	//������Z�q�I�[�o�[���[�h
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(float s);
	Vector3& operator/=(float s);
};

//�񍀉��Z�q�I�[�o�[���[�h
const Vector3 operator+(const Vector3& v1, const Vector3& v2);
const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);
const Vector3 operator/(const Vector3& v, float s);

//���`���
const Vector3 lerp(const Vector3& start, const Vector3& end, const float time);
const Vector3 easeIn(const Vector3& start, const Vector3& end, const float time);
const Vector3 easeOut(const Vector3& start, const Vector3& end, const float time);
const Vector3 easeInOut(const Vector3& start, const Vector3& end, const float time);
