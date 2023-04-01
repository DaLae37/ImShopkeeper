#pragma once
#include "ZeroIScene.h"
#include "ZeroSoundManager.h"
#include "ZeroSprite.h"
#include "ZeroInputManager.h"
#include "Number.h"

class Radio : public ZeroIScene
{
public:
	Radio();
	~Radio();
	void Update(float eTime);
	void Render();
	void StartRadio();
	void StopRadio();
	void ResetRadio();
	void NextRadio();
	void Sad();
	int nowPlay;
	int nowsadTime;
	float sadTime;
	bool isSad;
	bool clicked;
	ZeroSprite *radio;
	ZeroSprite *start;
	ZeroSprite *stop;
	ZeroSprite *reset;
	ZeroSprite *next;
	Number *num[2];
};

