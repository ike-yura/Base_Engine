﻿#pragma once
#include "DebugCamera.h"
#include "Shake.h"
#include <memory>
#include "Feed.h"
#include "InterBoss.h"
#include"Spline.h"
using namespace std;         //  名前空間指定

//ゲームのカメラの動き
class CameraWork {
private:
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public:
	CameraWork(XMFLOAT3 eye = { 2.0f, 30.0f, 2.0f }, XMFLOAT3 target = { 2.0f, 0.0f, 3.0f });
	void SplineSet();
	void Update(DebugCamera* camera);//更新
	void ImGuiDraw();
};