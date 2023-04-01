#include "MiniGameScene.h"

MiniGameScene::MiniGameScene()
{
	background = new ZeroSprite("Background/restBackground.png");

	back = new ZeroSprite("Background/back.png");
	back->SetPos(10, 650);

	comming = new ZeroSprite("Background/commingsoon.png");
	comming->SetPos(800, 10);

	cardGameButton = new ZeroSprite("Background/cardGameButton.png");
	cardGameButton->SetPos(100, 10);

	ZeroSoundMgr->PushSound("Sound/MiniGame.mp3", "Mini");
	ZeroSoundMgr->Play("Mini");
	back->SetScale(0.5);
	ShowCursor(false);
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
	isClicked = false;
}

MiniGameScene::~MiniGameScene()
{
}

void MiniGameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (cardGameButton->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSoundMgr->Stop("Mini");
			ZeroSceneMgr->ChangeScene(new BlackJack());
			return;
		}
		if (back->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSoundMgr->Stop("Mini");
			ZeroSceneMgr->ChangeScene(new RestScene());
			return;
		}
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	for (int i = 0; i<2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void MiniGameScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	back->Render();
	cardGameButton->Render();
	comming->Render();
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}