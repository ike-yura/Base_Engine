#pragma once
#include "BTNode.h"
#include <memory>

//�r�w�C�r�A�c���[�S�̗p
class BehaviorTree {
public:
	BehaviorTree(std::unique_ptr<BTNode> rootNode);
	//�c���[���X�V
	void Tick();

	std::unique_ptr<BTNode> root;//���[�g�m�[�h
};