#pragma once
#include "ObjCommon.h"
#include "CsvLoader.h"
#include <any>
using namespace DirectX;
class Player :public ObjCommon
{
public:
	static Player* GetInstance();

private:
public:
	void InitState(const XMFLOAT3& pos);
	void LoadResource();
	//初期化
	bool Initialize()override;
	//更新
	void Update()override;
	//描画
	void Draw()override;
	//ImGui
	void ImGuiDraw();
	//パーティクル
	void BirthParticle();
	
private:
	XMFLOAT3 MoveVECTOR(XMVECTOR v, float angle);
	void ChangeShapeType();
	void Move();
	void Jump();
private:
	void LoadCSV();
	void reLoadCSV();

private:
	//移動方向指定用
	float angle = 0.0f;
	//歩きまたは走り状態
	float velocity;
	//移動加算値
	float m_AddSpeed;
	//上昇度
	float m_AddPower = 0.0f;
	//重力加速度
	float m_Gravity = 0.02f;
	//プレイヤーのHP
	int m_HP = 0;
	bool m_Jump = false;

private:
	unique_ptr<CsvLoader> loader = nullptr;
	enum WIreType
	{
		Sphere,
		Box
	};

	int m_WireType = Sphere;
};