#pragma once
#include "BTNode.h"
#include <memory>

//ビヘイビアツリー全体用
class BehaviorTree {
public:
	BehaviorTree(std::unique_ptr<BTNode> rootNode);
	//ツリーを更新
	void Tick();

	std::unique_ptr<BTNode> root;//ルートノード
};