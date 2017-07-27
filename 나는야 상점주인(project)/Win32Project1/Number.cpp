#include "Number.h"

Number::Number()
{
	for (int i = 0; i < 10; i++)
	{
		number[i] = new ZeroSprite("Resource/number/%d.png",i);
		PushScene(number[i]);
	}
}

Number::~Number()
{
}

void Number::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void Number::Render()
{
	ZeroIScene::Render();
}