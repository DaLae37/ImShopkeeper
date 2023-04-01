#include "PotionBuy.h"

PotionBuy::PotionBuy()
{
	store1 = new ZeroSprite("Background/store1.png");
	store2 = new ZeroSprite("Background/store2.png");
	potion = new Potion();
	spotion = new SPotion();
	for (int i = 0; i < 24; i++)
	{
		potionNum[i] = new Number();
		if (i < 4)
		{
			num[i] = new Number();
			num[i]->SetPos(450 + i * 40, 400);
		}
	}
	potion->potion[0]->SetPos(100, 0);
	potion->potion[1]->SetPos(100, 200);
	potion->potion[2]->SetPos(100, 400);
	potion->potion[3]->SetPos(650, 0);
	potion->potion[4]->SetPos(650, 200);
	potion->potion[5]->SetPos(650, 400);

	spotion->Spotion[0]->SetPos(100, 0);
	spotion->Spotion[1]->SetPos(100, 200);
	spotion->Spotion[2]->SetPos(100, 400);
	spotion->Spotion[3]->SetPos(650, 0);
	spotion->Spotion[4]->SetPos(650, 200);
	spotion->Spotion[5]->SetPos(650, 400);

	potionAccount[0] = new Number();
	potionAccount[1] = new Number();
	potionAccount[0]->SetPos(470, 330);
	potionAccount[1]->SetPos(510, 330);

	goBack = new ZeroSprite("Background/back.png");
	goBack->SetPos(10, 600);
	goBack->SetScale(0.7, 0.7);

	back = new ZeroSprite("Background/store1.png");
	pop = new PopUp();

	data = new DataManager();
	next = new ZeroSprite("Resource/achieve/next.png");
	before = new ZeroSprite("Resource/achieve/before.png");
	next->SetPos(1200, 350);
	before->SetPos(10, 350);
	pop->Up->SetPos(800, 280);
	pop->Down->SetPos(800, 380);
	gowindowRender = false;
	buywindowRender = false;
	howmanywindowRender = false;
	nomoneywindowRender = false;
	checknomoney = false;
	accountMan = false;
	whatpotion = -1;
	a = 0;
	b = true;
	account = 0;
	ShowCursor(false);
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
	isClicked = false;
}

PotionBuy::~PotionBuy()
{
}

