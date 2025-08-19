#include "InterEnemy.h"
#include "Collision.h"
#include "Helper.h"
#include "Player.h"
//初期化
bool InterEnemy::Initialize() {
	return true;
}
//更新
void InterEnemy::Update() {
	//�s��
	Action();
}
//描画
void InterEnemy::Draw() {
}

void InterEnemy::ImGuiDraw() {
	ImGui_Origin();
}

//プレイヤーがダメージ食らう
void InterEnemy::PlayerCollide() {
	XMFLOAT3 l_PlayerPos = Player::GetInstance()->GetPosition();
	if (Collision::SphereCollision(m_Position,m_ColScale.x, l_PlayerPos,Player::GetInstance()->GetColScale().x)) {

		m_ColColor = { 1.0f,0.0f,0.0f,1.0f };
		Player::GetInstance()->SetColColor({ 1.0f,0.0f,0.0f,1.0f });
	}
	else {
		m_ColColor = { 1.0f,1.0f,1.0f,1.0f };
		Player::GetInstance()->SetColColor({ 1.0f,1.0f,1.0f,1.0f });
	}

}