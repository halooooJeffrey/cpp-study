#include <iostream>
#include <cstring>
using namespace std;
class Complex{
private:
	double r, i;
public:
	void operator =(char *p){
		int addPos, iPos, realDotPos = 0, imagDotPos = 0;
		double r1 = 0, r2 = 0, i1 = 0, i2 = 0;
		int len = strlen(p);
		for (int j = 0; j < len; j++){
			if (p[j] == '+')
				addPos = j;
			if (p[j] == 'i')
				iPos = j;
		}
		for (int j = 0; j < addPos; j++){
			if (p[j] == '.')
				realDotPos = j;
		}
		for (int j = addPos + 1; j < iPos; j++){
			if (p[j] == '.')
				imagDotPos = j;
		}
		if (realDotPos != 0){
			for (int j = 0; j < realDotPos; j++)
				r1 = r1 * 10 + (p[j] - '0');
			for (int j = addPos - 1; j > realDotPos; j--)
				r2 = r2 / 10 + (p[j] - '0');
			r2 = r2 / 10;
			r = r1 + r2;
		}
		else{
			for (int j = 0; j < addPos; j++)
				r1 = r1 * 10 + (p[j] - '0');
			r = r1;
		}
		if (imagDotPos != 0){
			for (int j = addPos + 1; j < imagDotPos; j++)
				i1 = i1 * 10 + (p[j] - '0');
			for (int j = iPos - 1; j > imagDotPos; j--)
				i2 = i2 / 10 + (p[j] - '0');
			i2 = i2 / 10;
			i = i1 + i2;
		}
		else{
			for (int j = addPos + 1; j < iPos; j++)
				i1 = i1 * 10 + (p[j] - '0');
			i = i1;
		}

	}
	void Print(){
		cout << r << "+" << i << "i" << endl;
	}
};

int main(){
	Complex a;
	a = "3.87+4.76i";
	a.Print();
	a = "12345.7+26.382i";
	a.Print();
	return 0;
}