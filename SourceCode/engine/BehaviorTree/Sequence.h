#pragma once
#include "BTNode.h"

//�V�[�P���X
class Sequence : public BTNode {
public:
	//�q�m�[�h�ǉ�
	void AddChild(std::unique_ptr <BTNode> child);

	//�m�[�h�����Ɏ��s
	NodeStatus Tick() override;

	std::vector<std::unique_ptr<BTNode>> childlen;//�q�m�[�h���X�g
};