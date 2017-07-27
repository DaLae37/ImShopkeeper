#include "BlackJack.h"

BlackJack::BlackJack()
{
	coin = new ZeroSprite("Resource/rest/coin.png");
	board = new ZeroSprite("Resource/MiniGame/CardBoard.png");
	backCard = new ZeroSprite("Resource/MiniGame/back.png");
	Hit = new ZeroSprite("Resource/MiniGame/Hit.png");
	Hit->SetPos(500, 650);
	Hold = new ZeroSprite("Resource/MiniGame/Hold.png");
	Hold->SetPos(800, 650);
	for (int i = 0; i < 2; i++)
	{
		showMyScore[i] = new Number();
		showMyScore[i]->SetPos(500 + i * 40, 0);
		showYourScore[i] = new Number();
		showYourScore[i]->SetPos(500 + i * 40, 600);
	}
	back = new ZeroSprite("Background/back.png");
	back->SetPos(10, 650);
	back->SetScale(0.5);
	draww = new ZeroSprite("Resource/MiniGame/draw.png");
	draww->SetPos(500, 300);
	cardCap = new ZeroSprite("Resource/MiniGame/CardCap.png");
	data = new DataManager();
	bat = new ZeroSprite("Resource/MiniGame/batting.png");
	bust = new ZeroSprite("Resource/MiniGame/Bust.png");
	bust->SetPos(500, 300);
	win = new ZeroSprite("Resource/MiniGame/Win.png");
	win->SetPos(500, 300);
	lose = new ZeroSprite("Resource/MiniGame/Lose.png");
	lose->SetPos(500, 300);
	cardCap->SetPos(1050, 0);
	backCard->SetPos(1170, -50);
	backCard->SetRot(33);
	pop = new PopUp();
	for (int i = 0; i < 4; i++)
	{
		myBack[i] = new ZeroSprite("Resource/MiniGame/back.png");
		myBack[i]->SetPos(0, 10);
		yourback[i] = new ZeroSprite("Resource/MiniGame/back.png");
		yourback[i]->SetPos(0, 300);
		myCard[i] = new Card();
		yourCard[i] = new Card();
		num[i] = new Number();
		battingmoneynum[i] = new Number();
		battingmoneynum[i]->SetPos(350+i*40, 250);
		coinnum[i] = new Number();
	}
	ZeroCameraMgr->SetCameraOn();
	ZeroCameraMgr->SetTarget(backCard);
	ZeroCameraMgr->SetSpeed(0);
	ZeroCameraMgr->SetScreen(1280, 1024);
	pop->Up->AddPosX(-150);
	pop->Down->AddPosX(-150);
	myScore = 0;
	yourScore = 0;
	draw = 0;
	battingmoney = 0;
	gameStart = false;
	once = true;
	isDrag = false;
	batting = false;
	battingon = false;
	finish = false;
	battingmoneyrender = false;
	start = false;
	one = false;
	two = false;
	three = false;
	four = false;
	isHit = false;
	isWin = false;
	isLose = false;
	winrender = false; 
	bustrender = false;
	pleaseontime = false;
	loserender = false;
	drawrender = false;
	ZeroSoundMgr->PushSound("Sound/cardGame.mp3", "Jack");
	ZeroSoundMgr->Play("Jack");
	Overlap();
	cursor[0] = new ZeroSprite("Resource/cursor.png");
	cursor[1] = new ZeroSprite("Resource/cursorclick.png");
}

BlackJack::~BlackJack()
{
}

