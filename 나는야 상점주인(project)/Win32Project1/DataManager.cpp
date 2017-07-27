#include "DataManager.h"

DataManager::DataManager()
{
	FILE *potionPrice;
	FILE * money;
	FILE * date;
	FILE * potion1;
	FILE * potion2;
	FILE * potion3;
	FILE * potion4;
	FILE * potion5;
	FILE * potion6;
	FILE * sp1;
	FILE * sp2;
	FILE * sp3;
	FILE * sp4;
	FILE * sp5;
	FILE * sp6;
	FILE * fame;
	FILE * achieve[6];
	potionPrice = fopen("Data/potionPrice.txt", "rt");
	money = fopen("Data/money.txt", "rt");
	date = fopen("Data/date.txt", "rt");
	potion1 = fopen("Data/potion1.txt", "rt");
	potion2 = fopen("Data/potion2.txt", "rt");
	potion3 = fopen("Data/potion3.txt", "rt");
	potion4 = fopen("Data/potion4.txt", "rt");
	potion5 = fopen("Data/potion5.txt", "rt");
	potion6 = fopen("Data/potion6.txt", "rt");
	sp1 = fopen("Data/sp1.txt", "rt");
	sp2 = fopen("Data/sp2.txt", "rt");
	sp3 = fopen("Data/sp3.txt", "rt");
	sp4 = fopen("Data/sp4.txt", "rt");
	sp5 = fopen("Data/sp5.txt", "rt");
	sp6 = fopen("Data/sp6.txt", "rt");
	fame = fopen("Data/fame.txt", "rt");
	achieve[0] = fopen("Data/achieve1.txt", "rt");
	achieve[1] = fopen("Data/achieve2.txt", "rt");
	achieve[2] = fopen("Data/achieve3.txt", "rt");
	achieve[3] = fopen("Data/achieve4.txt", "rt");
	achieve[4] = fopen("Data/achieve5.txt", "rt");
	achieve[5] = fopen("Data/achieve6.txt", "rt");
	fscanf(money, "%d", &Dmoney);
	fscanf(date, "%d", &Ddate);
	fscanf(potion1, "%d", &Dpotion1);
	fscanf(potion2, "%d", &Dpotion2);
	fscanf(potion3, "%d", &Dpotion3);
	fscanf(potion4, "%d", &Dpotion4);
	fscanf(potion5, "%d", &Dpotion5);
	fscanf(potion6, "%d", &Dpotion6);
	fscanf(sp1, "%d", &Dsp1);
	fscanf(sp2, "%d", &Dsp2);
	fscanf(sp3, "%d", &Dsp3);
	fscanf(sp4, "%d", &Dsp4);
	fscanf(sp5, "%d", &Dsp5);
	fscanf(sp6, "%d", &Dsp6);
	fscanf(fame, "%d", &Dfame);
	for (int i = 0; i < 12; i++)
		fscanf(potionPrice, "%d ", &pPrice[i]);
	for (int i = 0; i<6; i++)
		fscanf(achieve[i], "%d", &Dachieve[i]);
	fclose(money);
	fclose(date);
	fclose(potion1);
	fclose(potion2);
	fclose(potion3);
	fclose(potion4);
	fclose(potion5);
	fclose(potion6);
	fclose(sp1);
	fclose(sp2);
	fclose(sp3);
	fclose(sp4);
	fclose(sp5);
	fclose(sp6);
	fclose(fame);
	for (int i = 0; i<6; i++)
		fclose(achieve[i]);
}

DataManager::~DataManager()
{

}

void DataManager::Update(float eTime)
{
	ZeroIScene::Update(eTime);
}

