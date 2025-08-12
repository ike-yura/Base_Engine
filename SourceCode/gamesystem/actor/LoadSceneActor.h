#pragma once
#include "BaseActor.h"
#include "IKESprite.h"
#include "JsonLoader.h"
#include <map>
#include <array>
/// �^�C�g���V�[��
class LoadSceneActor : public BaseActor {
public:
	/// ������
	void Initialize(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) override;
	/// �I��
	void Finalize() override;
	/// ���t���[���X�V
	void Update(DirectXCommon* dxCommon, DebugCamera* camera, LightGroup* lightgroup) override;
	/// �`��
	void Draw(DirectXCommon* dxCommon) override;
	void BackDraw(DirectXCommon* dxCommon);
	void ImGuiDraw(DirectXCommon* dxCommon);
	void SpriteDraw();
private:
	void IntroUpdate(DebugCamera* camera)override;
	void MainUpdate(DebugCamera* camera)override;
	void FinishUpdate(DebugCamera* camera)override;


private://�����o�ϐ�

};