void BlackJack::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
		isClicked = true;
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
		isClicked = false;
	if (battingon == false)
	{
		if (batting == false)
		{
			if (isDrag == true)
			{
				if (once == true)
				{
					MouseY = ZeroInputMgr->GetClientPoint().y;
					once = false;
				}
				if (isDrag == true && backCard->IsOverlapped(ZeroInputMgr->GetClientPoint()) && MouseY < ZeroInputMgr->GetClientPoint().y)
				{
					backCard->AddPos(-ZeroInputMgr->GetClientPoint().y / 15 * 0.7, ZeroInputMgr->GetClientPoint().y / 15);
					once = true;
				}
				if (backCard->Pos().y > 250)
				{
					isDrag = false;
					gameStart = true;
				}
			}

			if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYON)
			{
				if (isDrag == true && !backCard->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					isDrag = false;
					backCard->SetPos(1170, -50);
					MouseY = 0;
				}
			}
			if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYUP)
			{
				if (isDrag == true)
				{
					isDrag = false;
					backCard->SetPos(1170, -50);
					MouseY = 0;
				}
			}
			if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
			{
				if (gameStart == false && backCard->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					isDrag = true;
				}
			}
			if (gameStart == true)
			{
				backCard->SetRotCenter(backCard->Width() / 2, backCard->Height() / 2);
				backCard->AddRot(-11);
				backCard->AddPos(-30, -10);
				backCard->AddScale(0.04);
				if (backCard->Pos().x < -400)
				{
					gameStart = false;
					batting = true;
				}
			}
		}
		else
		{
			if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
			{
				if (battingmoneyrender == false && bat->IsOverlapped(ZeroInputMgr->GetClientPoint()))
				{
					battingmoneyrender = true;
				}
				if (battingmoneyrender == true)
				{
					if (data->Dmoney < 100)
					{
						battingmoney = 0;
						if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
						{
							battingmoneyrender = false;
							battingon = true;
						}
					}
					else
					{
						if (pop->Up->IsOverlapped(ZeroInputMgr->GetClientPoint()) && battingmoney + 100 <= 3000 && battingmoney<=data->Dmoney)
						{
							battingmoney += 100;
						}
						else if (pop->Down->IsOverlapped(ZeroInputMgr->GetClientPoint()) && battingmoney - 100 >= 0 && data->Dmoney - battingmoney >= 100)
						{
							battingmoney -= 100;
						}
						else if (pop->Accept->IsOverlapped(ZeroInputMgr->GetClientPoint()))
						{
							data->Dmoney -= battingmoney;
							data->Save();
							battingmoneyrender = false;
							battingon = true;
						}
					}
				}
			}
		}
	}
	else
	{
		if (myScore == 21)
		{
			isWin = true;
			Stopped();
		}
		else if (myScore > 21)
		{
			isLose = true;
			Stopped();
		}
		CardSet();
		if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN)
		{
			if (Hit->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				if (three == false)
				{
					three = true;
				}
				else if (four == false)
				{
					four = true;
				}
				else
				{
					if (myBack[3]->Pos().x == 800)
					{
						myScore += myCardnum[3] + 1;
					}
					Stopped();
				}
			}
			if (Hold->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				Stopped();
			}
			if (back->IsOverlapped(ZeroInputMgr->GetClientPoint()))
			{
				ZeroSoundMgr->Stop("Jack");
				ZeroSceneMgr->ChangeScene(new MiniGameScene);
				return;
			}
		}
	}
	for (int i = 0; i<2; i++)
		cursor[i]->SetPos(ZeroInputMgr->GetClientPoint());
}

void BlackJack::Render()
{
	ZeroIScene::Render();
	board->Render();
	backCard->Render();
	bat->Render();
	cardCap->Render();
	if (start == true)
	{
		for (int i = 0; i < 4; i++)
		{
			myCard[i]->Render();
			yourCard[i]->Render();
			myCard[i]->card[myCardnum[i]]->Render();
			yourCard[i]->card[yourCardnum[i]]->Render();
		}
	}
	if (battingmoneyrender == true)
	{
		pop->moneyCheckWindow->Render();
		pop->Up->Render();
		pop->Down->Render();
		pop->Accept->Render();
		for (int i = 0; i < 4; i++)
		{
			battingmoneynum[i]->Render();
		}
		battingmoneynum[0]->number[battingmoney / 1000]->Render();
		battingmoneynum[1]->number[battingmoney / 100 % 10]->Render();
		battingmoneynum[2]->number[battingmoney / 10 % 10]->Render();
		battingmoneynum[3]->number[battingmoney % 10]->Render();
	}
	for (int i = 0; i < 4; i++)
	{
		myCard[i]->Render();
		yourCard[i]->Render();
	}
	if (battingon == true)
	{
		for (int i = 0; i < 2; i++)
		{
			showMyScore[i]->Render();
		}
		Hit->Render();
		Hold->Render();
		if (one == false)
		{
			myBack[0]->Render();
		}
		else if(one == true)
		{
			myCard[0]->card[myCardnum[0]]->Render();
		}
		if (two == false && one == true)
		{
			myBack[1]->Render();
		}
		else if (two == true)
		{
			myCard[1]->card[myCardnum[1]]->Render();
		}
		if (three == false && two == true)
		{
			myBack[2]->Render();
		}
		else if(three == true)
		{
			myCard[2]->card[myCardnum[2]]->Render();
		}
		if (four == false && three == true)
		{
			myBack[3]->Render();
		}
		else if(four == true)
		{
			myCard[3]->card[myCardnum[3]]->Render();
		}
		showMyScore[0]->number[myScore / 10]->Render();
		showMyScore[1]->number[myScore % 10]->Render();
	}
	if (finish == true)
	{
		for (int i = 0; i < 2; i++)
		{
			showYourScore[i]->Render();
		}
		showYourScore[0]->number[yourScore / 10]->Render();
		showYourScore[1]->number[yourScore % 10]->Render();
		for (int i = 0; i < current; i++)
		{
			yourCard[i]->card[yourCardnum[i]]->Render();
		}
	}
	if (bustrender == true)
	{
		bust->Render();
		back->Render();
	}
	if (loserender == true)
	{
		lose->Render();
		back->Render();
	}
	if (winrender == true)
	{
		win->Render();
		back->Render();
	}
	if (drawrender == true)
	{
		draww->Render();
		back->Render();
	}
}

