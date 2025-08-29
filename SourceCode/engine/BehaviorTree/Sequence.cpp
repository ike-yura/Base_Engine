#include "Sequence.h"

//子ノードを追加する関数
void Sequence::AddChild(std::unique_ptr<BTNode> child) {
	childlen.emplace_back(std::move(child));
}

//子ノードを順に実装
NodeStatus Sequence::Tick() {
	for (auto& child : childlen) {
		NodeStatus status = child->Tick();
		//成功以外ならそのまま返す
		if (status != NodeStatus::Success) {
			return status;
		}
	}

	//全部成功の場合成功を返す
	return NodeStatus::Success;
}