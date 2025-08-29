#include "Selector.h"

//子ノードを追加する関数
void Selector::AddChild(std::unique_ptr<BTNode> child) {
	childlen.emplace_back(std::move(child));
}

//子ノードを順に実装
NodeStatus Selector::Tick() {
	for (auto& child : childlen) {
		NodeStatus status = child->Tick();
		//失敗以外ならそのまま返す
		if (status != NodeStatus::Failure) {
			return status;
		}
	}

	//全部成功の場合成功を返す
	return NodeStatus::Failure;
}