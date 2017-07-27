#include "achieveScene.h"

achieveScene::achieveScene()
{
	back = new ZeroSprite("Background/back.png");
	back->SetPos(0, 600);
	back->SetScale(0.7, 0.7);
	background = new ZeroSprite("Background/restBackground(1).png");
	next = new ZeroSprite("Resource/achieve/next.png");
	before = new ZeroSprite("Resource/achieve/before.png");
	next->SetPos(1200, 350);
	before->SetPos(10, 350);
	for (int i = 0; i < 12; i++)
	{
		achieveList[i] = new ZeroSprite("Resource/achieve/%d.png", i);
		achieveEx[i] = new ZeroSprite("Resource/achieve/a%d.png", i);
		if (i < 6)
		{
			if (i % 2 == 0)
			{
				achieveList[i]->SetPos(100, 10 + i / 2 * 200);
				achieveEx[i]->SetPos(250, 20 + i / 2 * 200);
			}
			else
			{
				achieveList[i]->SetPos(650, 10 + i / 2 * 200);
				achieveEx[i]->SetPos(800, 20 + i / 2 * 200);
			}
		}
		else
		{
			if (i % 2 == 0)
			{
				achieveList[i]->SetPos(100, 10 + (i - 6) / 2 * 200);
				achieveEx[i]->SetPos(250, 20 + (i - 6) / 2 * 200);
			}
			else
			{
				achieveList[i]->SetPos(650, 10 + (i - 6) / 2 * 200);
				achieveEx[i]->SetPos(800, 20 + (i - 6) / 2 * 200);
			}
		}

	}
	scene = true;
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
}

achieveScene::~achieveScene()
{
}

void achieveScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (back->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			ZeroSceneMgr->ChangeScene(new RestScene());
			return;
		}
		if (next->IsOverlapped(ZeroInputMgr->GetClientPoint()) || before->IsOverlapped(ZeroInputMgr->GetClientPoint()))
		{
			switch (scene)
			{
			case true:
				scene = false;
				break;
			case false:
				scene = true;
				break;
			}
		}
	}
	for (int i = 0; i<2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void achieveScene::Render()
{
	ZeroIScene::Render();
	background->Render();
	for (int i = 0; i < 6; i++)
	{
		if (scene)
		{
			achieveList[i]->Render();
			achieveEx[i]->Render();
			next->Render();
		}
		else
		{
			achieveList[i + 6]->Render();
			achieveEx[i + 6]->Render();
			before->Render();
		}
	}
	back->Render();
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}