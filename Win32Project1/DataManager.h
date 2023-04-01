#pragma once
#include "ZeroIScene.h"
#include "ZeroInputManager.h"
class DataManager : public ZeroIScene
{
public:
	DataManager();
	~DataManager();
	void Update(float eTime);
	void Render();
	void Start();
	void Save();
	void Day();
	void Reset();
	void potionPrice();
	void FameUpdate(int a, int b);
	int Dmoney;
	int Ddate;
	int Dpotion1;
	int Dpotion2;
	int Dpotion3;
	int Dpotion4;
	int Dpotion5;
	int Dpotion6;
	int Dsp1;
	int Dsp2;
	int Dsp3;
	int Dsp4;
	int Dsp5;
	int Dsp6;
	int Dfame;
	int Dachieve[6];
	int pPrice[12];
};