void PotionBuy::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	potionNum[0]->number[data->Dpotion1 / 10]->SetPos(150, 100);
	potionNum[1]->number[data->Dpotion1 % 10]->SetPos(190, 100);
	potionNum[2]->number[data->Dpotion2 / 10]->SetPos(150, 300);
	potionNum[3]->number[data->Dpotion2 % 10]->SetPos(190, 300);
	potionNum[4]->number[data->Dpotion3 / 10]->SetPos(150, 500);
	potionNum[5]->number[data->Dpotion3 % 10]->SetPos(190, 500);
	potionNum[6]->number[data->Dpotion4 / 10]->SetPos(700, 100);
	potionNum[7]->number[data->Dpotion4 % 10]->SetPos(740, 100);
	potionNum[8]->number[data->Dpotion5 / 10]->SetPos(700, 300);
	potionNum[9]->number[data->Dpotion5 % 10]->SetPos(740, 300);
	potionNum[10]->number[data->Dpotion6 / 10]->SetPos(700, 500);
	potionNum[11]->number[data->Dpotion6 % 10]->SetPos(740, 500);

	potionNum[12]->number[data->Dsp1 / 10]->SetPos(150, 100);
	potionNum[13]->number[data->Dsp1 % 10]->SetPos(190, 100);
	potionNum[14]->number[data->Dsp2 / 10]->SetPos(150, 300);
	potionNum[15]->number[data->Dsp2 % 10]->SetPos(190, 300);
	potionNum[16]->number[data->Dsp3 / 10]->SetPos(150, 500);
	potionNum[17]->number[data->Dsp3  % 10]->SetPos(190, 500);
	potionNum[18]->number[data->Dsp4 / 10]->SetPos(700, 100);
	potionNum[19]->number[data->Dsp4  % 10]->SetPos(740, 100);
	potionNum[20]->number[data->Dsp5 / 10]->SetPos(700, 300);
	potionNum[21]->number[data->Dsp5 % 10]->SetPos(740, 300);
	potionNum[22]->number[data->Dsp6 / 10]->SetPos(700, 500);
	potionNum[23]->number[data->Dsp6 % 10]->SetPos(740, 500);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (howmanywindowRender == false && nomoneywindowRender == false && buywindowRender == false)
		{
			if (next->IsOverlapped(ZeroInputMgr->GetClientPoint()) || before->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				switch (b)
				{
				case true:
					b = false;
					break;
				case false:
					b = true;
					break;
				}
			}
			for (int i = 0; i < 6; i++)
			{
				if (b)
				{
					if (potion->potion[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
					{
						switch (i)
						{
						case 0:
							whatpotion = 0;
							break;
						case 1:
							whatpotion = 1;
							break;
						case 2:
							whatpotion = 2;
							break;
						case 3:
							whatpotion = 3;
							break;
						case 4:
							whatpotion = 4;
							break;
						case 5:
							whatpotion = 5;
							break;
						default:
							break;
						}
						howmanywindowRender = true;
					}
				}
				else
				{
					if (spotion->Spotion[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()))
					{
						switch (i)
						{
						case 0:
							whatpotion = 6;
							break;
						case 1:
							whatpotion = 7;
							break;
						case 2:
							whatpotion = 8;
							break;
						case 3:
							whatpotion = 9;
							break;
						case 4:
							whatpotion = 10;
							break;
						case 5:
							whatpotion = 11;
							break;
						default:
							break;
						}
						howmanywindowRender = true;
					}
				}
			}
		}
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
	if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
	{
		Acceptbutton[OVER] = true;
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
		{
			Acceptbutton[OVER] = false;
			Acceptbutton[ON] = true;
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
			Acceptbutton[i] = false;
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		isClicked = false;
		if (goBack->IsOverlapped(ZeroInputMgr->GetClientPoint()) && gowindowRender == false)
			gowindowRender = true;
		if (gowindowRender == true)
		{
			if (pop->Yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				gowindowRender = false;
				data->Save();
				ZeroSceneMgr->ChangeScene(new RestScene());
				return;
			}
			if (pop->No->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				gowindowRender = false;
		}
		if (nomoneywindowRender == true)
		{
			if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				nomoneywindowRender = false;
		}
		if (howmanywindowRender == true)
		{
			if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				howmanywindowRender = false;
				if (data->Dmoney - a < 0)
					nomoneywindowRender = true;
				else
					buywindowRender = true;
			}
			else if (pop->Up->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				if (account+1 < 100 && accountMan == false)
					account++;
			}
			else if (pop->Down->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				if (account-1 > 0)
				{
					account--;
					if (accountMan == true)
						accountMan = false;
				}
			}
			a = data->pPrice[whatpotion] * account;
		}
		if (buywindowRender == true)
		{
			if (pop->Yes->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				switch (whatpotion)
				{
				case 0:
					data->Dpotion1 += account;
					break;
				case 1:
					data->Dpotion2 += account;
					break;
				case 2:
					data->Dpotion3 += account;
					break;
				case 3:
					data->Dpotion4 += account;
					break;
				case 4:
					data->Dpotion5 += account;
					break;
				case 5:
					data->Dpotion6 += account;
					break;
				case 6:
					data->Dsp1 += account;
					break;
				case 7:
					data->Dsp2 += account;
					break;
				case 8:
					data->Dsp3 += account;
					break;
				case 9:
					data->Dsp4 += account;
					break;
				case 10:
					data->Dsp5 += account;
					break;
				case 11:
					data->Dsp6 += account;
					break;

				}
				account = 0;
				data->Dmoney -= a;
				buywindowRender = false;
				data->Save();
				data->Start();
			}
			else if (pop->No->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				buywindowRender = false;
		}
	}
	for (int i = 0; i<2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void PotionBuy::Render()
{
	ZeroIScene::Render();
	if(b)
		store1->Render();
	else
		store2->Render();
	pop->Render();
	potionAccount[0]->Render();
	potionAccount[1]->Render();
	for (int i = 0; i < 6; i++)
	{
		if (i<4)
			num[i]->Render();
		if (b)
		{
			potion->potion[i]->Render();
			next->Render();
		}
		else
		{
			spotion->Spotion[i]->Render();
			before->Render();
		}
	}
	potionNum[0]->number[data->Dpotion1 / 10]->Render();
	potionNum[1]->number[data->Dpotion1 % 10]->Render();
	potionNum[2]->number[data->Dpotion2 / 10]->Render();
	potionNum[3]->number[data->Dpotion2 % 10]->Render();
	potionNum[4]->number[data->Dpotion3 / 10]->Render();
	potionNum[5]->number[data->Dpotion3 % 10]->Render();
	potionNum[6]->number[data->Dpotion4 / 10]->Render();
	potionNum[7]->number[data->Dpotion4 % 10]->Render();
	potionNum[8]->number[data->Dpotion5 / 10]->Render();
	potionNum[9]->number[data->Dpotion5 % 10]->Render();
	potionNum[10]->number[data->Dpotion6 / 10]->Render();
	potionNum[11]->number[data->Dpotion6 % 10]->Render();

	potionNum[12]->number[data->Dsp1 / 10]->Render();
	potionNum[13]->number[data->Dsp1 % 10]->Render();
	potionNum[14]->number[data->Dsp2 / 10]->Render();
	potionNum[15]->number[data->Dsp2 % 10]->Render();
	potionNum[16]->number[data->Dsp3 / 10]->Render();
	potionNum[17]->number[data->Dsp3 % 10]->Render();
	potionNum[18]->number[data->Dsp4 / 10]->Render();
	potionNum[19]->number[data->Dsp4 % 10]->Render();
	potionNum[20]->number[data->Dsp5 / 10]->Render();
	potionNum[21]->number[data->Dsp5 % 10]->Render();
	potionNum[22]->number[data->Dsp6 / 10]->Render();
	potionNum[23]->number[data->Dsp6 % 10]->Render();
	goBack->Render();
	if (nomoneywindowRender == true)
	{
		pop->noMoneyWindow->Render();
		pop->Accept->SetPos(590, 435);
		pop->onAccept->SetPos(590, 435);
		if (Acceptbutton[OVER] == false && Acceptbutton[ON] == false)
			pop->Accept->Render();
		else if (Acceptbutton[OVER] == true)
			pop->onAccept->Render();
		else
			pop->downAccept->Render();
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
	if (howmanywindowRender == true)
	{
		pop->howManyWindow->Render();
		pop->Accept->SetPos(750,470);
		pop->onAccept->SetPos(750,470);
		if (Acceptbutton[OVER] == false && Acceptbutton[ON] == false)
			pop->Accept->Render();
		else if (Acceptbutton[OVER] == true)
			pop->onAccept->Render();
		else
			pop->downAccept->Render();
		pop->Up->Render();
		pop->Down->Render();
		if (a > 9999)
		{
			accountMan = true;
		}
		num[0]->number[a / 1000]->Render();
		num[1]->number[a / 100 % 10]->Render();
		num[2]->number[a / 10 % 10]->Render();
		num[3]->number[a % 10]->Render();
		potionAccount[0]->number[account / 10]->Render();
		potionAccount[1]->number[account % 10]->Render();
	}
	if (buywindowRender == true)
	{
		pop->buyWindow->Render();
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