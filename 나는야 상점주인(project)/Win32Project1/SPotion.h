#pragma once
#include "ZeroIScene.h"
#include <ZeroSprite.h>
class SPotion : public ZeroIScene
{
public:
	SPotion();
	~SPotion();
	ZeroSprite *Spotion[7];
	ZeroSprite *small_Spotion[7];
};

