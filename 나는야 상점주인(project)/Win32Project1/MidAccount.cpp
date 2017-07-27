#include "MidAccount.h"

MidAccount::MidAccount()
{
	background = new ZeroSprite("Background/restBackground.png");
	Pop = new ZeroSprite("Background/midAccount.png");
	Pop->SetPos(150, 70);
	for (int i = 0; i < 4; i++)
	{
		money[i] = new Number();
		money[i]->AddScale(0.3);
		money[i]->SetPos(400 + i * 40, 300);
		goalmoney[i] = new Number();
		goalmoney[i]->SetPos(850 + i * 40, 300);
		goalmoney[i]->AddScale(0.3);
	}
	for (int i = 0; i < 2; i++)
	{
		day[i] = new Number();
		day[i]->SetPos(560 + i*40, 110);
		day[i]->AddScale(0.2);
	}
	data = new DataManager();
	delay = 0.f;
	isDelay = true;
}

MidAccount::~MidAccount()
{
}

void MidAccount::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (isDelay == true)
	{
		delay += eTime;
		if (delay > 3.f)
		{
			isDelay = false;
		}
	}
	else
	{
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		{
			ZeroSceneMgr->ChangeScene(new RestScene());
			return;
		}
	}
}

void MidAccount::Render()
{
	ZeroIScene::Render();
	background->Render();
	Pop->Render();
	for (int i = 0; i < 4; i++)
	{
		money[i]->Render();
		goalmoney[i]->Render();
	}
	day[0]->Render();
	day[0]->number[data->Ddate / 10]->Render();
	day[1]->Render();
	day[1]->number[data->Ddate % 10]->Render();
	money[0]->number[data->Dmoney/1000]->Render();
	money[1]->number[data->Dmoney / 100 % 10]->Render();
	money[2]->number[data->Dmoney / 10 % 10]->Render();
	money[3]->number[data->Dmoney % 10]->Render();
	goalmoney[0]->number[7]->Render();
	goalmoney[1]->number[7]->Render();
	goalmoney[2]->number[7]->Render();
	goalmoney[3]->number[7]->Render();
}