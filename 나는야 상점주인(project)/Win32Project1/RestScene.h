#pragma once
#include "ZeroIScene.h"
#include "ZeroSceneManager.h"
#include "GameScene.h"
#include "DataManager.h"
#include "MainScene.h"
#include "ZeroSprite.h"
#include "Number.h"
#include "Potion.h"
#include "PotionBuy.h"
#include "PopUp.h"
#include "ZeroSoundManager.h"
#include "MiniGameScene.h"
#include "achieveScene.h"
#include "Tutorial.h"
#include <math.h>
#define SPEED 3

class RestScene  : public ZeroIScene
{
private:
	float MouseX;
	float MouseY;
	float angle;
	bool clicked;
	bool press;
	bool moving;
	float speedX;
	float speedY;
public:
	RestScene();
	~RestScene();
	ZeroSprite *cursor[2];
	ZeroSprite *start[3];
	ZeroSprite *coin;
	ZeroSprite *sun;
	ZeroSprite *goPotion;
	ZeroSprite *back;
	ZeroSprite *restBackground;
	ZeroSprite *achieveButton;
	ZeroSprite *potionShop;
	ZeroSprite *seller;
	ZeroSprite *reset;
	ZeroSprite *potal[3];
	ZeroSprite *movePoint;
	ZeroSprite *tutorialbook;
	DataManager *data;
	Number *money[4];
	Number *date[3];
	Number *potionAccount[8];
	PopUp *pop;
	Potion *potion;
	void Update(float eTime);
	void Render();
	int Dmoney;
	int Ddate;
	int Dhour;
	int potionPos;
	int doublepotionPos;
	int easter;
	float inputDelay;
	bool startwindowRender;
	bool gowindowRender;
	bool canvasRender;
	bool resetrender;
	bool Yesbutton[2];
	bool Nobutton[2];
	bool pointRender;
	bool isClicked;
};

