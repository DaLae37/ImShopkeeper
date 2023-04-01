#include "Card.h"

Card::Card()
{
	card[0] = new ZeroSprite("Resource/MiniGame/SA.png");
	card[1] = new ZeroSprite("Resource/MiniGame/S2.png");
	card[2] = new ZeroSprite("Resource/MiniGame/S3.png");
	card[3] = new ZeroSprite("Resource/MiniGame/S4.png");
	card[4] = new ZeroSprite("Resource/MiniGame/S5.png");
	card[5] = new ZeroSprite("Resource/MiniGame/S6.png");
	card[6] = new ZeroSprite("Resource/MiniGame/S7.png");
	card[7] = new ZeroSprite("Resource/MiniGame/S8.png");
	card[8] = new ZeroSprite("Resource/MiniGame/S9.png");
	card[9] = new ZeroSprite("Resource/MiniGame/S10.png");
	card[10] = new ZeroSprite("Resource/MiniGame/SJ.png");
	card[11] = new ZeroSprite("Resource/MiniGame/SQ.png");
	card[12] = new ZeroSprite("Resource/MiniGame/SK.png");
	for (int i = 0; i < 13; i++)
	{
		PushScene(card[i]);
	}
	back = new ZeroSprite("Resource/MiniGame/Back.png");
}


Card::~Card()
{
}

void Card::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Card::Render()
{
	ZeroIScene::Render();
}