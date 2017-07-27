#include "MainScene.h"
#include <iostream>
using namespace std;
MainScene::MainScene()
{
	mainBackground = new ZeroSprite("Background/mainBackground.png");
	PushScene(mainBackground);

	startGame = new ZeroSprite("Background/startGame.png");
	PushScene(startGame);
	startGame->SetPos(850, 200);
	startGame->SetScale(0.7);
	onstartGame = new ZeroSprite("Background/onstartGame.png");
	endGame = new ZeroSprite("Background/endGame.png");
	onendGame = new ZeroSprite("Background/onendGame.png");
	onstartGame->SetScale(0.7);
	PushScene(endGame);
	endGame->SetPos(850, 340);
	endGame->SetScale(0.7);
	onstartGame->SetPos(850, 200);
	onendGame->SetScale(0.7);
	onendGame->SetPos(850, 340);
	//data = new DataManager();
	for (int i = 0; i < 2; i++)
		press[i] = false;
	//ZeroSoundMgr->PushSound("Sound/mapleLogin.mp3", "main");
	//ZeroSoundMgr->Play("main");
	ShowCursor(false);
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
}

MainScene::~MainScene()
{
}

void MainScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		isClicked = false;
		if (onstartGame->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new AccountScene());
			ZeroSoundMgr->Stop("main");
			return;
		}
		else if (onendGame->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			PostQuitMessage(0);
		press[0] = false;
		press[1] = false;
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (startGame->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			press[0] = true;
		else if (endGame->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			press[1] = true;
	}	
	for (int i = 0; i < 2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void MainScene::Render()
{
	ZeroIScene::Render();
	mainBackground->Render();
	if (press[0])
		onstartGame->Render();
	else
		startGame->Render();
	if (press[1])
		onendGame->Render();
	else
		endGame->Render();
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}