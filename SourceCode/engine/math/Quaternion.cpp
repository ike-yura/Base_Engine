#include "Quaternion.h"
#include "Matrix4.h"
#include <cmath>
#include <math.h>

//�������w�肵�āA�N�I�[�^�j�I�����쐬
Quaternion quaternion(float x, float y, float z, float w)
{
	Quaternion result{ x, y, z, w };
	return result;
}

//�C�ӎ��܂��̉�]�̎w�肩��N�I�[�^�j�I�����쐬
Quaternion quaternion(const Vector3& v, float angle)
{
	float _sin = sin(angle / 2.0f);
	return quaternion(_sin * v.x, _sin * v.y, _sin * v.z, cos(angle / 2.0f));
}

//�x�N�g��v���N�H�[�^�j�I��q�ŉ�]���A���ʂ��N�H�[�^�j�I���ŕԂ�
Quaternion quaternion(const Vector3& v, const Quaternion& q)
{
	Quaternion qq = conjugate(q);//q�̋����l�������쐬����
	Quaternion qv = quaternion(v.x, v.y, v.z, 0);//�x�N�g��v���N�H�[�^�j�I��������

	return q * qv * qq;
}

//dot �֐��̎���
float dot(const Quaternion& q1, const Quaternion& q2)
{
	return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
}

//length �֐��̎���
float length(const Quaternion& q)
{
	return float(sqrt(dot(q, q)));
}

//normalize �֐��̎���
Quaternion normalize(const Quaternion& q)
{
	Quaternion result = q;
	float len = length(result);
	if (len != 0)
	{
		result /= len;
	}
	return result;
}

Quaternion conjugate(const Quaternion& q)
{
	Quaternion result = { -q.x, -q.y, -q.z, q.w };

	return result;
}

Quaternion LookRotation(const Vector3& v)
{
	Vector3 target = v;
	Vector3 targetN = target.normalize(); //���K��
	Vector3 norm = { 0, 0, 1 }; //�f�t�H���g�̕���
	float dot = target.dot(norm); //����
	float theta = acosf(dot);//�p�x�̎Z�o
	Vector3 cross = target.cross(norm); //�O��

	cross = cross.normalize();
	theta = theta / 2;
	Quaternion q;
	q.x = cross.x * sinf(theta);
	q.y = cross.y * sinf(theta);
	q.z = cross.z * sinf(theta);
	q.w = cosf(theta);

	return q;
}

Vector3 EulerAngles(const Quaternion& q)
{
	Quaternion r = q;
	float x = r.x;
	float y = r.y;
	float z = r.z;
	float w = r.w;

	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float xy = x * y;
	float xz = x * z;
	float yz = y * z;
	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	// 1 - 2y^2 - 2z^2
	float m00 = 1.0f - (2.0f * y2) - (2.0f * z2);

	// 2xy + 2wz
	float m01 = (2.0f * xy) + (2.0f * wz);

	// 2xy - 2wz
	float m10 = (2.0f * xy) - (2.0f * wz);

	// 1 - 2x^2 - 2z^2
	float m11 = 1.0f - (2.0f * x2) - (2.0f * z2);

	// 2xz + 2wy
	float m20 = (2.0f * xz) + (2.0f * wy);

	// 2yz+2wx
	float m21 = (2.0f * yz) - (2.0f * wx);

	// 1 - 2x^2 - 2y^2
	float m22 = 1.0f - (2.0f * x2) - (2.0f * y2);


	Vector3 t = { 0,0,0 };

	const float epsilon = 1.0e-5f;	// �덷�z���p�̔����Ȓl

	if (fabs(m21 - 1.0f) < epsilon)
	{
		t.x = DirectX::XM_PI / 2.0f;
		t.y = 0;
		t.z = atan2(m10, m00);
	}
	else if (fabs(m21 + 1.0f) < epsilon)
	{
		t.x = -DirectX::XM_PI / 2.0f;
		t.y = 0;
		t.z = atan2(m10, m00);
	}
	else
	{
		t.x = asin(-m21);
		t.y = atan2(m20, m22);
		t.z = atan2(m01, m11);
	}

	t.x = DirectX::XMConvertToDegrees(t.x);
	t.y = DirectX::XMConvertToDegrees(t.y);
	t.z = DirectX::XMConvertToDegrees(t.z);

	return t;
}

