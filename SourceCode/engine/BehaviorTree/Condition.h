#pragma once
#include "BTNode.h"
#include <functional>

//����
//�����֐������s���Đ��������s��Ԃ�
class Condition : public BTNode {
public:
	//�����_�֐��Ȃǂ�Ԃ�
	Condition(std::function<bool()> cond);

	//�����̌���
	NodeStatus Tick() override;

	std::function<bool()> condition;//�����`�F�b�N�p
};