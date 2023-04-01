#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "ZeroAnimation.h"
#include "DataManager.h"
#include "ZeroInputManager.h"
#include "Card.h"
#include "ZeroSoundManager.h"
#include "DataManager.h"
#include "ZeroCameraManager.h"
#include "ZeroSceneManager.h"
#include "MiniGameScene.h"
#include "Number.h"
#include "PopUp.h"
class BlackJack : public ZeroIScene
{
public:
	BlackJack();
	~BlackJack();
	ZeroSprite *board;
	ZeroSprite *coin;
	ZeroSprite *backCard;
	ZeroSprite *cardCap;
	ZeroSprite *bat;
	ZeroSprite *cursor[2];
	PopUp *pop;
	Number *num[4];
	Number *battingmoneynum[4];
	Number *coinnum[4];
	Number *showMyScore[2];
	Number *showYourScore[2];
	Card *myCard[4];
	Card *yourCard[4];
	ZeroSprite *myBack[4];
	ZeroSprite *yourback[4];
	ZeroSprite *Hit;
	ZeroSprite *Hold;
	ZeroSprite *bust;
	ZeroSprite *draww;
	ZeroSprite *win;
	ZeroSprite *lose;
	ZeroSprite *back;
	DataManager *data;
	void Update(float eTime);
	void Render();
	void Overlap();
	void CardSet();
	void Stopped();
	int tool;
	int myCardnum[4];
	int yourCardnum[4];
	int myScore;
	int yourScore;
	int draw;
	int current;
	int battingmoney;
	float MouseY;
	bool finish;
	bool isClicked;
	bool isWin;
	bool bustrender;
	bool winrender;
	bool loserender;
	bool gameStart;
	bool isDrag;
	bool drawrender;
	bool once;
	bool pleaseontime;
	bool isLose;
	bool backrender;
	bool batting;
	bool start;
	bool battingon;
	bool battingmoneyrender;
	bool one;
	bool two;
	bool three;
	bool four;
	bool isHit;
};

