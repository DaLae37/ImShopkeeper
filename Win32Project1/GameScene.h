#pragma once
#include "ZeroIScene.h"
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
#include "AccountScene.h"
#include "Number.h"
#include "DataManager.h"
#include "Buyer.h"
#include "Potion.h"
#include "PopUp.h"
//#include "Radio.h"
#include "SPotion.h"
#include "Background.h"
#include <ZeroSprite.h>

class GameScene : public ZeroIScene
{
public:
	GameScene();
	~GameScene();
	void Update(float eTime);
	void Render();
	void PotionSell();
	void PotionClicking();
	ZeroSprite *sell;
	ZeroSprite *coin;
	ZeroSprite *inGame;
	ZeroSprite *endGame;
	ZeroSprite *changep;
	ZeroSprite *changesp;
	Potion *potion;
	Potion *movePotion;
	SPotion *spotion;
	SPotion *movesPotion;
	Buyer *buyer;
	//Radio *radio;
	DataManager *data;
	Background *back;
	Number *Nhour[2];
	Number *Nminute[2];
	Number *Potion1num[2];
	Number *Potion2num[2];
	Number *Potion3num[2];
	Number *Potion4num[2];
	Number *Potion5num[2];
	Number *Potion6num[2];
	Number *sp1num[2];
	Number *sp2num[2];
	Number *sp3num[2];
	Number *sp4num[2];
	Number *sp5num[2];
	Number *sp6num[2];
	Number *accountCheck;
	Number *money[4];
	PopUp *pop;
	float opentoclose;
	float toclosetime;
	int hour;
	int minute;
	int what;
	int potionSellingAccount[6];
	int spotionSellingAccount[6];
	int whatAccount;
	bool isClick;
	bool isComed;
	bool noticewindowRender;
	bool accountcheckwindowRender;
	bool loading;
	bool Acceptbutton[2];
	bool p;
	bool sp;
	bool isClicked;
	ZeroSprite *cursor[2];
};

