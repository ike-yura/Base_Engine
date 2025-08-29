#pragma once
#include "BTNode.h"

//セレクター
//最初に成功した子ノードに成功を返す
//すべて失敗の場合は失敗を返す
class Selector : public BTNode {
public:
	//子ノード追加
	void AddChild(std::unique_ptr <BTNode> child);

	//ノードを順に実行
	NodeStatus Tick() override;

	std::vector<std::unique_ptr<BTNode>> childlen;//子ノードリスト
};
