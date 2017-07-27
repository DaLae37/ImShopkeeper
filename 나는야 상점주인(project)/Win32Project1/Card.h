#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
class Card : public ZeroIScene
{
public:
	Card();
	~Card();
	void Update(float eTime);
	void Render();
	ZeroSprite *card[13];
	ZeroSprite *back;
};

