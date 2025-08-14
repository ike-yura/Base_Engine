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
	void Draw(DirectXCommon* dxCommon)override;
	//ImGui
	void ImGuiDraw();
	//パーティクル
	void BirthParticle();
	
private:
	XMFLOAT3 MoveVECTOR(XMVECTOR v, float angle);
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
	//プレイヤーのHP
	int m_HP = 0;

private:
	unique_ptr<CsvLoader> loader = nullptr;
};