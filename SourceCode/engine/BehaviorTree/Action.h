#pragma once
#include "BTNode.h"
#include <functional>

//�A�N�V�����m�[�h
//�s�����֐��ŕێ��A��������s
class Action : public BTNode {
public:
	//�����_�֐��Ȃǂ�Ԃ�
	Action(std::function<NodeStatus()> cond);

	//�����̌���
	NodeStatus Tick() override;

	std::function<NodeStatus()> action;//���s�p
};