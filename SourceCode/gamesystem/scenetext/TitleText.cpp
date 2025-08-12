#include "TitleText.h"
TitleText::TitleText() {
};
//������
void TitleText::Initialize(DirectXCommon* dxCommon) {
	text_ = make_unique<TextManager>();
	text_->Initialize(dxCommon);
	text_->SetConversation(TextManager::FIRST);
}
//�e�L�X�g�̑I��
void TitleText::SelectText(TextManager::TITLE name) {
	text_->SetConversation(name);
}
//�F�ύX
void TitleText::ChangeColor(int row, const XMVECTOR& color) {
	text_->SetOnceColor(row, color);
}
//���ׂĂ̐F�ύX
void TitleText::ChangeAllColor(const XMVECTOR& color) {
	text_->SetAllColor(color);
}

void TitleText::SpriteDraw(DirectXCommon* dxCommon) {
	text_->TestDraw(dxCommon);
}