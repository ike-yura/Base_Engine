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
	bool l_Hit = false;
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
		if (enemy[i]->CheckHit()) { // 当たり判定だけ返す関数
			l_Hit = true;
		}
	}

	//当たっているかどうかで色を変える
	if (l_Hit) {
		Player::GetInstance()->SetColColor({ 1.0f,0.0f,0.0f,1.0f });
	}
	else {
		Player::GetInstance()->SetColColor({ 1.0f,1.0f,1.0f,1.0f });
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