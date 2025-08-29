#include "Condition.h"

//�R���X�g���N�^�ŏ����֐����󂯎��
Condition::Condition(std::function<bool()> cond) : condition(cond) {
}

//�������猋�ʂ�Ԃ�
NodeStatus Condition::Tick() {
	return condition() ? NodeStatus::Success : NodeStatus::Failure;
}