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

void InterEnemy::ChangeShapeType() {
	if (m_WireType == Sphere) {

		m_ColObject->SetModel(ModelManager::GetInstance()->GetModel(ModelManager::SPHERE));
		m_HitShape = HitShape::Type::Sphere;
		m_Scale = { 0.5f,0.5f,0.5f };
	}
	else {
		m_ColObject->SetModel(ModelManager::GetInstance()->GetModel(ModelManager::BOX));
		m_HitShape = HitShape::Type::AABB;
		m_Scale = { 1.5f,0.5f,0.5f };
	}
}