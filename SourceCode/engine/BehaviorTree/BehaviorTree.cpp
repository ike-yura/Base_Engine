#include "BehaviorTree.h"

//���[�g�m�[�h�̃Z�b�g
BehaviorTree::BehaviorTree(std::unique_ptr<BTNode> rootNode) : root(std::move(rootNode)) {
}

//���[�g�m�[�h�̏��������s
void BehaviorTree::Tick() {
	if (root) {
		root->Tick();
	}
}