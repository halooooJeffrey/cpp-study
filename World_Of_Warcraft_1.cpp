#include <iostream>
using namespace std;

class Headquarter
{
public:
	int wholeLifeValue;
	int icemanLifeValue;
	int lionLifeValue;
	int wolfLifeValue;
	int ninjaLifeValue;
	int dragonLifeValue;
	int time;
	int icemanNumber;
	int lionNumber;
	int wolfNumber;
	int ninjaNumber;
	int dragonNumber;
	int warriorNumber;
};
class Red: public Headquarter
{
public:
	int stopLoop;
	Red(){
		stopLoop = 1;
		redWarrior = iceman;
		time = 0;
		warriorNumber = 1;
		icemanNumber = 0;
		lionNumber = 0;
		wolfNumber = 0;
		ninjaNumber = 0;
		dragonNumber = 0;
	}
	void show(){cout << wholeLifeValue << icemanLifeValue << lionLifeValue << wolfLifeValue << ninjaLifeValue << dragonLifeValue << endl;}
	void produceWarrior();
	friend void setSpecialInfo();
protected:
	enum Warrior {iceman, lion, wolf, ninja, dragon};
	Warrior redWarrior;
};

class Blue: public Headquarter
{
public:
	int stopLoop;
	Blue(){
		stopLoop = 1;
		blueWarrior = lion;
		time = 0;
		warriorNumber = 1;
		icemanNumber = 0;
		lionNumber = 0;
		wolfNumber = 0;
		ninjaNumber = 0;
		dragonNumber = 0;
	}
	void show(){cout << wholeLifeValue << icemanLifeValue << lionLifeValue << wolfLifeValue << ninjaLifeValue << dragonLifeValue << endl;}
	void produceWarrior();
	friend void setSpecialInfo();
protected:
	enum Warrior {lion, dragon, ninja, iceman, wolf};
	Warrior blueWarrior;
};

void Red::produceWarrior()
{
	int flag = 1;
	int minLifeValue = icemanLifeValue;
	if (minLifeValue > lionLifeValue)
		minLifeValue = lionLifeValue;
	if (minLifeValue > wolfLifeValue)
		minLifeValue = wolfLifeValue;
	if (minLifeValue > ninjaLifeValue)
		minLifeValue = ninjaLifeValue;
	if (minLifeValue > dragonLifeValue)
		minLifeValue = dragonLifeValue;
	if (time < 10)
		cout << "00" << time << " ";
	else
		cout << "0" << time << " ";
	while (flag){
		if (wholeLifeValue < minLifeValue){
			cout << "red headquarter stops making warriors" << endl;
			stopLoop = 0;
			break;
		}
		switch(redWarrior){
		case(iceman):
			if (wholeLifeValue < icemanLifeValue){
				redWarrior = Warrior(redWarrior + 1);
				break;
			}
			cout << "red iceman " << warriorNumber << " born with strength " << icemanLifeValue
				<< "," << ++icemanNumber << " iceman in red headquarter" << endl;
			wholeLifeValue -= icemanLifeValue;
			redWarrior = Warrior(redWarrior + 1);
			flag = 0;
			break;
		case(lion):
			if (wholeLifeValue < lionLifeValue){
				redWarrior = Warrior(redWarrior + 1);
				break;
			}
			cout << "red lion " << warriorNumber << " born with strength " << lionLifeValue
				<< "," << ++lionNumber << " lion in red headquarter" << endl;
			wholeLifeValue -= lionLifeValue;
			redWarrior = Warrior(redWarrior + 1);
			flag = 0;
			break;
		case(wolf):
			if (wholeLifeValue < wolfLifeValue){
				redWarrior = Warrior(redWarrior + 1);
				break;
			}
			cout << "red wolf " << warriorNumber << " born with strength " << wolfLifeValue
				<< "," << ++wolfNumber << " wolf in red headquarter" << endl;
			wholeLifeValue -= wolfLifeValue;
			redWarrior = Warrior(redWarrior + 1);
			flag = 0;
			break;
		case(ninja):
			if (wholeLifeValue < ninjaLifeValue){
				redWarrior = Warrior(redWarrior + 1);
				break;
			}
			cout << "red ninja " << warriorNumber << " born with strength " << ninjaLifeValue
				<< "," << ++ninjaNumber << " ninja in red headquarter" << endl;
			wholeLifeValue -= ninjaLifeValue;
			redWarrior = Warrior(redWarrior + 1);
			flag = 0;
			break;
		case(dragon):
			if (wholeLifeValue < dragonLifeValue){
				redWarrior = iceman;
				break;
			}
			cout << "red dragon " << warriorNumber << " born with strength " << dragonLifeValue
				<< "," << ++dragonNumber << " dragon in red headquarter" << endl;
			wholeLifeValue -= dragonLifeValue;
			redWarrior = iceman;
			flag = 0;
			break;
		}
	}
	time++;
	warriorNumber++;
}

