#include "Radio.h"

Radio::Radio()
{
	for (int i = 0; i < 2; i++)
	{
		num[i] = new Number();
		num[i]->SetPos(1020 + i * 40, 550);
	}
	radio = new ZeroSprite("Resource/radio/radio.png");
	PushScene(radio);
	radio->SetPos(830, 450);

	start = new ZeroSprite("Resource/radio/start.png");
	PushScene(start);
	start->SetPos(1030, 605);

	stop = new ZeroSprite("Resource/radio/stop.png");
	PushScene(stop);
	stop->SetPos(1100, 605);

	reset = new ZeroSprite("Resource/radio/reset.png");
	PushScene(reset);
	reset->SetPos(1030, 645);

	next = new ZeroSprite("Resource/radio/next.png");
	PushScene(next);
	next->SetPos(1100, 645);

	ZeroSoundMgr->PushSound("Sound/QueensGarden.mp3", "1");
	ZeroSoundMgr->PushSound("Sound/TotheRiver.mp3", "2");
	ZeroSoundMgr->PushSound("Sound/TobyFox.mp3", "3");
	ZeroSoundMgr->PushSound("Sound/WhenTheMorningComes.mp3", "4");
	ZeroSoundMgr->PushSound("Sound/HopeandDreams.mp3", "5");
	ZeroSoundMgr->PushSound("Sound/DogandPonyShow.mp3", "6");
	ZeroSoundMgr->PushSound("Sound/AtelierRorona.mp3", "7");
	ZeroSoundMgr->PushSound("Sound/Sans.mp3", "8");
	ZeroSoundMgr->PushSound("Sound/21.mp3", "sad1");
	ZeroSoundMgr->PushSound("Sound/comBack.mp3", "sad2");

	sadTime = 0.f;
	nowsadTime = 0;
	isSad = false;
	nowPlay = 1;
	clicked = false;
}

Radio::~Radio()
{
}

void Radio::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (isSad == true)
	{
		sadTime += eTime;
		nowsadTime = sadTime;
		if (sadTime > 30.f)
		{
			if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
			{
				if (start->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					StopRadio();
					StartRadio();
					isSad = false;
					sadTime = 0;
					nowsadTime = 0;
				}
			}
		}
	}
	else if (isSad == false)
	{
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
		{
			if (start->IsOverlapped(ZeroInputMgr->GetClientPoint()) && clicked == false)
			{
				StartRadio();
			}
			if (stop->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				StopRadio();
			}
			if (reset->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				ResetRadio();
			}
			if (next->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				if (rand() % 10 + 1 == 1)
				{
					Sad();
				}
				else
				{
					NextRadio();
				}
			}
		}
	}
}

void Radio::Render()
{
	ZeroIScene::Render();
	radio->Render();
	start->Render();
	stop->Render();
	reset->Render();
	next->Render();
	for (int i = 0; i < 2; i++)
	{
		num[i]->Render();
	}
	num[0]->number[nowsadTime / 10]->Render();
	num[1]->number[nowsadTime % 10]->Render();
}

void Radio::Sad()
{
	if (rand() % 10 + 1  < 4)
	{
		StopRadio();
		ZeroSoundMgr->Play("sad1");
		nowPlay = 11;
	}
	else
	{
		StopRadio();
		ZeroSoundMgr->Play("sad2");
		nowPlay = 12;
	}
	isSad = true;
}

void Radio::StartRadio()
{
	if (nowPlay == 1)
	{
		ZeroSoundMgr->Play("1");
	}
	if (nowPlay == 2)
	{
		ZeroSoundMgr->Play("2");
	}
	if (nowPlay == 3)
	{
		ZeroSoundMgr->Play("3");
	}
	if (nowPlay == 4)
	{
		ZeroSoundMgr->Play("4");
	}
	if (nowPlay == 5)
	{
		ZeroSoundMgr->Play("5");
	}
	if (nowPlay == 6)
	{
		ZeroSoundMgr->Play("6");
	}
	if (nowPlay == 7)
	{
		ZeroSoundMgr->Play("7");
	}
	if (nowPlay == 8)
	{
		ZeroSoundMgr->Play("8");
	}
	if (nowPlay > 10)
	{
		ZeroSoundMgr->Play("1");
		nowPlay = 1;
	}
	clicked = true;
}

void Radio::StopRadio()
{
	if (nowPlay == 1)
	{
		ZeroSoundMgr->Stop("1");
	}
	if (nowPlay == 2)
	{
		ZeroSoundMgr->Stop("2");
	}
	if (nowPlay == 3)
	{
		ZeroSoundMgr->Stop("3");
	}
	if (nowPlay == 4)
	{
		ZeroSoundMgr->Stop("4");
	}
	if (nowPlay == 5)
	{
		ZeroSoundMgr->Stop("5");
	}
	if (nowPlay == 6)
	{
		ZeroSoundMgr->Stop("6");
	}
	if (nowPlay == 7)
	{
		ZeroSoundMgr->Stop("7");
	}
	if (nowPlay == 8)
	{
		ZeroSoundMgr->Stop("8");
	}
	if (nowPlay == 11)
	{
		ZeroSoundMgr->Stop("sad1");
	}
	if (nowPlay == 12)
	{
		ZeroSoundMgr->Stop("sad2");
	}
	clicked = false;
}

void Radio::ResetRadio()
{
	if (nowPlay == 1)
	{
		ZeroSoundMgr->Reset("1");
	}
	if (nowPlay == 2)
	{
		ZeroSoundMgr->Reset("2");
	}
	if (nowPlay == 3)
	{
		ZeroSoundMgr->Reset("3");
	}
	if (nowPlay == 4)
	{
		ZeroSoundMgr->Reset("4");
	}
	if (nowPlay == 5)
	{
		ZeroSoundMgr->Reset("5");
	}
	if (nowPlay == 6)
	{
		ZeroSoundMgr->Reset("6");
	}
	if (nowPlay == 7)
	{
		ZeroSoundMgr->Reset("7");
	}
	if (nowPlay == 8)
	{
		ZeroSoundMgr->Reset("8");
	}
}

void Radio::NextRadio()
{
	if (nowPlay == 1)
	{
		ZeroSoundMgr->Stop("1");
		ZeroSoundMgr->Play("2");
		nowPlay = 2;
	}
	else if (nowPlay == 2)
	{
		ZeroSoundMgr->Stop("2");
		ZeroSoundMgr->Play("3");
		nowPlay = 3;
	}
	else if (nowPlay == 3)
	{
		ZeroSoundMgr->Stop("3");
		ZeroSoundMgr->Play("4");
		nowPlay = 4;
	}
	else if (nowPlay == 4)
	{
		ZeroSoundMgr->Stop("4");
		ZeroSoundMgr->Play("5");
		nowPlay = 5;
	}
	else if (nowPlay == 5)
	{
		ZeroSoundMgr->Stop("5");
		ZeroSoundMgr->Play("6");
		nowPlay = 6;
	}
	else if (nowPlay == 6)
	{
		ZeroSoundMgr->Stop("6");
		ZeroSoundMgr->Play("7");
		nowPlay = 7;
	}
	else if (nowPlay == 7)
	{
		ZeroSoundMgr->Stop("7");
		ZeroSoundMgr->Play("8");
		nowPlay = 8;
	}
	else if (nowPlay == 8)
	{
		ZeroSoundMgr->Stop("8");
		ZeroSoundMgr->Play("1");
		nowPlay = 1;
	}
}