#include "Action.h"

//コンストラクタでアクション関数を受け取る
Action::Action(std::function<NodeStatus()> act) : action(act) {
}

//アクションを実行して結果を返す
NodeStatus Action::Tick() {
	return action();
}