#pragma once
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "ZeroSoundManager.h"
#include "ZeroAnimation.h"
#include "ZeroTextureManager.h"
#include "MainScene.h"
class Loading : public ZeroIScene
{
public:
	Loading();
	~Loading();
	void Update(float eTime);
	void Render();
	ZeroAnimation *powered;
	float countTime;
	bool once;
};

