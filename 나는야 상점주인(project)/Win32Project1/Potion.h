#pragma once
#include "ZeroIScene.h"
#include "ZeroInputManager.h"
#include "ZeroSprite.h"
#include "Background.h"
class Potion : public ZeroIScene
{
public:
	Potion();
	~Potion();
	ZeroSprite *potion[7];
	ZeroSprite *small_potion[7];
	void Update(float eTime);
	void Render();
};

