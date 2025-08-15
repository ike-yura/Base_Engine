#include "FirstStageActor.h"
#include"Easing.h"
#include "ParticleEmitter.h"
#include "ImageManager.h"
#include "Player.h"
#include "Helper.h"
#include "FPSManager.h"

void FirstStageActor::Initialize(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) {
	dxCommon->SetFullScreen(true);
	//共通の初期化
	BaseInitialize(dxCommon);
	//オーディオ
	//Audio::GetInstance()->LoopWave(AUDIO_BATTLE, VolumManager::GetInstance()->GetBGMVolum() + 1.0f);
	//ポストエフェクト
	PlayPostEffect = false;
	//パーティクル全削除
	ParticleEmitter::GetInstance()->AllDelete();

	m_SceneState = SceneState::IntroState;

	lightgroup->SetCircleShadowActive(0, true);

	/*
	lightgroup->SetCircleShadowActive(1, true);
	lightgroup->SetDirLightActive(0, true);

	lightgroup->Update();
	///ポイントライト
	lightgroup->SetPointLightPos(0, XMFLOAT3(Player::GetInstance()->GetPosition().x, Player::GetInstance()->GetPosition().y + 2.0f, Player::GetInstance()->GetPosition().z - 5.0f));
	lightgroup->SetPointLightColor(0, XMFLOAT3(pointLightColor));
	lightgroup->SetPointLightAtten(0, XMFLOAT3({ 6.0f,6.0f,6.0f }));*/

	//ライト
	/*lightgroup->SetDirLightActive(0, true);
	lightgroup->SetDirLightActive(1, true);
	lightgroup->SetDirLightActive(2, true);
	lightgroup->SetPointLightActive(0, false);
	lightgroup->SetPointLightActive(1, false);*/

	
	//地面
	ground.reset(new IKEObject3d());
	ground->Initialize();
	ground->SetModel(ModelManager::GetInstance()->GetModel(ModelManager::GROUND));
	ground->SetScale({ 2.f,1.f,2.f });
	ground->SetPosition({ 0.0f,-10.0f,0.0f });
	ground->SetAddOffset(3.0f);
	ground->VertexCheck();
	ground->SetFog(true);

	//スカイドーム
	skydome.reset(new IKEObject3d());
	skydome->Initialize();
	skydome->SetModel(ModelManager::GetInstance()->GetModel(ModelManager::SKYDOME));
	skydome->SetScale({ 1.f,1.f,1.f });
	skydome->SetColor({ 1.0f,1.0f,1.0f,1.0f });
	skydome->SetPosition({ 0.0f,0.0f,0.0f });
	skydome->VertexCheck();

	//プレイヤー
	Player::GetInstance()->LoadResource();
	Player::GetInstance()->InitState({ 0.0f,-5.0f,0.0f });
	Player::GetInstance()->Initialize();

	////敵
	//for (int i = 0; i < enemy.size(); i++) {
	//	enemy[i].reset(new NormalEnemy());
	//	enemy[i]->Initialize();
	//}

	//テクスチャ
	tex.reset(IKETexture::Create(ImageManager::MAGIC, { 0,0,0 }, { 0.5f,0.5f,0.5f }, { 1,1,1,1 }));
	tex->TextureCreate();
	tex->SetPosition({ 5.0f,2.0f,0.0f });
	tex->SetScale({ 0.5f,0.5f,0.5f });
	tex->SetIsBillboard(true);
	//tex->SetColor({ 1.0f,0.0,0.0f,1.0f });
}

void FirstStageActor::Finalize() {
}

void FirstStageActor::Update(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) {
	//関数ポインタで状態管理
	(this->*stateTable[static_cast<size_t>(m_SceneState)])(camera);

	//各クラス更新
	camerawork->Update(camera);

	//プレイヤー
	lightgroup->SetCircleShadowDir(0, XMVECTOR({ circleShadowDir[0], circleShadowDir[1], circleShadowDir[2], 0 }));
	lightgroup->SetCircleShadowCasterPos(0, XMFLOAT3({ Player::GetInstance()->GetPosition().x, 0.0f, Player::GetInstance()->GetPosition().z }));
	lightgroup->SetCircleShadowAtten(0, XMFLOAT3(circleShadowAtten));
	lightgroup->SetCircleShadowFactorAngle(0, XMFLOAT2(circleShadowFactorAngle));
	lightgroup->Update();
	ground->Update();
	skydome->Update();
	m_AddOffset.x = 0.001f;
	ground->SetAddOffset(m_AddOffset.x);
	Player::GetInstance()->Update();
	ParticleEmitter::GetInstance()->Update();
	/*
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
	}*/
	tex->Update();
}

void FirstStageActor::Draw(DirectXCommon* dxCommon) {
	//描画方法
	//ポストエフェクトをかけるか
	if (PlayPostEffect) {
		postEffect->PreDrawScene(dxCommon->GetCmdList());
		BackDraw(dxCommon);
		FrontDraw(dxCommon);
		postEffect->PostDrawScene(dxCommon->GetCmdList());

		dxCommon->PreDraw();
		postEffect->Draw(dxCommon->GetCmdList());
		ImGuiDraw();
		dxCommon->PostDraw();
	} else {
		postEffect->PreDrawScene(dxCommon->GetCmdList());
		postEffect->Draw(dxCommon->GetCmdList());
		postEffect->PostDrawScene(dxCommon->GetCmdList());
		dxCommon->PreDraw();
		BackDraw(dxCommon);
		FrontDraw(dxCommon);
		ImGuiDraw();
		dxCommon->PostDraw();
	}
}
//ポストエフェクトかからない
void FirstStageActor::FrontDraw(DirectXCommon* dxCommon) {

}
//ポストエフェクトかかる
void FirstStageActor::BackDraw(DirectXCommon* dxCommon) {
	IKEObject3d::PreDraw();
	ground->Draw();
	skydome->Draw();
	ParticleEmitter::GetInstance()->FlontDrawAll();
	Player::GetInstance()->Draw(dxCommon);
	/*for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Draw(dxCommon);
	}*/
	IKEObject3d::PostDraw();

	IKETexture::PreDraw2(dxCommon, AlphaBlendType);
	tex->Draw();
	IKETexture::PostDraw();
}
//導入しーんの更新
void FirstStageActor::IntroUpdate(DebugCamera* camera) {

}
//プレイ中の更新
void FirstStageActor::MainUpdate(DebugCamera* camera) {

}

void FirstStageActor::FinishUpdate(DebugCamera* camera) {
	Input* input = Input::GetInstance();
}

void FirstStageActor::ImGuiDraw() {
	ImGui::Begin("FIRST");
	ImGui::Text("GroundNum:%d",ground->GetVertexNum());
	ImGui::Text("SkydomeNum:%d", skydome->GetVertexNum());
	ImGui::End();

	Player::GetInstance()->ImGuiDraw();
	FPSManager::GetInstance()->ImGuiDraw();
}
