#pragma once
#include "NormalEnemy.h"
#include<vector>
#include <array>
class CharacterManager {
public:
	//‰Šú‰»
	void Initialize();
	//XV
	void Update();
	//•`‰æ
	void Draw();
	//Imgui
	void ImguiDraw();
private:
	array<unique_ptr<InterEnemy>, 1> enemy;
};