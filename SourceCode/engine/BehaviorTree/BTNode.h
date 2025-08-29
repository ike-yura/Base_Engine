#pragma once
#include <vector>
#include <memory>

//ノードの実行結果
enum class NodeStatus {
	Success,//成功
	Failure,//失敗
	Running//実行
};

//基底クラス
class BTNode {
public:
	virtual ~BTNode() = default;

	//ノードの処理を実行
	virtual NodeStatus Tick() = 0;
};