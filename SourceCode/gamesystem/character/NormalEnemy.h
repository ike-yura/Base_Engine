#pragma once
#include"InterEnemy.h"
using namespace std;         //  ���O��Ԏw��
//���ʂ̓G
class NormalEnemy :public InterEnemy {
public:
	NormalEnemy();
	bool Initialize() override;//������
	void BehaviorInit() override;//�r�w�C�r�A�c���[�̏�����
	void Finalize() override;//�J��
	void Act()override;//�X�V
	void ImGui_Origin()override;

	void Draw() override;//�`��
private:
	//�L�����̏��
	enum CharaState
	{
		STATE_INTER,
		STATE_FOLLOW,
		STATE_CIRCLE,
		STATE_SIN,
	};

	//�֐��|�C���^
	static void(NormalEnemy::* stateTable[])();

	int _charaState = STATE_INTER;

private:
	void Attack();
	void Inter();//�ҋ@
	void Follow();//�Ǐ]
protected:

private:
	//�~�^���̕ϐ�
	float m_CircleAngle = 0.0f;
	float m_CircleRadius = 0.0f;
	float m_CircleSpeed = 0.0f;
	float m_CircleScale = 20.0f;
	//�Ǐ]�p�ϐ�
	XMFLOAT3 m_FollowVel{};
	//�C�[�W���O��̈ʒu
	XMFLOAT3 m_AfterPos = {};
	//���߂̍��W
	XMFLOAT3 m_StartPos = {};
};

