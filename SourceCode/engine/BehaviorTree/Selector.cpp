#include "Selector.h"

//�q�m�[�h��ǉ�����֐�
void Selector::AddChild(std::unique_ptr<BTNode> child) {
	childlen.emplace_back(std::move(child));
}

//�q�m�[�h�����Ɏ���
NodeStatus Selector::Tick() {
	for (auto& child : childlen) {
		NodeStatus status = child->Tick();
		//���s�ȊO�Ȃ炻�̂܂ܕԂ�
		if (status != NodeStatus::Failure) {
			return status;
		}
	}

	//�S�������̏ꍇ������Ԃ�
	return NodeStatus::Failure;
}