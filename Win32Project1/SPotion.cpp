#include "SPotion.h"

SPotion::SPotion()
{
	for (int i = 0; i < 7; i++)
	{
		Spotion[i] = new ZeroSprite("Resource/sp/sp%d.png", i + 1);
		small_Spotion[i] = new ZeroSprite("Resource/sp/smallsp%d.png", i + 1);
	}
}

SPotion::~SPotion()
{

}