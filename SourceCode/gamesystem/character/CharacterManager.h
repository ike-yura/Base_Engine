#pragma once
#include "NormalEnemy.h"
#include<vector>
#include <array>
class CharacterManager {
public:
	//������
	void Initialize();
	//�X�V
	void Update();
	//�`��
	void Draw();
	//Imgui
	void ImguiDraw();
private:
	array<unique_ptr<InterEnemy>, 1> enemy;
};