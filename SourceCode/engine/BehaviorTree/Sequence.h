#pragma once
#include "BTNode.h"

//シーケンス
class Sequence : public BTNode {
public:
	//子ノード追加
	void AddChild(std::unique_ptr <BTNode> child);

	//ノードを順に実行
	NodeStatus Tick() override;

	std::vector<std::unique_ptr<BTNode>> childlen;//子ノードリスト
};