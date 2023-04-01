#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "ZeroSoundManager.h"
#include "RestScene.h"
#include "BlackJack.h"
class MiniGameScene : public ZeroIScene
{
public:
	MiniGameScene();
	~MiniGameScene();
	void Update(float eTime);
	void Render();
	ZeroSprite *background;
	ZeroSprite *back;
	ZeroSprite *cardGameButton;
	ZeroSprite *comming;
	bool isClicked;
	ZeroSprite *cursor[2];
};

