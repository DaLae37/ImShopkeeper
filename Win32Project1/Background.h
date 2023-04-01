#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroCameraManager.h"
class Background : public ZeroIScene
{
public:
	Background();
	~Background();
	ZeroSprite *gameBackground;
	ZeroSprite *stand;
	ZeroSprite *stand1;
	ZeroSprite *colon;
	ZeroSprite *gameBackground1;
	void Update(float eTime);
	void Render();
};

