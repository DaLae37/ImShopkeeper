#include "GameScene.h"

GameScene::GameScene()
{
	isClicked = false;
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
	loading = false;
	data = new DataManager();
	data->Start();
	coin = new ZeroSprite("Resource/rest/coin.png");
	for (int i = 0; i < 4; i++)
	{
		money[i] = new Number();
		money[i]->SetPos(300 + i * 40, 30);
	}
	coin->SetPos(465, 10);
	back = new Background();

	//radio = new Radio();
	
	changep = new ZeroSprite("Background/p.png");
	changep->SetPos(890, 0);
	changesp = new ZeroSprite("Background/sp.png");
	changesp->SetPos(1085, 0);

	inGame = new ZeroSprite("Background/inBack.png");
	//inGame->SetScalingCenter(inGame->Width() / 2, inGame->Height() / 2);
	//inGame->AddScale(0.07);
	//inGame->SetPos(42,23);

	endGame = new ZeroSprite("Background/endButton.png");
	endGame->SetPos(650, 10);
	endGame->SetScale(0.5);

	pop = new PopUp();

	accountCheck = new Number();

	potion = new Potion();
	potion->potion[0]->SetPos(930, 130);
	potion->potion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
	potion->potion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
	potion->potion[3]->SetPos(930, 350);
	potion->potion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
	potion->potion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);

	movePotion = new Potion();
	movePotion->potion[0]->SetPos(930, 130);
	movePotion->potion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
	movePotion->potion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
	movePotion->potion[3]->SetPos(930, 350);
	movePotion->potion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
	movePotion->potion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);

	spotion = new SPotion();
	spotion->Spotion[0]->SetPos(930, 130);
	spotion->Spotion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
	spotion->Spotion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
	spotion->Spotion[3]->SetPos(930, 350);
	spotion->Spotion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
	spotion->Spotion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);

	movesPotion = new SPotion();
	movesPotion->Spotion[0]->SetPos(930, 130);
	movesPotion->Spotion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
	movesPotion->Spotion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
	movesPotion->Spotion[3]->SetPos(930, 350);
	movesPotion->Spotion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
	movesPotion->Spotion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);

	buyer = new Buyer();
	
	sell = new ZeroSprite("Background/sell.png");
	sell->SetPos(750, 460);


	for (int i = 0; i < 6; i++)
	{
		potionSellingAccount[i] = 1;
		spotionSellingAccount[i] = 1;
	}
	for (int i = 0; i < 2; i++)
	{
		Nhour[i] = new Number();
		Nhour[i]->SetPos(30 + i * 40, 30);
		Nminute[i] = new Number();
		Nminute[i]->SetPos(115 + i * 40, 30);
		Potion1num[i] = new Number();
		Potion1num[i]->SetPos(930+i*40, 230);
		Potion2num[i] = new Number();
		Potion2num[i]->SetPos(950 +potion->potion[0]->Width()+ i * 40, 230);
		Potion3num[i] = new Number();
		Potion3num[i]->SetPos(970 + 2 * potion->potion[0]->Width() + i * 40, 230);
		Potion4num[i] = new Number();
		Potion4num[i]->SetPos(930 + i * 40, 450);
		Potion5num[i] = new Number();
		Potion5num[i]->SetPos(950 + potion->potion[0]->Width() + i * 40, 450);
		Potion6num[i] = new Number();
		Potion6num[i]->SetPos(970 + 2 * potion->potion[0]->Width() + i * 40, 450);
		sp1num[i] = new Number();
		sp1num[i]->SetPos(930 + i * 40, 230);
		sp2num[i] = new Number();
		sp2num[i]->SetPos(950 + potion->potion[0]->Width() + i * 40, 230);
		sp3num[i] = new Number();
		sp3num[i]->SetPos(970 + 2 * potion->potion[0]->Width() + i * 40, 230);
		sp4num[i] = new Number();
		sp4num[i]->SetPos(930 + i * 40, 450);
		sp5num[i] = new Number();
		sp5num[i]->SetPos(950 + potion->potion[0]->Width() + i * 40, 450);
		sp6num[i] = new Number();
		sp6num[i]->SetPos(970 + 2 * potion->potion[0]->Width() + i * 40, 450);

		Acceptbutton[i] = false;
	}
	p = true;
	sp = false;
	toclosetime = 0;
	opentoclose = 0.f;
	hour = 10;
	minute = 0;
	what = -1;
	isClick = false;
	isComed = false;
	accountcheckwindowRender = false;
	noticewindowRender = false;
	PotionSell();
	loading = true;
}

GameScene::~GameScene()
{
}

void GameScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
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
	/*if (radio->isSad == false)
	{
		buyer->Update(eTime);
	}
	radio->Update(eTime);*/
	if (noticewindowRender == false)
	{
		opentoclose += eTime;
		toclosetime += eTime;
		minute = opentoclose;
		if (minute + 1 > 12.f)
		{
			opentoclose = 0.f;
			minute = 0;
			hour += 1;
		}
		if (toclosetime > 120.f)
			noticewindowRender = true;
	}
	if (buyer->isComed == true && isComed == false)
	{
		movePotion->potion[0]->SetPos(930, 130);
		movePotion->potion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
		movePotion->potion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
		movePotion->potion[3]->SetPos(930, 350);
		movePotion->potion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
		movePotion->potion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);
		isComed = true;
	}
	if (buyer->isComed == false)
		isComed = false;
	if (ZeroInputMgr->GetKey(VK_RBUTTON) == INPUTMGR_KEYDOWN)
	{
		for (int i = 0; i < 6; i++)
		{
			if (movePotion->potion[i]->IsOverlapped(back->stand) && movePotion->potion[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && accountcheckwindowRender == false)
			{
				accountcheckwindowRender = true;
				whatAccount = i;
			}
			else if (movesPotion->Spotion[i]->IsOverlapped(back->stand) && movesPotion->Spotion[i]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && accountcheckwindowRender == false)
			{
				accountcheckwindowRender = true;
				whatAccount = 10 + i;
			}
		}
	}

	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
	{
		isClicked = true;
		if (sell->IsOverlapped(ZeroInputMgr->GetClientPoint()) && buyer->isComed == true)
			PotionSell();
		if (changep->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			p = true;
		else if (changesp->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			p = false;
		if (endGame->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			noticewindowRender = true;
		if (accountcheckwindowRender == true)
		{
			if (whatAccount < 10)
			{
				if (pop->Up->IsOverlapped(ZeroInputMgr->GetClientPoint()) && potionSellingAccount[whatAccount] + 1 <= 9)
				{
					if (whatAccount == 0 && data->Dpotion1 > potionSellingAccount[0])
						potionSellingAccount[whatAccount] += 1;
					if (whatAccount == 1 && data->Dpotion2 > potionSellingAccount[1])
						potionSellingAccount[whatAccount] += 1;
					if (whatAccount == 2 && data->Dpotion3 > potionSellingAccount[2])
						potionSellingAccount[whatAccount] += 1;
					if (whatAccount == 3 && data->Dpotion4 > potionSellingAccount[3])
						potionSellingAccount[whatAccount] += 1;
					if (whatAccount == 4 && data->Dpotion5 > potionSellingAccount[4])
						potionSellingAccount[whatAccount] += 1;
					if (whatAccount == 5 && data->Dpotion6 > potionSellingAccount[5])
						potionSellingAccount[whatAccount] += 1;
				}
				else if (pop->Down->IsOverlapped(ZeroInputMgr->GetClientPoint()) && potionSellingAccount[whatAccount] - 1 >= 1)
					potionSellingAccount[whatAccount] -= 1;
			}
			else
			{
				if (pop->Up->IsOverlapped(ZeroInputMgr->GetClientPoint()) && spotionSellingAccount[whatAccount - 10] + 1 <= 9)
				{
					if (whatAccount == 10 && data->Dsp1 > spotionSellingAccount[0])
						spotionSellingAccount[whatAccount - 10] += 1;
					if (whatAccount == 11 && data->Dsp2 > spotionSellingAccount[1])
						spotionSellingAccount[whatAccount - 10] += 1;
					if (whatAccount == 12 && data->Dsp3 > spotionSellingAccount[2])
						spotionSellingAccount[whatAccount - 10] += 1;
					if (whatAccount == 13 && data->Dsp4 > spotionSellingAccount[3])
						spotionSellingAccount[whatAccount - 10] += 1;
					if (whatAccount == 14 && data->Dsp5 > spotionSellingAccount[4])
						spotionSellingAccount[whatAccount - 10] += 1;
					if (whatAccount == 15 && data->Dsp6 > spotionSellingAccount[5])
						spotionSellingAccount[whatAccount - 10] += 1;
				}
				else if (pop->Down->IsOverlapped(ZeroInputMgr->GetClientPoint()) && spotionSellingAccount[whatAccount - 10] - 1 >= 1)
					spotionSellingAccount[whatAccount - 10] -= 1;
			}
			if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				accountcheckwindowRender = false;
		}
		if (noticewindowRender == true)
		{
			if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				data->Day();
				data->Save();
				ZeroSoundMgr->Stop();
				ZeroSceneMgr->ChangeScene(new AccountScene());
				return;
			}
		}
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
	{
		if (isClick == false)
		{
			if (what != -1)
				isClick = true;
			if (p)
			{
				if (movePotion->potion[0]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dpotion1 != 0)
					what = 0;
				else if (movePotion->potion[1]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dpotion2 != 0)
					what = 1;
				else if (movePotion->potion[2]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dpotion3 != 0)
					what = 2;
				else if (movePotion->potion[3]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dpotion4 != 0)
					what = 3;
				else if (movePotion->potion[4]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dpotion5 != 0)
					what = 4;
				else if (movePotion->potion[5]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dpotion6 != 0)
					what = 5;
			}
			else if (p == false)
			{
				if (movesPotion->Spotion[0]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dsp1 != 0)
					what = 10;
				else if (movesPotion->Spotion[1]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dsp2 != 0)
					what = 11;
				else if (movesPotion->Spotion[2]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dsp3 != 0)
					what = 12;
				else if (movesPotion->Spotion[3]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dsp4 != 0)
					what = 13;
				else if (movesPotion->Spotion[4]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dsp5 != 0)
					what = 14;
				else if (movesPotion->Spotion[5]->IsOverlapped(ZeroInputMgr->GetClientPoint()) && data->Dsp6 != 0)
					what = 15;
			}
		}
	}
	if (isClick == true)
		PotionClicking();
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	for (int i = 0; i<2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());

}

void GameScene::Render()
{
	if (loading == true)
	{
		ZeroIScene::Render();
		inGame->Render();
		back->colon->Render();
		back->stand->Render();
		if (p == false)
		{
			back->gameBackground1->Render();
			for (int i = 0; i < 6; i++)
			{
				if (i < 2)
				{
					sp1num[i]->Render();
					sp2num[i]->Render();
					sp3num[i]->Render();
					sp4num[i]->Render();
					sp5num[i]->Render();
					sp6num[i]->Render();
				}
				sp1num[0]->number[data->Dsp1 / 10]->Render();
				sp1num[1]->number[data->Dsp1 % 10]->Render();
				sp2num[0]->number[data->Dsp2 / 10]->Render();
				sp2num[1]->number[data->Dsp2 % 10]->Render();
				sp3num[0]->number[data->Dsp3 / 10]->Render();
				sp3num[1]->number[data->Dsp3 % 10]->Render();
				sp4num[0]->number[data->Dsp4 / 10]->Render();
				sp4num[1]->number[data->Dsp4 % 10]->Render();
				sp5num[0]->number[data->Dsp5 / 10]->Render();
				sp5num[1]->number[data->Dsp5 % 10]->Render();
				sp6num[0]->number[data->Dsp6 / 10]->Render();
				sp6num[1]->number[data->Dsp6 % 10]->Render();
				spotion->Spotion[i]->Render();
				movesPotion->Spotion[i]->Render();
			}
		}
		else if (p)
		{
			back->gameBackground->Render();
			for (int i = 0; i < 6; i++)
			{
				if (i < 2)
				{
					Potion1num[i]->Render();
					Potion2num[i]->Render();
					Potion3num[i]->Render();
					Potion4num[i]->Render();
					Potion5num[i]->Render();
					Potion6num[i]->Render();
				}
				potion->potion[i]->Render();
				movePotion->potion[i]->Render();
			}
			Potion1num[0]->number[data->Dpotion1 / 10]->Render();
			Potion1num[1]->number[data->Dpotion1 % 10]->Render();
			Potion2num[0]->number[data->Dpotion2 / 10]->Render();
			Potion2num[1]->number[data->Dpotion2 % 10]->Render();
			Potion3num[0]->number[data->Dpotion3 / 10]->Render();
			Potion3num[1]->number[data->Dpotion3 % 10]->Render();
			Potion4num[0]->number[data->Dpotion4 / 10]->Render();
			Potion4num[1]->number[data->Dpotion4 % 10]->Render();
			Potion5num[0]->number[data->Dpotion5 / 10]->Render();
			Potion5num[1]->number[data->Dpotion5 % 10]->Render();
			Potion6num[0]->number[data->Dpotion6 / 10]->Render();
			Potion6num[1]->number[data->Dpotion6 % 10]->Render();
		}
		changep->Render();
		changesp->Render();
		coin->Render();
		for (int i = 0; i < 2; i++)
		{
			Nhour[i]->Render();
			Nminute[i]->Render();
		}
		for (int i = 0; i < 4; i++)
		{
			money[i]->Render();
		}
		Nhour[0]->number[hour / 10]->Render();
		Nhour[1]->number[hour % 10]->Render();
		Nminute[0]->number[minute * 5 / 10]->Render();
		Nminute[1]->number[minute * 5 % 10]->Render();
		money[0]->number[data->Dmoney / 1000]->Render();
		money[1]->number[data->Dmoney / 100 % 10]->Render();
		money[2]->number[data->Dmoney / 10 % 10]->Render();
		money[3]->number[data->Dmoney % 10]->Render();
		sell->Render();
		//radio->Render();
		potion->Render();
		movePotion->Render();
		buyer->Render();
		endGame->Render();
		if (noticewindowRender == true)
		{
			pop->noticeWindow->Render();
			if (Acceptbutton[OVER] == false && Acceptbutton[ON] == false)
				pop->Accept->Render();
			else if (Acceptbutton[OVER] == true)
				pop->onAccept->Render();
			else
				pop->downAccept->Render();

			if (Acceptbutton[OVER] == false && Acceptbutton[ON] == false)
				pop->Accept->Render();
			else if (Acceptbutton[OVER] == true)
				pop->onAccept->Render();
			else
				pop->downAccept->Render();
		}
		if (accountcheckwindowRender == true)
		{
			accountCheck->Render();
			pop->accountCheckWindow->Render();
			pop->Up->SetPosX(600);
			pop->Up->Render();
			pop->Down->SetPosX(670);
			pop->Down->Render();
			pop->Accept->SetPos(350,350);
			pop->onAccept->SetPos(350, 350);
			if (Acceptbutton[OVER] == false && Acceptbutton[ON] == false)
				pop->Accept->Render();
			else if (Acceptbutton[OVER] == true)
				pop->onAccept->Render();
			else
				pop->downAccept->Render();
			accountCheck->SetPos(400, 250);
			if(whatAccount<10)
				accountCheck->number[potionSellingAccount[whatAccount]]->Render();
			else
				accountCheck->number[spotionSellingAccount[whatAccount-10]]->Render();
		}
	}
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}
void GameScene::PotionSell()
{
	data->Save();
	if (buyer->isComed)
	{
		movePotion->potion[0]->SetPos(930, 130);
		movePotion->potion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
		movePotion->potion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
		movePotion->potion[3]->SetPos(930, 350);
		movePotion->potion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
		movePotion->potion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);
		movesPotion->Spotion[0]->SetPos(930, 130);
		movesPotion->Spotion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
		movesPotion->Spotion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
		movesPotion->Spotion[3]->SetPos(930, 350);
		movesPotion->Spotion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
		movesPotion->Spotion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);
		for (int i = 0; i < 6; i++)
		{
			if (!movePotion->potion[i]->IsOverlapped(back->stand))
				potionSellingAccount[i] = 0;
			if (!movesPotion->Spotion[i]->IsOverlapped(back->stand))
				spotionSellingAccount[i] = 0;
		}
		buyer->CheckOrder(potionSellingAccount, spotionSellingAccount);
		for (int i = 0; i < 6; i++)
		{
			potionSellingAccount[i] = 1;
			spotionSellingAccount[i] = 1;
		}
		data->Start();
	}
}

void GameScene::PotionClicking()
{
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
	{
		if (what != -1)
		{
			if (p)
				movePotion->potion[what]->SetPos(ZeroInputMgr->GetClientPoint().x - movePotion->potion[0]->Width() / 2, ZeroInputMgr->GetClientPoint().y - movePotion->potion[0]->Height() / 2);
			else if (p == false)
				movesPotion->Spotion[what - 10]->SetPos(ZeroInputMgr->GetClientPoint().x - movePotion->potion[0]->Width() / 2, ZeroInputMgr->GetClientPoint().y - movePotion->potion[0]->Height() / 2);
		}
	}
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
	{
		if (p)
		{
			if (!back->stand->IsOverlapped(movePotion->potion[what]) || sell->IsOverlapped(movePotion->potion[what]))
			{
				switch (what)
				{
				case 0:
					movePotion->potion[0]->SetPos(930, 130);
					break;
				case 1:
					movePotion->potion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
					break;
				case 2:
					movePotion->potion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
					break;
				case 3:
					movePotion->potion[3]->SetPos(930, 350);
					break;
				case 4:
					movePotion->potion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
					break;
				case 5:
					movePotion->potion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);
					break;
				default:
					break;
				}
			}
		}
		else if (p == false)
		{
			if (!back->stand->IsOverlapped(movesPotion->Spotion[what - 10]) || sell->IsOverlapped(movesPotion->Spotion[what - 10]))
			{
				switch (what)
				{
				case 10:
					movesPotion->Spotion[0]->SetPos(930, 130);
					break;
				case 11:
					movesPotion->Spotion[1]->SetPos(950 + potion->potion[0]->Width(), 130);
					break;
				case 12:
					movesPotion->Spotion[2]->SetPos(970 + 2 * potion->potion[0]->Width(), 130);
					break;
				case 13:
					movesPotion->Spotion[3]->SetPos(930, 350);
					break;
				case 14:
					movesPotion->Spotion[4]->SetPos(950 + potion->potion[0]->Width(), 350);
					break;
				case 15:
					movesPotion->Spotion[5]->SetPos(970 + 2 * potion->potion[0]->Width(), 350);
					break;
				default:
					break;
				}
			}
		}
		what = -1;
		isClick = false;
	}
}