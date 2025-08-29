#pragma once
#include "BTNode.h"
#include <functional>

//条件
//条件関数を実行して成功か失敗を返す
class Condition : public BTNode {
public:
	//ラムダ関数などを返す
	Condition(std::function<bool()> cond);

	//条件の結果
	NodeStatus Tick() override;

	std::function<bool()> condition;//条件チェック用
};