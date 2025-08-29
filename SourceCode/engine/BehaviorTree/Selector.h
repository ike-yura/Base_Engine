#pragma once
#include "BTNode.h"

//�Z���N�^�[
//�ŏ��ɐ��������q�m�[�h�ɐ�����Ԃ�
//���ׂĎ��s�̏ꍇ�͎��s��Ԃ�
class Selector : public BTNode {
public:
	//�q�m�[�h�ǉ�
	void AddChild(std::unique_ptr <BTNode> child);

	//�m�[�h�����Ɏ��s
	NodeStatus Tick() override;

	std::vector<std::unique_ptr<BTNode>> childlen;//�q�m�[�h���X�g
};
