#pragma once
#include "Easing.h"
#include "IKESprite.h"
#include <WinApp.h>

#include<vector>
#include <memory>
#include<string>
#include <list>

#include "Feed.h"

//�V�[���`�F���W�N���X
class SceneChanger {
public:
	SceneChanger();
	~SceneChanger();

	/// <summary>
	/// ����k����
	/// </summary>
	void Initialize();
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// ����k����
	/// </summary>
	void InitializeOver();
};