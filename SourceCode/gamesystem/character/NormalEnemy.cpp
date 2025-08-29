#include "NormalEnemy.h"
#include <random>
#include <memory>
#include "Player.h"
#include "Collision.h"
#include "CsvLoader.h"
#include "Helper.h"
#include "Easing.h"
//モデル読み込み
NormalEnemy::NormalEnemy() {
	
}
//初期化
bool NormalEnemy::Initialize() {

	m_Object.reset(new IKEObject3d());
	m_Object->Initialize();
	m_Object->SetModel(ModelManager::GetInstance()->GetModel(ModelManager::PLAYERMODEL));
	m_Object->SetScale({ 2.f,2.f,2.f });
	m_Object->SetPosition({ 0.0f,0.0f,20.0f });
	m_Object->SetColor({ 1.0f,0.0f,0.0,1.0f });
	m_Object->VertexCheck();

	m_ColObject.reset(new IKEObject3d());
	m_ColObject->Initialize();
	m_ColObject->SetModel(ModelManager::GetInstance()->GetModel(ModelManager::BOX));

	m_Scale = { 0.5f,0.5f,0.5f };
	m_Rotation = { 0.0f,0.0f,0.0f };
	
	XMFLOAT3 m_RandPos = {};
	m_RandPos.x = static_cast<float>(Helper::GetInstance()->GetRanNum(-5, 5));
	m_RandPos.y = -5.0f;
	m_RandPos.z = 0.0f;
	m_Position = m_RandPos;
	m_WireType = WIreType::Box;
	m_HitShape = HitShape::Type::AABB;

	BehaviorInit();
	return true;
}

void NormalEnemy::BehaviorInit() {
	auto root = std::make_unique<Selector>();

	//距離によって動きを決める
	//攻撃
	auto attackSeq = std::make_unique<Sequence>();
	attackSeq->AddChild(std::make_unique<Condition>([this]() {
		return Helper::GetInstance()->ChechLength(
			m_Position, Player::GetInstance()->GetPosition()
		) < 1.0f;
		}));
	attackSeq->AddChild(std::make_unique<Action>([this]() {
		this->Attack();
		return NodeStatus::Success;
		}));
	root->AddChild(std::move(attackSeq));

	//追従
	auto followSeq = std::make_unique<Sequence>();
	followSeq->AddChild(std::make_unique<Condition>([this]() {
		return Helper::GetInstance()->ChechLength(
			m_Position, Player::GetInstance()->GetPosition()
		) < 3.0f;
		}));
	followSeq->AddChild(std::make_unique<Action>([this]() {
		this->Follow();
		return NodeStatus::Success;
		}));
	root->AddChild(std::move(followSeq));

	//待機
	root->AddChild(std::make_unique<Action>([this]() {
		this->Inter();
		return NodeStatus::Success;
		}));

	// ツリーを保持
	m_BehaviorTree = std::make_unique<BehaviorTree>(std::move(root));
}
//行動
void NormalEnemy::Act() {
	m_ColScale = { m_Scale.x + 0.25f,m_Scale.y + 0.25f,m_Scale.z + 0.25f };
	
	//ビヘイビアツリーの実行
	if (m_BehaviorTree) {
		m_BehaviorTree->Tick();
	}

	Obj_SetParam();
	ColObj_SetParam();
}
//描画
void NormalEnemy::Draw() {
	Obj_Draw();
}
//ImGui描画
void NormalEnemy::ImGui_Origin() {
	ImGui::Checkbox("WireDraw", &m_WireDraw);
	ImGui::RadioButton("Sphere", &m_WireType, Sphere); ImGui::SameLine(); ImGui::RadioButton("Box", &m_WireType, Box);
	ImGui::SliderFloat("scaleX", &m_Scale.x, 0.1f, 1.5f);
	if (ImGui::Button("modelChange", ImVec2(90, 50))) {
		ChangeShapeType();
	}
	ImGui::Text("WireDraw:%d", m_WireDraw);
}
//開放
void NormalEnemy::Finalize() {

}
//追従
void NormalEnemy::Follow() {
	Helper::GetInstance()->FollowMove(m_Position, Player::GetInstance()->GetPosition(), 0.05f);
}
//待機
void NormalEnemy::Inter() {
	m_Rotation.y += 1.0f;
}
//攻撃
void NormalEnemy::Attack() {
	m_Rotation.y += 3.0f;
}