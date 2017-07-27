#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "DataManager.h"

class CloseScene : public ZeroIScene
{
public:
	CloseScene();
	~CloseScene();
	ZeroSprite *back;
	void Update(float eTime);
	void Render();
};