//�P�����Z�q + �̃I�[�o�[���[�h
//�P�����Z�q + �͓��ɈӖ��������Ȃ�
//( + �N�I�[�^�j�I�� )
Quaternion operator + (const Quaternion& q)
{
	return q;
}

//�P�����Z�q - �̃I�[�o�[���[�h
//( - �N�I�[�^�j�I�� )
Quaternion operator - (const Quaternion& q)
{
	Quaternion result = { -q.x, -q.y, -q.z, -q.w };
	return result;
}

//�P�����Z�q += �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� += �N�I�[�^�j�I�� )
Quaternion& operator += (Quaternion& q1, const Quaternion& q2)
{
	q1.x += q2.x;
	q1.y += q2.y;
	q1.z += q2.z;
	q1.w += q2.w;
	return q1;
}

//�P�����Z�q -= �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� -= �N�I�[�^�j�I�� )
Quaternion& operator -= (Quaternion& q1, const Quaternion& q2)
{
	q1.x -= q2.x;
	q1.y -= q2.y;
	q1.z -= q2.z;
	q1.w -= q2.w;
	return q1;
}

//�P�����Z�q *= �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� *= �N�I�[�^�j�I�� )
Quaternion& operator *= (Quaternion& q1, const Quaternion& q2)
{
	Quaternion result
	{
		 q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x, //x����
		-q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y, //y����
		 q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z, //z����
		-q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w  //w����
	};

	q1 = result;
	return q1;
}

//�P�����Z�q *= �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� *= �X�J���[ )
Quaternion& operator *= (Quaternion& q, float s)
{
	q.x *= s; //x����
	q.y *= s; //y����
	q.z *= s; //z����
	q.w *= s; //w����

	return q;
}

//�P�����Z�q /= �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� /= �X�J���[ )
Quaternion& operator /= (Quaternion& q, float s)
{
	return q *= 1.0f / s;
}

//2�����Z�q + �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� + �N�I�[�^�j�I�� )
Quaternion operator + (const Quaternion& q1, const Quaternion& q2)
{
	Quaternion result = q1;
	return result += q2;
}

//2�����Z�q - �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� - �N�I�[�^�j�I�� )
Quaternion operator - (const Quaternion& q1, const Quaternion& q2)
{
	Quaternion result = q1;
	return result -= q2;
}

//2�����Z�q * �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� * �N�I�[�^�j�I�� )
Quaternion operator * (const Quaternion& q1, const Quaternion& q2)
{
	Quaternion result = q1;
	return result *= q2;
}

//2�����Z�q * �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� * �X�J���[ )
Quaternion operator * (const Quaternion& q, float s)
{
	Quaternion result = q;
	return result *= s;
}

//2�����Z�q * �̃I�[�o�[���[�h
//( �X�J���[ * �N�I�[�^�j�I�� )
Quaternion operator * (float s, const Quaternion& q)
{
	Quaternion result = q;
	return result *= s;
}

//2�����Z�q * �̃I�[�o�[���[�h
//( �N�I�[�^�j�I�� / �X�J���[ )
Quaternion operator / (const Quaternion& q, float s)
{
	Quaternion result = q;
	return result /= s;
}