void DataManager::Render()
{
	ZeroIScene::Render();
}
void DataManager::Start()
{
	FILE * money;
	FILE * date;
	FILE * potion1;
	FILE * potion2;
	FILE * potion3;
	FILE * potion4;
	FILE * potion5;
	FILE * potion6;
	FILE * sp1;
	FILE * sp2;
	FILE * sp3;
	FILE * sp4;
	FILE * sp5;
	FILE * sp6;
	FILE * fame;
	FILE * achieve[6];
	money = fopen("Data/money.txt", "rt");
	date = fopen("Data/date.txt", "rt");
	potion1 = fopen("Data/potion1.txt", "rt");
	potion2 = fopen("Data/potion2.txt", "rt");
	potion3 = fopen("Data/potion3.txt", "rt");
	potion4 = fopen("Data/potion4.txt", "rt");
	potion5 = fopen("Data/potion5.txt", "rt");
	potion6 = fopen("Data/potion6.txt", "rt");
	sp1 = fopen("Data/sp1.txt", "rt");
	sp2 = fopen("Data/sp2.txt", "rt");
	sp3 = fopen("Data/sp3.txt", "rt");
	sp4 = fopen("Data/sp4.txt", "rt");
	sp5 = fopen("Data/sp5.txt", "rt");
	sp6 = fopen("Data/sp6.txt", "rt");
	fame = fopen("Data/fame.txt", "rt");
	achieve[0] = fopen("Data/achieve1.txt", "rt");
	achieve[1] = fopen("Data/achieve2.txt", "rt");
	achieve[2] = fopen("Data/achieve3.txt", "rt");
	achieve[3] = fopen("Data/achieve4.txt", "rt");
	achieve[4] = fopen("Data/achieve5.txt", "rt");
	achieve[5] = fopen("Data/achieve6.txt", "rt");
	fscanf(money, "%d", &Dmoney);
	fscanf(date, "%d", &Ddate);
	fscanf(potion1, "%d", &Dpotion1);
	fscanf(potion2, "%d", &Dpotion2);
	fscanf(potion3, "%d", &Dpotion3);
	fscanf(potion4, "%d", &Dpotion4);
	fscanf(potion5, "%d", &Dpotion5);
	fscanf(potion6, "%d", &Dpotion6);
	fscanf(sp1, "%d", &Dsp1);
	fscanf(sp2, "%d", &Dsp2);
	fscanf(sp3, "%d", &Dsp3);
	fscanf(sp4, "%d", &Dsp4);
	fscanf(sp5, "%d", &Dsp5);
	fscanf(sp6, "%d", &Dsp6);
	fscanf(fame, "%d", &Dfame);
	for (int i = 0; i<6; i++)
		fscanf(achieve[i], "%d", &Dachieve[i]);
	fclose(money);
	fclose(date);
	fclose(potion1);
	fclose(potion2);
	fclose(potion3);
	fclose(potion4);
	fclose(potion5);
	fclose(potion6);
	fclose(sp1);
	fclose(sp2);
	fclose(sp3);
	fclose(sp4);
	fclose(sp5);
	fclose(sp6);
	fclose(fame);
	for (int i = 0; i<6; i++)
		fclose(achieve[i]);
}

void DataManager::Save()
{
	FILE * money;
	FILE * date;
	FILE * potion1;
	FILE * potion2;
	FILE * potion3;
	FILE * potion4;
	FILE * potion5;
	FILE * potion6;
	FILE * sp1;
	FILE * sp2;
	FILE * sp3;
	FILE * sp4;
	FILE * sp5;
	FILE * sp6;
	FILE * fame;
	FILE * achieve[6];
	fopen_s(&money, "Data/money.txt", "wt");
	fopen_s(&date, "Data/date.txt", "wt");
	fopen_s(&potion1, "Data/potion1.txt", "wt");
	fopen_s(&potion2, "Data/potion2.txt", "wt");
	fopen_s(&potion3, "Data/potion3.txt", "wt");
	fopen_s(&potion4, "Data/potion4.txt", "wt");
	fopen_s(&potion5, "Data/potion5.txt", "wt");
	fopen_s(&potion6, "Data/potion6.txt", "wt");
	fopen_s(&sp1, "Data/sp1.txt", "wt");
	fopen_s(&sp2, "Data/sp2.txt", "wt");
	fopen_s(&sp3, "Data/sp3.txt", "wt");
	fopen_s(&sp4, "Data/sp4.txt", "wt");
	fopen_s(&sp5, "Data/sp5.txt", "wt");
	fopen_s(&sp6, "Data/sp6.txt", "wt");
	fopen_s(&fame, "Data/fame.txt", "wt");
	fopen_s(&achieve[0], "Data/achieve1.txt", "wt");
	fopen_s(&achieve[1], "Data/achieve2.txt", "wt");
	fopen_s(&achieve[2], "Data/achieve3.txt", "wt");
	fopen_s(&achieve[3], "Data/achieve4.txt", "wt");
	fopen_s(&achieve[4], "Data/achieve5.txt", "wt");
	fopen_s(&achieve[5], "Data/achieve6.txt", "wt");
	fprintf(money, "%d", Dmoney);
	fprintf(date, "%d", Ddate);
	fprintf(potion1, "%d", Dpotion1);
	fprintf(potion2, "%d", Dpotion2);
	fprintf(potion3, "%d", Dpotion3);
	fprintf(potion4, "%d", Dpotion4);
	fprintf(potion5, "%d", Dpotion5);
	fprintf(potion6, "%d", Dpotion6);
	fprintf(sp1, "%d", Dpotion1);
	fprintf(sp2, "%d", Dpotion2);
	fprintf(sp3, "%d", Dpotion3);
	fprintf(sp4, "%d", Dpotion4);
	fprintf(sp5, "%d", Dpotion5);
	fprintf(sp6, "%d", Dpotion6);
	fprintf(fame, "%d", Dfame);
	for (int i = 0; i < 6; i++)
		fprintf(achieve[i], "%d", Dachieve[i]);
	fclose(money);
	fclose(date);
	fclose(potion1);
	fclose(potion2);
	fclose(potion3);
	fclose(potion4);
	fclose(potion5);
	fclose(potion6);
	fclose(sp1);
	fclose(sp2);
	fclose(sp3);
	fclose(sp4);
	fclose(sp5);
	fclose(sp6);
	fclose(fame);
	for (int i = 0; i < 6; i++)
		fclose(achieve[i]);
}

