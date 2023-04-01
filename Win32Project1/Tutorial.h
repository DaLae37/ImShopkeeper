#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroAnimation.h"
#include "ZeroSoundManager.h"
#include "RestScene.h"


class Tutorial : public ZeroIScene
{
public:
	Tutorial();
	~Tutorial();
	void Update(float eTime);
	void Render();

	ZeroSprite *tuto1;
	ZeroSprite *tuto2;
	bool b;
};

