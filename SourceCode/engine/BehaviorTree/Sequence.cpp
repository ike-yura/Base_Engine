#include "Sequence.h"

//�q�m�[�h��ǉ�����֐�
void Sequence::AddChild(std::unique_ptr<BTNode> child) {
	childlen.emplace_back(std::move(child));
}

//�q�m�[�h�����Ɏ���
NodeStatus Sequence::Tick() {
	for (auto& child : childlen) {
		NodeStatus status = child->Tick();
		//�����ȊO�Ȃ炻�̂܂ܕԂ�
		if (status != NodeStatus::Success) {
			return status;
		}
	}

	//�S�������̏ꍇ������Ԃ�
	return NodeStatus::Success;
}