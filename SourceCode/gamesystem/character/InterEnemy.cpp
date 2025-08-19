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

//当たり判定
bool InterEnemy::CheckHit() {
	XMFLOAT3 l_PlayerPos = Player::GetInstance()->GetPosition();
	float l_PlayerSca = Player::GetInstance()->GetColScale().x;
	XMFLOAT3 l_emenymax = Helper::GetInstance()->GetAABBMax(m_Position,m_ColScale);
	XMFLOAT3 l_emenymin = Helper::GetInstance()->GetAABBMin(m_Position, m_ColScale);

	if (Collision::SphereAABBCollision(l_PlayerPos, l_PlayerSca,l_emenymin,l_emenymax) && m_WireDraw && Player::GetInstance()->GetWireDraw()) {
		m_ColColor = { 1.0f,0.0f,0.0f,1.0f };
		return true;
	}
	else {
		m_ColColor = { 1.0f,1.0f,1.0f,1.0f };
		return false;
	}

	return false;
}