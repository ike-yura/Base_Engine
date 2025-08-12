#include "EndRollActor.h"
#include "SceneManager.h"
#include <Easing.h>
#include "ImageManager.h"
#include "Audio.h"
#include "Helper.h"
//������
void EndRollActor::Initialize(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) {
	//���ʂ̏�����
	BaseInitialize(dxCommon);
	//���̃V�[�������Z�s�A�J���[����
	postEffect->CreateGraphicsPipeline(L"Resources/Shaders/PostEffectTestVS.hlsl", L"Resources/Shaders/SepiaPS.hlsl");
	Audio::GetInstance()->LoopWave(AUDIO_TITLE, VolumManager::GetInstance()->GetBGMVolum() + 1.0f);
	//�V�[���`�F���W���[
	PlayPostEffect = false;
	sceneChanger_ = make_unique<SceneChanger>();
	sceneChanger_->Initialize();
	m_SceneState = SceneState::IntroState;
}
//�X�V
void EndRollActor::Update(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) {
	(this->*stateTable[static_cast<size_t>(m_SceneState)])(camera);
}
//�`��
void EndRollActor::Draw(DirectXCommon* dxCommon) {
	//�|�X�g�G�t�F�N�g�������邩
	if (PlayPostEffect) {
		postEffect->PreDrawScene(dxCommon->GetCmdList());
		BackDraw(dxCommon);
		postEffect->PostDrawScene(dxCommon->GetCmdList());

		dxCommon->PreDraw();
		postEffect->Draw(dxCommon->GetCmdList());
		//ImGuiDraw(dxCommon);
		FrontDraw();
		//postEffect->ImGuiDraw();
		dxCommon->PostDraw();
	}
	else {
		dxCommon->PreDraw();
		//ImGuiDraw(dxCommon);
		BackDraw(dxCommon);
		FrontDraw();
		dxCommon->PostDraw();
	}
}
//�O�ʕ`��
void EndRollActor::FrontDraw() {
	IKESprite::PreDraw();
	IKESprite::PostDraw();
}
void EndRollActor::IntroUpdate(DebugCamera* camera) {
}
void EndRollActor::MainUpdate(DebugCamera* camera) {
}
void EndRollActor::FinishUpdate(DebugCamera* camera) {
}

//�w��
void EndRollActor::BackDraw(DirectXCommon* dxCommon) {
}
//ImGui�`��
void EndRollActor::ImGuiDraw(DirectXCommon* dxCommon) {
}
//���
void EndRollActor::Finalize() {
}
