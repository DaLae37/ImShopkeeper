#pragma once
#include "ZeroIScene.h"
#include "ZeroSprite.h"
#include "Potion.h"
#include "SPotion.h"
#include "DataManager.h"
#include "Number.h"

class Buyer : public ZeroIScene
{
private :
	int a;
public:
	Buyer();
	~Buyer();
	ZeroSprite *buyer[10];
	ZeroSprite *perfect;
	ZeroSprite *good;
	ZeroSprite *bad;
	ZeroSprite *bullon;
	Potion *potion;
	SPotion *spotion;
	Number *num[4];
	DataManager *data;
	void Update(float eTime);
	void Render();
	void Order();
	void CheckOrder(int *a, int *b);
	int who;
	int PotionList[12];
	int RandList[4];
	float comeTime;
	float resultTime;
	float delayTime;
	bool isComed;
	bool perpectRender;
	bool goodRender;
	bool badRender;
	bool checking(int a[]);
};

