#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
class Number : public ZeroIScene
{
public:
	Number();
	~Number();
	ZeroSprite *number[10];
	void Update(float eTime);
	void Render();
};

