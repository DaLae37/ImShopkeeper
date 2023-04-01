#include "Background.h"

Background::Background()
{
	gameBackground = new ZeroSprite("Background/gameBackground.png");
	gameBackground->SetPos(890, 81);
	gameBackground1 = new ZeroSprite("Background/gameBackground1.png");
	gameBackground1->SetPos(890, 81);
	PushScene(gameBackground);
	//ZeroCameraMgr->SetCameraOn();
	//ZeroCameraMgr->SetTarget(stand);
	//ZeroCameraMgr->SetSpeed(0);
	//ZeroCameraMgr->SetScreen(100, 100);
	stand = new ZeroSprite("Background/stand.png");
	stand->SetPos(0, 465);
	colon = new ZeroSprite("Background/colon.png");
	PushScene(colon);
	colon->SetPos(110, 30);
}

Background::~Background()
{
}

void Background::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Background::Render()
{
	ZeroIScene::Render();
}