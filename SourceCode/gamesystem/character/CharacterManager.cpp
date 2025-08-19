#include "CharacterManager.h"
#include "Player.h"
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
	Player::GetInstance()->Update();
	bool l_Hit = false;
	for (int i = 0; i < enemy.size(); i++) {
		enemy[i]->Update();
		if (enemy[i]->CheckHit()) { // �����蔻�肾���Ԃ��֐�
			l_Hit = true;
		}
	}

	//�������Ă��邩�ǂ����ŐF��ς���
	if (l_Hit) {
		Player::GetInstance()->SetColColor({ 1.0f,0.0f,0.0f,1.0f });
	}
	else {
		Player::GetInstance()->SetColColor({ 1.0f,1.0f,1.0f,1.0f });
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