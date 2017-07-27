#include "PopUp.h"

PopUp::PopUp()
{
	resetWindow = new ZeroSprite("Resource/PopUp/resetPop.png");
	resetWindow->SetPos(350, 200);

	startWindow = new ZeroSprite("Resource/PopUp/startPop.png");
	startWindow->SetPos(350, 200);

	endWindow = new ZeroSprite("Resource/PopUp/endPop.png");
	endWindow->SetPos(350, 200);

	buyWindow = new ZeroSprite("Resource/PopUp/buyPop.png");
	buyWindow->SetPos(350, 200);

	goWindow = new ZeroSprite("Resource/PopUp/goPop.png");
	goWindow->SetPos(350, 200);

	noticeWindow = new ZeroSprite("Resource/PopUp/noticePop.png");
	noticeWindow->SetPos(350, 200);

	accountWindow = new ZeroSprite("Resource/PopUp/accountPop.png");
	accountWindow->SetPos(350, 200);

	noMoneyWindow = new ZeroSprite("Resource/PopUp/noMoneyPop.png");
	noMoneyWindow->SetPos(350, 200);

	howManyWindow = new ZeroSprite("Resource/PopUp/howManyPop.png");
	howManyWindow->SetPos(350, 200);

	accountCheckWindow = new ZeroSprite("Resource/PopUp/accountCheckPop.png");
	accountCheckWindow->SetPos(300, 200);

	moneyCheckWindow = new ZeroSprite("Resource/PopUp/moneyCheckPop.png");
	moneyCheckWindow->SetPos(300, 200);

	Accept = new ZeroSprite("Resource/PopUp/Accept.png");
	Accept->SetPos(590, 435);

	Yes = new ZeroSprite("Resource/PopUp/Yes.png");
	Yes->SetPos(450, 435);

	No = new ZeroSprite("Resource/PopUp/No.png");
	No->SetPos(730, 435);

	onAccept = new ZeroSprite("Resource/PopUp/onAccept.png");
	onAccept->SetPos(590, 435);

	onYes = new ZeroSprite("Resource/PopUp/onYes.png");
	onYes->SetPos(450, 435);

	onNo = new ZeroSprite("Resource/PopUp/onNo.png");
	onNo->SetPos(730, 435);

	downAccept = new ZeroSprite("Resource/PopUp/downAccept.png");
	downAccept->SetPos(590, 435);

	downYes = new ZeroSprite("Resource/PopUp/downYes.png");
	downYes->SetPos(450, 435);

	downNo = new ZeroSprite("Resource/PopUp/downNo.png");
	downNo->SetPos(730, 435);

	Up = new ZeroSprite("Resource/PopUp/Up.png");
	Up->SetPos(750, 350);

	Down = new ZeroSprite("Resource/PopUp/Down.png");
	Down->SetPos(850, 350);
}

PopUp::~PopUp()
{
}

void PopUp::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void PopUp::Render()
{
	ZeroIScene::Render();
}