void BlackJack::Overlap()
{
	for (int i = 0; i < 4; i++)
	{
		myCardnum[i] = rand() % 13;
		for (int j = 0; j < i; j++)
		{
			if (myCardnum[i] == myCardnum[j])
			{
				i--;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		yourCardnum[i] = rand() % 13;
		for (int j = 0; j < i; j++)
		{
			if (yourCardnum[i] == yourCardnum[j])
			{
				i--;
			}
		}
	}
	if (isClicked)
		cursor[1]->Render();
	else
		cursor[0]->Render();
}

void BlackJack::CardSet()
{
	for (int i = 0; i < 4; i++)
	{
		myCard[i]->SetPos(200 + i * 200, 10);
		yourCard[i]->SetPos(200 + i * 200, 300);
	}
	if (one == false)
	{
		myBack[0]->AddPosX(10);
		if (myBack[0]->Pos().x == 200)
		{
			myScore += myCardnum[0]+1;
			one = true;
		}
	}
	else if (two == false && one == true)
	{
		myBack[1]->AddPosX(10);
		if (myBack[1]->Pos().x == 400)
		{
			myScore += myCardnum[1]+1;
			two = true;
		}
	}
	if (three == true)
	{
		myBack[2]->AddPosX(10);
		if (myBack[2]->Pos().x == 600)
		{
			myScore += myCardnum[2] + 1;
		}
	}
	if (four == true)
	{
		myBack[3]->AddPosX(10);
		if (myBack[3]->Pos().x == 800)
		{
			myScore += myCardnum[3] + 1;
		}
	}
}

void BlackJack::Stopped()
{
	if (pleaseontime == false)
	{
		pleaseontime = true;
		if (isLose == true)
		{
			finish = true;
			for (int i = 0; i < 4; i++)
			{
				current = i;
				if (yourScore > 16)
				{
					break;
				}
				yourScore += yourCardnum[i] + 1;
			}
			if (yourScore > 21)
			{
				drawrender = true;
			}
			else
			{
				loserender = true;
			}
		}
		else if (isLose == false)
		{
			if (isWin == true)
			{
				finish = true;
				for (int i = 0; i < 4; i++)
				{
					current = i;
					if (yourScore > 10 + rand() % 10 + 6)
					{
						break;
					}
					yourScore += yourCardnum[i] + 1;
				}
				if (myScore == 21)
				{
					bustrender = true;
					data->Dmoney += battingmoney * 2;
					if (data->Dmoney > 10000)
					{
						data->Dmoney = 9999;
					}
					data->Save();
				}
			}
			else
			{
				finish = true;
				for (int i = 0; i < 4; i++)
				{
					current = i;
					if (yourScore > 16)
					{
						break;
					}
					yourScore += yourCardnum[i] + 1;
				}
				if (yourScore > 21)
				{
					winrender = true;
					data->Dmoney += battingmoney * 2;
					if (data->Dmoney > 10000)
					{
						data->Dmoney = 9999;
					}
					data->Save();
				}
				else if (myScore > yourScore && yourScore <= 21)
				{
					winrender = true;
					data->Dmoney += battingmoney * 2;
					if (data->Dmoney > 10000)
					{
						data->Dmoney = 9999;
					}
					data->Save();
				}
				else if (myScore < yourScore && yourScore <= 21)
				{
					loserender = true;
				}
				else if (myScore == yourScore)
				{
					drawrender = true;
				}
			}
		}
	}
}