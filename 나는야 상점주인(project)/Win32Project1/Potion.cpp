#include "Potion.h"

Potion::Potion()
{
	for (int i = 1; i <= 6; i++)
	{
		potion[i-1] = new ZeroSprite("Resource/potion/potion%d.png",i);
		small_potion[i-1] = new ZeroSprite("Resource/potion/smallpotion%d.png",i);
	}
}

Potion::~Potion()
{
}

void Potion::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}
void Potion::Render()
{
	ZeroIScene::Render();
}