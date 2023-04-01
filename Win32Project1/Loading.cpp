 #include "Loading.h"

Loading::Loading()
{
	powered = new ZeroAnimation(10.0f);
	for (int i = 1; i < 23; i++)
	{
		if (i == 1 || i == 22)
		{
			powered->PushSprite("Powered_by_ZeroEngine/%d.png", i);
			powered->PushSprite("Powered_by_ZeroEngine/%d.png", i);
		}
		powered->PushSprite("Powered_by_ZeroEngine/%d.png", i);
	}
	PushScene(powered);
	//ZeroSoundMgr->PushSound("Sound/loading.mp3", "loading");
	//ZeroSoundMgr->Play("loading");
	countTime = 0.f;
	once = false;
}

Loading::~Loading()
{

}	

void Loading::Update(float eTime)
{
	ZeroIScene::Update(eTime);
	countTime += eTime;
	if (once == false)
	{
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/1.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/2.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/3.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/4.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/5.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/6.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/7.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/8.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/9.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/buyer/10.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/potion1.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/smallpotion1.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/potion2.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/smallpotion2.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/potion3.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/smallpotion3.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/potion4.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/smallpotion4.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/potion5.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/smallpotion5.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/potion6.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/potion/smallpotion6.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp1.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp1.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp2.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp2.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp3.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp3.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp4.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp4.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp5.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp5.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp6.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp6.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/sp7.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/sp/smallsp7.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/1.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/2.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/3.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/4.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/5.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/6.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/7.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/8.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/9.png");
		ZeroTexMgr->LoadTextureFromFile("Resource/number/10.png");
		ZeroTexMgr->LoadTextureFromFile("Background/inGame.png");
		once = true;
	}
	if (countTime > 2.3f)
	{
		ZeroSceneMgr->ChangeScene(new MainScene());
		//ZeroSoundMgr->Stop("loading");
		return;
	}
}

void Loading::Render()
{
	ZeroIScene::Render();
	powered->Render();
}
