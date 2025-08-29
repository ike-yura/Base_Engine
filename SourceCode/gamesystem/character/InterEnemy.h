#pragma once
#include "ObjCommon.h"
#include "BehaviorTree.h"
#include "Selector.h"
#include "Sequence.h"
#include "Condition.h"
#include "Action.h"

//�G���
class InterEnemy :
	public ObjCommon {
protected:
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public://getter setter

protected:
	enum WIreType
	{
		Sphere,
		Box
	};

	int m_WireType = Sphere;
	// �GAI�p�̃r�w�C�r�A�c���[
	std::unique_ptr<BehaviorTree> m_BehaviorTree;
public:
	//virtual ~InterEnemy() = default;

	/// <summary>
	/// ������
	/// </summary>
	virtual bool Initialize()override;
	
	virtual void BehaviorInit() = 0;//�r�w�C�r�A�c���[�̏�����
	/// <summary>
	/// �I��
	/// </summary>
	virtual void Finalize() = 0;
	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	void Update();

	virtual void Act() = 0;//�G�̍s��

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw()override;

	void ImGuiDraw();

	virtual void ImGui_Origin() = 0;

	void ChangeShapeType();
};