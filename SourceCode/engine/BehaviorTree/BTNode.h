#pragma once
#include <vector>
#include <memory>

//�m�[�h�̎��s����
enum class NodeStatus {
	Success,//����
	Failure,//���s
	Running//���s
};

//���N���X
class BTNode {
public:
	virtual ~BTNode() = default;

	//�m�[�h�̏��������s
	virtual NodeStatus Tick() = 0;
};