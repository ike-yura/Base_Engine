#include "GameOverSceneActor.h"
#include "SceneManager.h"
#include <Easing.h>
#include "ImageManager.h"
#include "VariableCommon.h"
#include "Audio.h"
//������
void GameOverSceneActor::Initialize(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) {
	//���ʂ̏�����
	BaseInitialize(dxCommon);
	//�I�[�f�B�I
	Audio::GetInstance()->PlayWave("Resources/Sound/SE/gameOverSE.wav", VolumManager::GetInstance()->GetSEVolum());
	//�V�[���`�F���W���[
	PlayPostEffect = false;
	sceneChanger_ = make_unique<SceneChanger>();
	sceneChanger_->Initialize();
	m_SceneState = SceneState::IntroState;
}
//�X�V
void GameOverSceneActor::Update(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) {
	(this->*stateTable[static_cast<size_t>(m_SceneState)])(camera);
}
//�`��
void GameOverSceneActor::Draw(DirectXCommon* dxCommon) {
	//�|�X�g�G�t�F�N�g�������邩
	if (PlayPostEffect) {
		dxCommon->PreDraw();
		//postEffect->Draw(dxCommon->GetCmdList());
		BackDraw(dxCommon);
		FrontDraw();
		ImGuiDraw(dxCommon);
		dxCommon->PostDraw();
	} else {
		dxCommon->PreDraw();
		ImGuiDraw(dxCommon);
		BackDraw(dxCommon);
		FrontDraw();
		dxCommon->PostDraw();
	}
}
//�O�ʕ`��
void GameOverSceneActor::FrontDraw() {
}
void GameOverSceneActor::IntroUpdate(DebugCamera* camera) {

}
void GameOverSceneActor::MainUpdate(DebugCamera* camera) {

}
void GameOverSceneActor::FinishUpdate(DebugCamera* camera) {
}
//�w��
void GameOverSceneActor::BackDraw(DirectXCommon* dxCommon) {

}
//ImGui�`��
void GameOverSceneActor::ImGuiDraw(DirectXCommon* dxCommon) {
	//SceneSave::GetInstance()->ImGuiDraw();
}
//���
void GameOverSceneActor::Finalize() {
}