void Blue::produceWarrior()
{
	int flag = 1;
	int minLifeValue = icemanLifeValue;
	if (minLifeValue > lionLifeValue)
		minLifeValue = lionLifeValue;
	if (minLifeValue > wolfLifeValue)
		minLifeValue = wolfLifeValue;
	if (minLifeValue > ninjaLifeValue)
		minLifeValue = ninjaLifeValue;
	if (minLifeValue > dragonLifeValue)
		minLifeValue = dragonLifeValue;
	if (time < 10)
		cout << "00" << time << " ";
	else
		cout << "0" << time << " ";
	while (flag){
		if (wholeLifeValue < minLifeValue){
			cout << "blue headquarter stops making warriors" << endl;
			stopLoop = 0;
			break;
		}
		switch(blueWarrior){
		case(lion):
			if (wholeLifeValue < lionLifeValue){
				blueWarrior = Warrior(blueWarrior + 1);
				break;
			}
			cout << "blue lion " << warriorNumber << " born with strength " << lionLifeValue
				<< "," << ++lionNumber << " lion in blue headquarter" << endl;
			wholeLifeValue -= lionLifeValue;
			blueWarrior = Warrior(blueWarrior + 1);
			flag = 0;
			break;
		case(dragon):
			if (wholeLifeValue < dragonLifeValue){
				blueWarrior = Warrior(blueWarrior + 1);
				break;
			}
			cout << "blue dragon " << warriorNumber << " born with strength " << dragonLifeValue
				<< "," << ++dragonNumber << " dragon in blue headquarter" << endl;
			wholeLifeValue -= dragonLifeValue;
			blueWarrior = Warrior(blueWarrior + 1);
			flag = 0;
			break;
		case(ninja):
			if (wholeLifeValue < ninjaLifeValue){
				blueWarrior = Warrior(blueWarrior + 1);
				break;
			}
			cout << "blue ninja " << warriorNumber << " born with strength " << ninjaLifeValue
				<< "," << ++ninjaNumber << " ninja in blue headquarter" << endl;
			wholeLifeValue -= ninjaLifeValue;
			blueWarrior = Warrior(blueWarrior + 1);
			flag = 0;
			break;
		case(iceman):
			if (wholeLifeValue < icemanLifeValue){
				blueWarrior = Warrior(blueWarrior + 1);
				break;
			}
			cout << "blue iceman " << warriorNumber << " born with strength " << icemanLifeValue
				<< "," << ++icemanNumber << " iceman in blue headquarter" << endl;
			wholeLifeValue -= icemanLifeValue;
			blueWarrior = Warrior(blueWarrior + 1);
			flag = 0;
			break;
		case(wolf):
			if (wholeLifeValue < wolfLifeValue){
				blueWarrior = lion;
				break;
			}
			cout << "blue wolf " << warriorNumber << " born with strength " << wolfLifeValue
				<< "," << ++wolfNumber << " wolf in blue headquarter" << endl;
			wholeLifeValue -= wolfLifeValue;
			blueWarrior = lion;
			flag = 0;
			break;
		}
	}
	time++;
	warriorNumber++;
}

int main()
{
	int caseNumber;
	int i;
	cin >> caseNumber;
	for (i = 1;i <= caseNumber; i++){
	Red red;
	Blue blue;
	int tempWholeLifeValue;
	int tempIcemanLifeValue;
	int tempLionLifeValue;
	int tempWolfLifeValue;
	int tempNinjaLifeValue;
	int tempDragonLifeValue;
	cin >> tempWholeLifeValue >> tempDragonLifeValue >> tempNinjaLifeValue >> tempIcemanLifeValue
		>> tempLionLifeValue >> tempWolfLifeValue;
	red.wholeLifeValue = tempWholeLifeValue;
	blue.wholeLifeValue = tempWholeLifeValue;
	red.dragonLifeValue = tempDragonLifeValue;
	blue.dragonLifeValue = tempDragonLifeValue;
	red.ninjaLifeValue = tempNinjaLifeValue;
	blue.ninjaLifeValue = tempNinjaLifeValue;
	red.icemanLifeValue = tempIcemanLifeValue;
	blue.icemanLifeValue = tempIcemanLifeValue;
	red.lionLifeValue = tempLionLifeValue;
	blue.lionLifeValue = tempLionLifeValue;
	red.wolfLifeValue = tempWolfLifeValue;
	blue.wolfLifeValue = tempWolfLifeValue;
	cout << "Case:" << i << endl;
	while (red.stopLoop || blue.stopLoop){
		if (red.stopLoop){
			red.produceWarrior();
			if (blue.stopLoop)
				blue.produceWarrior();
		}
		else{
			if (blue.stopLoop)
				blue.produceWarrior();
		}
	}
	}
	return 0;
}