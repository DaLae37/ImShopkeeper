#pragma once
#include "ZeroSceneManager.h"
#include "ZeroIScene.h"
#include "DataManager.h"
#include "RestScene.h"
#include "ZeroSprite.h"
#include "Number.h"
#include "Potion.h"
#include "SPotion.h"
#include "PopUp.h"
#include "ZeroSoundManager.h"
class PotionBuy : public ZeroIScene
{
public:
	PotionBuy();
	~PotionBuy();
	void Update(float eTime);
	void Render();
	ZeroSprite *goBack;
	ZeroSprite *back;
	ZeroSprite *next;
	ZeroSprite *before;
	ZeroSprite *cursor[2];
	Potion *potion;
	SPotion *spotion;
	PopUp *pop;
	DataManager *data;
	Number *num[4];
	Number *potionAccount[2];
	Number *potionNum[24];
	int whatpotion;
	int account;
	int potionList[6];
	int a;
	bool b;
	bool isClicked;
	bool accountMan;
	bool gowindowRender;
	bool buywindowRender;
	bool howmanywindowRender;
	bool nomoneywindowRender;
	bool checknomoney;
	bool Acceptbutton[2];
	bool Yesbutton[2];
	bool Nobutton[2];
	ZeroSprite *store1;
	ZeroSprite *store2;
};

