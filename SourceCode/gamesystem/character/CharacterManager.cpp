#include "CharacterManager.h"
#include "Player.h"
#include "HitChecker.h"
//������
void CharacterManager::Initialize() {
	//�v���C���[
	Player::GetInstance()->LoadResource();
	Player::GetInstance()->InitState({ 0.0f,-5.0f,0.0f });
	Player::GetInstance()->Initialize();

	//�G
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i].reset(new NormalEnemy());
		enemy[i]->Initialize();
	}
}
//�X�V
void CharacterManager::Update() {
	Player* player = Player::GetInstance();
	player->Update();
	// �G�̍X�V
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
	}
	// HitChecker �ɓo�^
	HitChecker hitChecker;
	HitShape playerShape(HitShape::Type::AABB); // �v���C���[�͋�
	hitChecker.Register(player, &playerShape);

	for (int i = 0; i < enemy.size(); i++) {
		HitShape enemyShape(HitShape::Type::AABB); // �G�͔�
		hitChecker.Register(enemy[i].get(), &enemyShape);
	}

	// �����蔻��`�F�b�N
	auto hits = hitChecker.CheckHits();
	// �S�̂���U���ɖ߂�
	player->SetColColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->SetColColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}

	// �Փ˂��Ă���I�u�W�F�N�g�����Ԃɂ���
	for (auto& pair : hits) {
		ObjCommon* a = pair.first;
		ObjCommon* b = pair.second;
		if (a->GetWireDraw() && b->GetWireDraw()) {
			a->SetColColor({ 1.0f, 0.0f, 0.0f, 1.0f });
			b->SetColColor({ 1.0f, 0.0f, 0.0f, 1.0f });
		}
	}
}
//�`��
void CharacterManager::Draw() {
	Player::GetInstance()->Draw();
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Draw();
	}
}
//Imgui
void CharacterManager::ImguiDraw() {
	Player::GetInstance()->ImGuiDraw();

	//id�����Ȃ��Ⴂ���Ȃ��̂ŁA���̂����ɂ���
	ImGui::Begin("Enemy");
	for (int i = 0; i < enemy.size(); i++) {
		ImGui::PushID(i);
		enemy[i]->ImGuiDraw();
		ImGui::PopID();
	}
	ImGui::End();
}