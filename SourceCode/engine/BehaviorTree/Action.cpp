#include "Action.h"

//�R���X�g���N�^�ŃA�N�V�����֐����󂯎��
Action::Action(std::function<NodeStatus()> act) : action(act) {
}

//�A�N�V���������s���Č��ʂ�Ԃ�
NodeStatus Action::Tick() {
	return action();
}