//�N�I�[�^�j�I�������ʐ��`��Ԃ���֐�
// q1 �� q2 �ŕ�Ԃ��� ( t : 0.0 �` 1.0 )
Quaternion slerp(const Quaternion& q1, const Quaternion& q2, float t)
{
	float cos = dot(q1, q2);
	Quaternion t2 = q2;
	if (cos < 0.0f)
	{
		cos = -cos;
		t2 = -q2;
	}
	float k0 = 1.0f - t;
	float k1 = t;
	if ((1.0f - cos) > 0.001f)
	{
		float thera = float(acos(cos));
		k0 = sinf(thera * k0) / sinf(thera);
		k1 = sinf(thera * k1) / sinf(thera);
	}
	return q1 * k0 + t2 * k1;
}

//�N�I�[�^�j�I������`��Ԃ���֐�
Quaternion lerp(const Quaternion& q1, const Quaternion& q2, float t)
{
	float cos = dot(q1, q2);
	Quaternion t2 = q2;
	if (cos < 0.0f)
	{
		cos = -cos;
		t2 = -q2;
	}
	float k0 = 1.0f - t;
	float k1 = t;
	return q1 * k0 + t2 * k1;
}

//�N�H�[�^�j�I�������]�s��ɕϊ�����֐�
Matrix4 rotate(const Quaternion& q)
{
	float xx = q.x * q.x * 2.0f;
	float yy = q.y * q.y * 2.0f;
	float zz = q.z * q.z * 2.0f;
	float xy = q.x * q.y * 2.0f;
	float xz = q.x * q.z * 2.0f;
	float yz = q.y * q.z * 2.0f;
	float wx = q.w * q.x * 2.0f;
	float wy = q.w * q.y * 2.0f;
	float wz = q.w * q.z * 2.0f;
	DirectX::XMMATRIX result = {
		1.0f - yy - zz, xy + wz,        xz - wy,        0.0f,
		xy - wz,        1.0f - xx - zz, yz + wx,        0.0f,
		xz + wy,        yz - wx,        1.0f - xx - yy, 0.0f,
		0.0f,           0.0f,           0.0f,           1.0f
	};
	return result;
}

//��]�s�񂩂�N�H�[�^�j�I�������߂�֐�
Quaternion quaternion(const Matrix4& m)
{
	Quaternion result;
	float tr = m.r[0].m128_f32[0] + m.r[1].m128_f32[1] + m.r[2].m128_f32[2] + m.r[3].m128_f32[3];

	if (tr >= 1.0f)
	{
		float fourD = 2.0f * sqrt(tr);
		result.x = (m.r[1].m128_f32[2] - m.r[2].m128_f32[1]) / fourD;
		result.y = (m.r[2].m128_f32[0] - m.r[0].m128_f32[2]) / fourD;
		result.z = (m.r[0].m128_f32[1] - m.r[1].m128_f32[0]) / fourD;
		result.w = fourD / 4.0f;
		return result;
	}
	int i = 0;
	if (m.r[0].m128_f32[0] <= m.r[1].m128_f32[1])
	{
		i = 1;
	}
	if (m.r[2].m128_f32[2] > m.r[i].m128_f32[i])
	{
		i = 2;
	}

	int j = (i + 1) % 3;
	int k = (j + 1) % 3;
	tr = m.r[i].m128_f32[i] - m.r[j].m128_f32[j] - m.r[k].m128_f32[k] + 1.0f;
	float fourD = 2.0f * sqrt(tr);
	float qa[4];
	qa[i] = fourD / 4.0f;
	qa[j] = (m.r[j].m128_f32[i] + m.r[i].m128_f32[j]) / fourD;
	qa[k] = (m.r[k].m128_f32[i] + m.r[i].m128_f32[k]) / fourD;
	qa[3] = (m.r[j].m128_f32[k] - m.r[k].m128_f32[j]) / fourD;
	result.x = qa[0];
	result.y = qa[1];
	result.z = qa[2];
	result.w = qa[3];
	return result;
}

//��]���̎Z�o
Vector3 getAxis(const Quaternion& q)
{
	Vector3 result;

	float x = q.x;
	float y = q.y;
	float z = q.z;
	float _len = length(q);

	result.x = x / _len;
	result.y = y / _len;
	result.z = z / _len;

	return result;
}