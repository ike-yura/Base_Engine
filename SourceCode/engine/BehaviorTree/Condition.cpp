#include "Condition.h"

//コンストラクタで条件関数を受け取る
Condition::Condition(std::function<bool()> cond) : condition(cond) {
}

//条件から結果を返す
NodeStatus Condition::Tick() {
	return condition() ? NodeStatus::Success : NodeStatus::Failure;
}