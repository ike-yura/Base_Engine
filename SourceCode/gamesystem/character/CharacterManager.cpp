#include "CharacterManager.h"
#include "Player.h"
#include "HitChecker.h"
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
	Player* player = Player::GetInstance();
	player->Update();
	// 敵の更新
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
	}
	// HitChecker に登録
	HitChecker hitChecker;
	HitShape playerShape(HitShape::Type::AABB); // プレイヤーは球
	hitChecker.Register(player, &playerShape);

	for (int i = 0; i < enemy.size(); i++) {
		HitShape enemyShape(HitShape::Type::AABB); // 敵は箱
		hitChecker.Register(enemy[i].get(), &enemyShape);
	}

	// 当たり判定チェック
	auto hits = hitChecker.CheckHits();
	// 全体を一旦白に戻す
	player->SetColColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->SetColColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}

	// 衝突しているオブジェクトだけ赤にする
	for (auto& pair : hits) {
		ObjCommon* a = pair.first;
		ObjCommon* b = pair.second;
		if (a->GetWireDraw() && b->GetWireDraw()) {
			a->SetColColor({ 1.0f, 0.0f, 0.0f, 1.0f });
			b->SetColColor({ 1.0f, 0.0f, 0.0f, 1.0f });
		}
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