#include "CloseScene.h"

CloseScene::CloseScene()
{
	back = new ZeroSprite("Background/restBackground.png");
}

CloseScene::~CloseScene()
{
}

void CloseScene::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void CloseScene::Render()
{
	ZeroIScene::Render();
	back->Render();
}