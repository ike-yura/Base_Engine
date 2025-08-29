#pragma once
#include "BTNode.h"
#include <functional>

//アクションノード
//行動を関数で保持、それを実行
class Action : public BTNode {
public:
	//ラムダ関数などを返す
	Action(std::function<NodeStatus()> cond);

	//条件の結果
	NodeStatus Tick() override;

	std::function<NodeStatus()> action;//実行用
};