#include "Tutorial.h"

Tutorial::Tutorial()
{
	tuto1 = new ZeroSprite("Resource/tutorial/tuto1.png");
	tuto2 = new ZeroSprite("Resource/tutorial/tuto2.png");
	b = true;
	tuto1->Render();
}

Tutorial::~Tutorial()
{
}

void Tutorial::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	if (ZeroInputMgr->GetKey(VK_LBUTTON) == INPUTMGR_KEYDOWN) {
		if (b) 
			b = false;
		else if (b == false) {
			ZeroSceneMgr->ChangeScene(new RestScene());
			return;
		}
	}
}

void Tutorial::Render()
{
	if (b) {
		tuto1->Render();
	}
	else {
		tuto2->Render();
	}
}