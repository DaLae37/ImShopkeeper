#pragma once
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "ZeroSoundManager.h"
#include "ZeroSprite.h"
#include "RestScene.h"
#include "DataManager.h"
#include "AccountScene.h"

class MainScene : public ZeroIScene
{
public:
	MainScene();
	~MainScene();
	void Update(float eTime);
	void Render();
	bool press[2];
	bool isClicked;
	DataManager *data;
	ZeroSprite *cursor[2];
	ZeroSprite *mainBackground;
	ZeroSprite *startGame;
	ZeroSprite *endGame;
	ZeroSprite *onstartGame;
	ZeroSprite *onendGame;
};

