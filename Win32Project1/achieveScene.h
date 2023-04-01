#pragma once
#include "RestScene.h"
#include <ZeroIScene.h>
#include <ZeroSprite.h>
#include <ZeroInputManager.h>
#include <ZeroSceneManager.h>
#include "ZeroApplication.h"
class achieveScene : public ZeroIScene
{
public:
	achieveScene();
	~achieveScene();
	void Update(float eTime);
	void Render();
	ZeroSprite *background;
	ZeroSprite *achieveList[12];
	ZeroSprite *achieveEx[12];
	ZeroSprite *next;
	ZeroSprite *before;
	ZeroSprite *back;
	ZeroSprite *cursor[2];
	bool isClicked;
	bool scene;
};

