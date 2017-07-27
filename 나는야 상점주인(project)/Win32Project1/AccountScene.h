#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "DataManager.h"
#include "RestScene.h"
#include "ZeroInputManager.h"
#include "ZeroSceneManager.h"
//#include "MidAccount.h"
#include "PopUp.h"
#include "ZeroSoundManager.h"
class AccountScene : public ZeroIScene
{
public:
	AccountScene();
	~AccountScene();
	void Update(float eTime);
	void Render();
	ZeroSprite *background;
	ZeroSprite *Callender;
	ZeroSprite *X[31];
	DataManager *data;
	ZeroSprite *cursor[2];
	PopUp *pop;
	bool isClicked;
	bool accoutndayrender;
	bool Yesbutton[2];
	bool Nobutton[2];
	bool click;
	int posX;
	int posY;
	int dataDate;
};

