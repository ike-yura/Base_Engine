#pragma once
#include "ObjCommon.h"
#include "BehaviorTree.h"
#include "Selector.h"
#include "Sequence.h"
#include "Condition.h"
#include "Action.h"

//敵基底
class InterEnemy :
	public ObjCommon {
protected:
	// DirectX::を省略
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
	// 敵AI用のビヘイビアツリー
	std::unique_ptr<BehaviorTree> m_BehaviorTree;
public:
	//virtual ~InterEnemy() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual bool Initialize()override;
	
	virtual void BehaviorInit() = 0;//ビヘイビアツリーの初期化
	/// <summary>
	/// 終了
	/// </summary>
	virtual void Finalize() = 0;
	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update();

	virtual void Act() = 0;//敵の行動

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw()override;

	void ImGuiDraw();

	virtual void ImGui_Origin() = 0;

	void ChangeShapeType();
};