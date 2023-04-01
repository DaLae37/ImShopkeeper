#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#define OVER 0
#define ON 1
#define DOWN 2
class PopUp : public ZeroIScene
{
public:
	PopUp();
	~PopUp();
	void Update(float eTime);
	void Render();
	ZeroSprite *resetWindow;
	ZeroSprite *buyWindow;
	ZeroSprite *moneyCheckWindow;
	ZeroSprite *endWindow;
	ZeroSprite *startWindow;
	ZeroSprite *goWindow;
	ZeroSprite *noticeWindow;
	ZeroSprite *accountWindow;
	ZeroSprite *noMoneyWindow;
	ZeroSprite *howManyWindow;
	ZeroSprite *accountCheckWindow;
	ZeroSprite *Accept;
	ZeroSprite *Yes;
	ZeroSprite *No;
	ZeroSprite *onAccept;
	ZeroSprite *onYes;
	ZeroSprite *onNo;
	ZeroSprite *downAccept;
	ZeroSprite *downYes;
	ZeroSprite *downNo;
	ZeroSprite *Up;
	ZeroSprite *Down;
};

