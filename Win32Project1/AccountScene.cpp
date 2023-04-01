#include "AccountScene.h"

AccountScene::AccountScene()
{
	//ZeroSoundMgr->PushSound("Sound/RestScene.mp3", "RestScene");
	//ZeroSoundMgr->Play("RestScene");
	posX = 330;
	posY = 130;
	Callender = new ZeroSprite("Background/accountSceneBackground.png");
	Callender->SetPos(200, 50);
	background = new ZeroSprite("Background/restBackground(1).png");
	for (int i = 0; i < 32; i++)
	{
		X[i] = new ZeroSprite("Background/X.png");
		X[i]->SetPos(posX, posY);
		if (i == 5)
		{
			posX = 210;
			posY += 100;
		}
		else if (i != 0 && i == 12 || i == 19 || i == 26)
		{
			posX = 210;
			posY += 100;
		}
		else
		{
			posX += 120;
		}
	}
	isClicked = false;
	pop = new PopUp();
	accoutndayrender = false;
	data = new DataManager();
	data->Start();
	dataDate = data->Ddate-1;
	for (int i = 0; i < 2; i++)
	{
		Yesbutton[i] = false;
		Nobutton[i] = false;
	}
	click = false;
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
}

AccountScene::~AccountScene()
{
}

void AccountScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		click = false;
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
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		click = true;
		if (isClicked == false)
		{
			dataDate += 1;
			isClicked = true;
		}
		else if (isClicked == true)
		{
			/*if (data->Ddate != 0 && data->Ddate % 7 == 0)
			{
				accoutndayrender = true;
			}
			else
			{*/
				ZeroSceneMgr->ChangeScene(new RestScene());
				return;
			//}
		}
		/*if (accoutndayrender == true)
		{
			pop->Accept->SetPos(572, 425);
			if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				ZeroSceneMgr->ChangeScene(new MidAccount());
				return;
			}
		}*/
	}
	for (int i = 0; i<2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void AccountScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	Callender->Render();
	for (int j = 0; j < dataDate; j++)
	{
		X[j]->Render();
	}
	/*if (accoutndayrender == true)
	{
		pop->accountWindow->Render();
		pop->Accept->Render();
	}*/
	if (click)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}