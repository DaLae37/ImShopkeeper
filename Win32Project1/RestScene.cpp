#include "RestScene.h"

RestScene::RestScene()
{
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
	ShowCursor(false);
	restBackground = new ZeroSprite("Background/restBackground.png");
	for (int i = 0; i < 4; i++)
	{
		potal[i] = new ZeroSprite("Resource/rest/potal.png");
		if (i < 3)
		{
			start[2] = new ZeroSprite("Resource/rest/2.png");
			start[2]->SetPos(840, 70);
			potal[0]->SetPos(810 + start[2]->Width() / 2, 120 + start[2]->Height() / 2);
			//start[i] = new ZeroSprite("Resource/rest/%d.png", i);
			//start[i]->SetPos(840, 70);
			//potal[0]->SetPos(810+start[0]->Width()/2, 120+start[0]->Height()/2);
		}
	}

	back = new ZeroSprite("Resource/rest/Exit.png");
	back->SetPos(155, 370);
	potal[2]->SetPos(240, 605);
	movePoint = new ZeroSprite("Resource/rest/point.png");
	reset = new ZeroSprite("Resource/rest/reset.png");
	reset->SetPos(1150, 600);
	goPotion = new ZeroSprite("Resource/rest/potionPotal.png");
	goPotion->SetPos(484, 40);
	potal[1]->SetPos(570, 280);

	tutorialbook = new ZeroSprite("Resource/rest/tutorialbook.png");
	tutorialbook->SetPos(1190, 100);

	coin = new ZeroSprite("Resource/rest/coin.png");
	coin->SetPos(10, 10);

	sun = new ZeroSprite("Resource/rest/date.png");
	sun->SetPos(10, 100);

	potion = new Potion();
	
	achieveButton = new ZeroSprite("Resource/achieve/Acheive.png");
	achieveButton->SetPos(1190, 20);
	for (int i = 0; i < 4; i++)
	{
		money[i] = new Number();
		money[i]->SetPos(220 - i * 40, 25);
	}
	for (int i = 0; i < 3; i++)
	{
		date[i] = new Number();
		date[i]->SetPos(180 - i * 40, 115);
	}

	data = new DataManager();
	data->Start();
	Dmoney = data->Dmoney;
	Ddate = data->Ddate;
	if (Dmoney > 10000)
	{
		Dmoney = 9999;
	}
	if (Ddate > 1000)
	{
		Ddate = 999;
	}
	startwindowRender = false;
	gowindowRender = false;
	pop = new PopUp();
	for (int i = 0; i < 2; i++)
	{
		Yesbutton[i] = false;
		Nobutton[i] = false;
	}
	clicked = false;
	press = false;
	moving = false;
	canvasRender = true;
	pointRender = false;
	MouseX = 0;
	MouseY = 0;
	angle = 0;
	easter = 0;
	seller = new ZeroSprite("Resource/buyer/seller.png");
	seller->SetPos(600, 500);
}

RestScene::~RestScene()
{

}

void RestScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey('A') == INPUTMGR_KEYDOWN && easter == 0)
		easter++;
	if (ZeroInputMgr->GetKey('B') == INPUTMGR_KEYDOWN && easter == 1)
		easter++;
	if (ZeroInputMgr->GetKey('C') == INPUTMGR_KEYDOWN && easter == 2)
		easter++;
	if (easter == 3)
	{
		ZeroSceneMgr->ChangeScene(new MiniGameScene());
		return;
	}
	if (ZeroInputMgr->GetKey('Y') == INPUTMGR_KEYDOWN)
	{
		switch (canvasRender)
		{
		case false:
			canvasRender = true;
			break;
		case true:
			canvasRender = false;
			break;
		}
	}
	if(moving)
		seller->AddPos(speedX, speedY);
	if (seller->IsOverlapped(movePoint))
	{
		moving = false;
		pointRender = false;
	}
	if (clicked)
	{
		angle = atan2(MouseY - (seller->Pos().y + seller->Height() / 2), MouseX - (seller->Pos().x + seller->Width() / 2));
		speedX = cos(angle) * SPEED;
		speedY = sin(angle) * SPEED;
		moving = true;
		clicked = false;
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN) {
		if (tutorialbook->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new Tutorial());
			return;
		}
	}
	if (ZeroInputMgr->GetKey(VK_RBUTTON) == INPUTMGR_KEYUP)
	{
		clicked = true;
		MouseX = ZeroInputMgr->GetClientPoint().x;
		MouseY = ZeroInputMgr->GetClientPoint().y;
		pointRender = true;
		movePoint->SetPos(MouseX-movePoint->Width()/2, MouseY - movePoint->Height() / 2);
	}
	if (pop->Yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
	{
		Yesbutton[OVER] = true;
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
		{
			Yesbutton[OVER] = false;
			Yesbutton[ON] = true;
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
			Yesbutton[i] = false;
	}
	if (pop->No->IsOverlapped(ZeroInputMgr->GetClientPoint()))
	{
		Nobutton[OVER] = true;
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
		{
			Nobutton[OVER] = false;
			Nobutton[ON] = true;
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
			Nobutton[i] = false;
	}
	
	if (seller->IsOverlapped(potal[0]))
		startwindowRender = true;
	else if (seller->IsOverlapped(potal[1]))
		gowindowRender = true;
	else if (seller->IsOverlapped(potal[2]))
	{
		data->Save();
		ZeroSoundMgr->Stop("RestScene");
		ZeroSceneMgr->ChangeScene(new MainScene());
		return;
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (reset->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			resetrender = true;
		if (achieveButton->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new achieveScene);
			return;
		}
		if (resetrender == true)
		{
			if (pop->Yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				data->Reset();
				resetrender = false;
				ZeroSoundMgr->Stop("RestScene");
				ZeroSceneMgr->ChangeScene(new MainScene());
				return;
			}
			else if (pop->No->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				resetrender = false;
		}
		if (startwindowRender == true)
		{
			if (pop->Yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				startwindowRender = false;
				data->Save();
				ZeroSoundMgr->Stop("RestScene");
				ZeroSceneMgr->ChangeScene(new GameScene());
				return;
			}
			if (pop->No->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				startwindowRender = false;
				seller->SetPos(600, 500);
			}
		}
		if (gowindowRender == true)
		{
			if (pop->Yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				gowindowRender = false;
				data->Save();
				ZeroSceneMgr->ChangeScene(new PotionBuy());
				return;
			}
			if (pop->No->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				gowindowRender = false;
				seller->SetPos(600, 500);
			}
		}
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	for (int i = 0; i < 2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void RestScene::Render()
{
	ZeroIScene::Render();
	restBackground->Render();
	back->Render();
	goPotion->Render();
	reset->Render();
	tutorialbook->Render();
	/*for (int i = 0; i < 4; i++)
	{
		int okay = 0;
		if (data->Dachieve[i] == true)
			okay++;
		if (okay == 4)
			start[2]->Render();
		else if (okay < 2)
			start[1]->Render();
		else
			start[0]->Render();
	}*/
	start[2]->Render();
	for (int i = 0; i < 3; i++)
		potal[i]->Render();
	seller->Render();
	if (pointRender)
		movePoint->Render();
	if (canvasRender)
	{
		coin->Render();
		achieveButton->Render();
		for (int i = 0; i < 4; i++)
		{
			if (i < 3)
				date[i]->Render();
			if (i<4)
				money[i]->Render();
		}
		money[3]->number[Dmoney / 1000]->Render();
		money[2]->number[Dmoney / 100 % 10]->Render();
		money[1]->number[Dmoney / 10 % 10]->Render();
		money[0]->number[Dmoney % 10]->Render();
		sun->Render();
		date[2]->number[Ddate / 100]->Render();
		date[1]->number[Ddate / 10 % 10]->Render();
		date[0]->number[Ddate % 10]->Render();
	}
	if (startwindowRender == true)
	{
		pop->startWindow->Render();
		if (Yesbutton[OVER] == false && Yesbutton[ON] == false)
			pop->Yes->Render();
		else if (Yesbutton[OVER] == true)
			pop->onYes->Render();
		else
			pop->downYes->Render();
		if (Nobutton[OVER] == false && Nobutton[ON] == false)
			pop->No->Render();
		else if (Nobutton[OVER] == true)
			pop->onNo->Render();
		else
			pop->downNo->Render();
	}
	if (gowindowRender == true)
	{
		pop->goWindow->Render();
		if (Yesbutton[OVER] == false && Yesbutton[ON] == false)
			pop->Yes->Render();
		else if (Yesbutton[OVER] == true)
			pop->onYes->Render();
		else
			pop->downYes->Render();
		if (Nobutton[OVER] == false && Nobutton[ON] == false)
			pop->No->Render();
		else if (Nobutton[OVER] == true)
			pop->onNo->Render();
		else
			pop->downNo->Render();
	}
	if (resetrender == true)
	{
		pop->resetWindow->Render();
		if (Yesbutton[OVER] == false && Yesbutton[ON] == false)
			pop->Yes->Render();
		else if (Yesbutton[OVER] == true)
			pop->onYes->Render();
		else
			pop->downYes->Render();
		if (Nobutton[OVER] == false && Nobutton[ON] == false)
			pop->No->Render();
		else if (Nobutton[OVER] == true)
			pop->onNo->Render();
		else
			pop->downNo->Render();
	}
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}