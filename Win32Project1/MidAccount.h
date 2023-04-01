#pragma once
#include "ZeroIScene.h"
#include "ZeroSceneManager.h"
#include "DataManager.h"
#include "Number.h"
#include "RestScene.h"
#include "ZeroSprite.h"
class MidAccount : public ZeroIScene
{
public:
	MidAccount();
	~MidAccount();
	void Update(float eTime);
	void Render();
	float delay;
	bool isDelay;
	ZeroSprite *background;
	ZeroSprite *Pop;
	Number *money[4];
	Number *goalmoney[4];
	Number *day[2];
	DataManager *data;
};

