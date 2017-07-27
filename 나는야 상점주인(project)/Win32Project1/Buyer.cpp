#include "Buyer.h"
int check = 0;
Buyer::Buyer()
{
	for (int i = 0; i < 10; i++)
	{
		buyer[i] = new ZeroSprite("Resource/buyer/%d.png", i+1);
		buyer[i]->SetPos(50, 200);
		PushScene(buyer[i]);
	}
	perfect = new ZeroSprite("Resource/buyer/Perfect.png");
	perfect->SetPos(50 + buyer[0]->Width(), 200);
	good = new ZeroSprite("Resource/buyer/Good.png");
	good->SetPos(50 + buyer[0]->Width(), 200);
	bad = new ZeroSprite("Resource/buyer/Bad.png");
	bad->SetPos(50 + buyer[0]->Width(), 200);
	bullon = new ZeroSprite("Resource/buyer/bullon.png");
	PushScene(bullon);
	bullon->SetPos(50 + buyer[0]->Width(), 200);
	potion = new Potion();
	spotion = new SPotion();
	for (int i = 0; i < 4; i++)
	{
		num[i] = new Number();
	}
	for (int i = 0; i < 12; i++)
		PotionList[i] = 0;
	data = new DataManager();
	isComed = false;
	goodRender = false;
	perpectRender = false;
	badRender = false;
	delayTime = 0.f;
	who = -1;
	comeTime = 0.f;
	a = 0;
}

Buyer::~Buyer()
{
}

void Buyer::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (delayTime > 0)
		delayTime -= eTime;
	if (delayTime < 0)
		delayTime = 0;
	if (isComed == false)
	{
		if (perpectRender == true || goodRender == true || badRender == true)
		{
			if (resultTime > 2)
			{
				perpectRender = false;
				goodRender = false;
				badRender = false;
				resultTime = 0;
				delayTime = 4.f;
			}
			resultTime += eTime;
		}
		else if (rand() % 500 + 1 < 10 + data->Dfame && delayTime == 0)
		{
			for (int i = 0; i < 12; i++)
				PotionList[i] = 0;
			Order();
			who = rand() % 10;
			delayTime = 0;
			isComed = true;
			data->Dachieve[3] += 1;
			data->Save();
		}
	}
	else
	{
		comeTime += eTime;
		if (comeTime > 15.f)
		{
			isComed = false;
			comeTime = 0;
			resultTime = 0;
			delayTime = 4.f;
			badRender = true;
			data->Dachieve[0] += 1;
			data->Save();
		}
	}
}

void Buyer::Render()
{
	ZeroIScene::Render();
	if (isComed == true)
	{
		buyer[who]->Render();
		bullon->Render();
		for (int i = 0; i < 12; i++)
		{
			if (PotionList[i] != 0)
			{
				if (i < 6)
				{
					potion->small_potion[i]->SetPos(70 + buyer[0]->Width() + a * 100, 230);
					potion->small_potion[i]->Render();
				}
				else
				{
					spotion->small_Spotion[i - 6]->SetPos(70 + buyer[0]->Width() + a * 100, 230);
					spotion->small_Spotion[i - 6]->Render();
				}
				num[a]->number[PotionList[i]]->SetPos(70 + buyer[0]->Width() + a * 100, 320);
				num[a]->number[PotionList[i]]->Render();
				a++;
			}
		}
		a = 0;
	}
	else
	{
		if (perpectRender == true)
			perfect->Render();
		else if (goodRender == true)
			good->Render();
		else if (badRender == true)
			bad->Render();
	}
}

void Buyer::Order()
{
	for (int i = 0; i < 4; i++)
	{
		RandList[i] = rand() % 12;
		for (int j = 1; j < i; j++)
			if (RandList[i] == RandList[j]) i--;
	}
	for (int i = 0; i < 4; i++)
		PotionList[RandList[i]] = rand() % 3 + 1;
}

void Buyer::CheckOrder(int potion[], int spotion[])
{
	data->Start();
	int badd = 0;
	isComed = false;
	resultTime = 0;
	delayTime = 4.f;
	comeTime = 0;
	for (int i = 0; i < 4; i++)
	{
		if (potion[RandList[i]] != PotionList[RandList[i]] || spotion[RandList[i] - 6] != PotionList[RandList[i]])
			badd++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (potion[RandList[i]] == PotionList[RandList[i]])
		{
			data->Dmoney += potion[RandList[i]] * data->pPrice[i];
			switch (RandList[i])
			{
			case 0:
				data->Dpotion1 -= potion[RandList[i]];
				break;
			case 1:
				data->Dpotion2 -= potion[RandList[i]];
				break;
			case 2:
				data->Dpotion3 -= potion[RandList[i]];
				break;
			case 3:
				data->Dpotion4 -= potion[RandList[i]];
				break;
			case 4:
				data->Dpotion5 -= potion[RandList[i]];
				break;
			case 5:
				data->Dpotion6 -= potion[RandList[i]];
				break;
			}
			data->Dachieve[6] += potion[RandList[i]];
			data->Save();
		}
		if (spotion[RandList[i] - 6] == PotionList[RandList[i]])
		{
			data->Dmoney += spotion[RandList[i] - 6] * data->pPrice[i + 6];
			switch (RandList[i] - 6)
			{
			case 0:
				data->Dsp1 -= spotion[RandList[i] - 6];
				break;
			case 1:
				data->Dsp2 -= spotion[RandList[i] - 6];
				break;
			case 2:
				data->Dsp3 -= spotion[RandList[i] - 6];
				break;
			case 3:
				data->Dsp4 -= spotion[RandList[i] - 6];
				break;
			case 4:
				data->Dsp5 -= spotion[RandList[i] - 6];
				break;
			case 5:
				data->Dsp6 -= spotion[RandList[i] - 6];
				break;
			}
			data->Dachieve[5] += spotion[RandList[i] - 6];
			data->Save();
		}
	}
	check = 0;
	if (badd == 0)
	{
		perpectRender = true;
		data->Dachieve[2] += 1;
	}
	else if (badd < 4)
	{
		goodRender = true;
		data->Dachieve[1] += 1;
	}
	else
	{
		badRender = true;
		data->Dachieve[0] += 1;
	}
	data->Save();
}

bool Buyer::checking(int a[])
{
	for (int i = 0; i < 6; i++)
	{
		if (PotionList[RandList[check]] == a[i])
		{
			check++;
			return true;
		}
	}
	return false;
}