void DataManager::Day()
{
	Ddate += 1;
}
void DataManager::Reset()
{
	FILE * money;
	FILE * date;
	FILE * potion1;
	FILE * potion2;
	FILE * potion3;
	FILE * potion4;
	FILE * potion5;
	FILE * potion6;
	FILE * sp1;
	FILE * sp2;
	FILE * sp3;
	FILE * sp4;
	FILE * sp5;
	FILE * sp6;
	FILE * fame;
	FILE * achieve[6];
	fopen_s(&money, "Data/money.txt", "wt");
	fopen_s(&date, "Data/date.txt", "wt");
	fopen_s(&potion1, "Data/potion1.txt", "wt");
	fopen_s(&potion2, "Data/potion2.txt", "wt");
	fopen_s(&potion3, "Data/potion3.txt", "wt");
	fopen_s(&potion4, "Data/potion4.txt", "wt");
	fopen_s(&potion5, "Data/potion5.txt", "wt");
	fopen_s(&potion6, "Data/potion6.txt", "wt");
	fopen_s(&sp1, "Data/sp1.txt", "wt");
	fopen_s(&sp2, "Data/sp2.txt", "wt");
	fopen_s(&sp3, "Data/sp3.txt", "wt");
	fopen_s(&sp4, "Data/sp4.txt", "wt");
	fopen_s(&sp5, "Data/sp5.txt", "wt");
	fopen_s(&sp6, "Data/sp6.txt", "wt");
	fopen_s(&fame, "Data/fame.txt", "wt");
	fopen_s(&achieve[0], "Data/achieve1.txt", "wt");
	fopen_s(&achieve[1], "Data/achieve2.txt", "wt");
	fopen_s(&achieve[2], "Data/achieve3.txt", "wt");
	fopen_s(&achieve[3], "Data/achieve4.txt", "wt");
	fopen_s(&achieve[4], "Data/achieve5.txt", "wt");
	fopen_s(&achieve[5], "Data/achieve6.txt", "wt");
	fprintf(money, "%d", 100);
	fprintf(date, "%d", 1);
	fprintf(potion1, "%d", 5);
	fprintf(potion2, "%d", 5);
	fprintf(potion3, "%d", 5);
	fprintf(potion4, "%d", 5);
	fprintf(potion5, "%d", 5);
	fprintf(potion6, "%d", 5);
	fprintf(sp1, "%d", 5);
	fprintf(sp2, "%d", 5);
	fprintf(sp3, "%d", 5);
	fprintf(sp4, "%d", 5);
	fprintf(sp5, "%d", 5);
	fprintf(sp6, "%d", 5);
	fprintf(fame, "%d", 0);
	for (int i = 0; i < 6; i++)
		fprintf(achieve[i], "%d", 0);
	fclose(money);
	fclose(date);
	fclose(potion1);
	fclose(potion2);
	fclose(potion3);
	fclose(potion4);
	fclose(potion5);
	fclose(potion6);
	fclose(sp1);
	fclose(sp2);
	fclose(sp3);
	fclose(sp4);
	fclose(sp5);
	fclose(sp6);
	fclose(fame);
	for (int i = 0; i < 6; i++)
		fclose(achieve[i]);
}

void DataManager::potionPrice()
{
	FILE *potionPrice;
	for (int i = 0; i < 12; i++)
	{
		fopen_s(&potionPrice, "Data/potionPrice.txt", "rt");
		fscanf(potionPrice, "%d ", &pPrice[i]);
		fclose(potionPrice);
		pPrice[i] += rand() % 20 - 10;
		fopen_s(&potionPrice, "Data/potionPrice.txt", "wt");
		fprintf(potionPrice, "%d ", pPrice[i]);
		fclose(potionPrice);
	}
}

void DataManager::FameUpdate(int a, int b)
{
	float c;
	int d;
	c = b / 10;
	d = rand() % 10 + 1 * 10;
	Dfame += d*c;
	Save();
}