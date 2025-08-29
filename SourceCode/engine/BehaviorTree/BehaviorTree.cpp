#include "BehaviorTree.h"

//ルートノードのセット
BehaviorTree::BehaviorTree(std::unique_ptr<BTNode> rootNode) : root(std::move(rootNode)) {
}

//ルートノードの処理を実行
void BehaviorTree::Tick() {
	if (root) {
		root->Tick();
	}
}