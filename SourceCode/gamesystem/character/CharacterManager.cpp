#include "CharacterManager.h"
#include "Player.h"
//初期化
void CharacterManager::Initialize() {
	//プレイヤー
	Player::GetInstance()->LoadResource();
	Player::GetInstance()->InitState({ 0.0f,-5.0f,0.0f });
	Player::GetInstance()->Initialize();

	//敵
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i].reset(new NormalEnemy());
		enemy[i]->Initialize();
	}
}
//更新
void CharacterManager::Update() {
	Player::GetInstance()->Update();

	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
	}
}
//描画
void CharacterManager::Draw() {
	Player::GetInstance()->Draw();
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Draw();
	}
}
//Imgui
void CharacterManager::ImguiDraw() {
	Player::GetInstance()->ImGuiDraw();

	//idをつけなきゃいけないので、このやり方にする
	ImGui::Begin("Enemy");
	for (int i = 0; i < enemy.size(); i++) {
		ImGui::PushID(i);
		enemy[i]->ImGuiDraw();
		ImGui::PopID();
	}
	ImGui::End();
}