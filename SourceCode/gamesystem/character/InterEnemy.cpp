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
bool InterEnemy::CheckHit() {
	XMFLOAT3 l_PlayerPos = Player::GetInstance()->GetPosition();
	if (Collision::SphereCollision(m_Position,m_ColScale.x, l_PlayerPos,Player::GetInstance()->GetColScale().x) && m_WireDraw && Player::GetInstance()->GetWireDraw()) {
		m_ColColor = { 1.0f,0.0f,0.0f,1.0f };
		return true;
	}
	else {
		m_ColColor = { 1.0f,1.0f,1.0f,1.0f };
		return false;
	}

	return false;
}