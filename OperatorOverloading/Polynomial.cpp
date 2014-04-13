#include <iostream>
using namespace std;
class Polynomial
{
public:
	Polynomial();
	Polynomial(double coefs[], int exps[], int size);
	Polynomial(const Polynomial &);
	~Polynomial();
	void display();
	Polynomial & operator =(const Polynomial &);
	int degree() const;
	double evaluate(double x) const;
	bool operator ==(const Polynomial &) const;
	bool operator !=(const Polynomial &) const;
	Polynomial operator +(const Polynomial &) const;
	Polynomial operator -(const Polynomial &) const;
	Polynomial operator *(const Polynomial &) const;
	Polynomial& operator +=(const Polynomial &);
	Polynomial& operator -=(const Polynomial &);
	Polynomial& operator *=(const Polynomial &);
private:
	double *pCoefs;
	int *pExps;
	int numOfItems;
	int volume;
};
Polynomial::Polynomial()
{
	pCoefs = NULL;
	pExps = NULL;
	numOfItems = 0;
	volume = 0;
}
//规定数数组和系数数组是按顺序输入的
Polynomial::Polynomial(double coefs[], int exps[], int size)
{
	numOfItems = size;
	volume = size;
	pCoefs = new double[numOfItems];
	pExps = new int[numOfItems];
	for (int i = 0; i < numOfItems; i++){
		pCoefs[i] = coefs[i];
		pExps[i] = exps[i];
	}
}
Polynomial::Polynomial(const Polynomial &p)
{
	numOfItems = p.numOfItems;
	volume = p.volume;
	pCoefs = new double[numOfItems];
	pExps = new int[numOfItems];
	for (int i = 0; i < numOfItems; i++){
		pCoefs[i] = p.pCoefs[i];
		pExps[i] = p.pExps[i];
	}
}
Polynomial::~Polynomial()
{
	if (pCoefs != NULL){
		delete []pCoefs;
		pCoefs = NULL;
	}
	if (pExps != NULL){
		delete []pExps;
		pExps = NULL;
	}
	numOfItems = 0;
	volume = 0;
}
Polynomial & Polynomial::operator =(const Polynomial &p)
{
	if (&p == this) return *this;
	numOfItems = p.numOfItems;
	volume = p.volume;
	delete []pCoefs;
	delete []pExps;
	pCoefs = new double[numOfItems];
	pExps = new int[numOfItems];
	for (int i = 0; i < numOfItems; i++){
		pCoefs[i] = p.pCoefs[i];
		pExps[i] = p.pExps[i];
	}
	return *this;
}
void Polynomial::display()
{
	//指数数组里的元素从小到大排列,对应的系数随元素重新排列
	for (int i = 0; i < numOfItems; i++){
		for (int j = i + 1; j < numOfItems; j++){
			if (pExps[j] < pExps[i]){
				int temp1 = pExps[i];
				pExps[i] = pExps[j];
				pExps[j] = temp1;
				double temp2 = pCoefs[i];
				pCoefs[i] = pCoefs[j];
				pCoefs[j] = temp2;
			}
		}
	}
	for (int i = 0; i < numOfItems; i++){
		if (pCoefs[i] > 0 && i != 0){
			if (pCoefs[i] == 1)
				cout << "+";
			else
				cout << "+" << pCoefs[i];
			if (pExps[i] == 0)
				;
			else if(pExps[i] == 1)
				cout << "x";
			else
				cout << "x^" << pExps[i];
		}
		else if (pCoefs[i] == 0)
			;
		else{
			cout << pCoefs[i];
			if (pExps[i] == 0)
				;
			else if(pExps[i] == 1)
				cout << "x";
			else
				cout << "x^" << pExps[i];
		}
	}
	cout << endl;
}
int Polynomial::degree() const
{
	if (numOfItems != 0)
		return pExps[numOfItems - 1];
	else
		return 0;
}
double Polynomial::evaluate(double x) const
{
	double sum = 0;
	if (x == 0)
		return sum;
	else{
		for (int i = 0; i < numOfItems; i++){
			double temp = pCoefs[i];
			for (int j = 0; j < pExps[i]; j++)
				temp *= x;
			sum += temp;
		}
	}
	return sum;
}
bool Polynomial::operator ==(const Polynomial &p) const
{
	if (numOfItems != p.numOfItems) return false;
	else{
		for (int i = 0; i < numOfItems; i++){
			if (pCoefs[i] != p.pCoefs[i] || pExps[i] != p.pExps[i])
				return false;
		}
		return true;
	}
}
bool Polynomial::operator !=(const Polynomial &p) const
{
	return !(*this == p);
}
Polynomial Polynomial::operator +(const Polynomial &p) const
{
	Polynomial temp;
	temp = *this;
	int i, j;
	for (i = 0; i < p.numOfItems; i++){
		for (j = 0; j < temp.numOfItems; j++){
			if (temp.pExps[j] == p.pExps[i]){
				temp.pCoefs[j] += p.pCoefs[i];
				break;	//当找到对应指数时，就不用再比了
			}
		}
		//没有找到对应的指数，说明p中的指数在本多项式中不存在，需要扩大指数数组，将没有的存入
		if (j == temp.numOfItems){
			if (temp.numOfItems == temp.volume)
				temp.volume += 10;
			int *tempExps = new int[temp.volume];	//增加效率，一次性扩大10个
			double *tempCoefs = new double[temp.volume];
			for (int k = 0; k < temp.numOfItems; k++){
				tempExps[k] = temp.pExps[k];					//将原来数组里的值复制过去
				tempCoefs[k] = temp.pCoefs[k];
			}
			delete []temp.pExps;
			delete []temp.pCoefs;
			temp.pExps = tempExps;
			temp.pCoefs = tempCoefs;
			temp.pExps[temp.numOfItems] = p.pExps[i];			//将没有的系数和指数加上,同时也要扩大sumOfItems
			temp.pCoefs[temp.numOfItems] = p.pCoefs[i];
			temp.numOfItems++;
		}
	}
	return temp;
}
Polynomial Polynomial::operator -(const Polynomial &p) const
{
	Polynomial temp;
	temp = *this;
	int i, j;
	for (i = 0; i < p.numOfItems; i++){
		for (j = 0; j < temp.numOfItems; j++){
			if (temp.pExps[j] == p.pExps[i]){
				temp.pCoefs[j] -= p.pCoefs[i];
				break;
			}
		}
		if (j == temp.numOfItems){
			if (temp.numOfItems == temp.volume)
				temp.volume += 10;
			int *tempExps = new int[temp.volume];
			double *tempCoefs = new double[temp.volume];
			for (int k = 0; k < temp.numOfItems; k++){
				tempExps[k] = temp.pExps[k];
				tempCoefs[k] = temp.pCoefs[k];
			}
			delete []temp.pExps;
			delete []temp.pCoefs;
			temp.pExps = tempExps;
			temp.pCoefs = tempCoefs;
			temp.pExps[temp.numOfItems] = p.pExps[i];	//为什么temp.numOfItems++有错误
			temp.pCoefs[temp.numOfItems] = (-p.pCoefs[i]);
			temp.numOfItems++;
		}
	}
	return temp;
}
Polynomial Polynomial::operator *(const Polynomial &p) const
{
	Polynomial temp, q;
	q = p;
	for (int i = 0; i < numOfItems; i++){
		for (int j = 0; j < p.numOfItems; j++){
			q.pCoefs[j] = pCoefs[i] * p.pCoefs[j];
			q.pExps[j] = pExps[i] + p.pExps[j];
		}
		temp = temp + q; 
	}
	return temp;
}
Polynomial& Polynomial::operator +=(const Polynomial &p)
{
	*this = *this + p;
	return *this;
}
Polynomial& Polynomial::operator -=(const Polynomial &p)
{
	*this = *this - p;
	return *this;
}
Polynomial& Polynomial::operator *=(const Polynomial &p)
{
	*this = *this * p;
	return *this;
}
int main(){
	int size1,size2;
	cout << "多项式1" << endl;
	cout << "请输入项数: ";
	cin >> size1;
	double *coefs1 = new double[size1];
	int *exps1 = new int[size1];
	cout << "请输入系数: ";
	for (int i = 0; i < size1; i++)
		cin >> coefs1[i];
	cout << "请输入指数: ";
	for (int i = 0; i < size1; i++)
		cin >> exps1[i];
	cout << "多项式2" << endl;
	cout << "请输入项数: ";
	cin >> size2;
	double *coefs2 = new double[size2];
	int *exps2 = new int[size2];
	cout << "请输入系数: ";
	for (int i = 0; i < size2; i++)
		cin >> coefs2[i];
	cout << "请输入指数: ";
	for (int i = 0; i < size2; i++)
		cin >> exps2[i];
	Polynomial p1(coefs1, exps1, size1);
	Polynomial p2(coefs2, exps2, size2);
	cout << "多项式1: ";
	p1.display();
	cout << "多项式2: ";
	p2.display();
	if (p1 == p2)
		cout << "多项式1与多项式2相等" << endl;
	else
		cout << "多项式1与多项式2不相等" << endl;
	Polynomial p3;
	p3 = p1 + p2;
	cout << "多项式1加多项式2为: ";
	p3.display();
	Polynomial p4;
	p4 = p1 - p2;
	cout << "多项式1减多项式2为: ";
	p4.display();
	cout << "当x=2时，多项式1的值为: ";
	cout << p1.evaluate(2) << endl;
	Polynomial p5;
	p5 = p1 * p2;
	cout << "多项式1乘多项式2为: ";
	p5.display();
	cout << "多项式1 += 多项式2: ";
	p1 += p2;
	p1.display();
	cout << "多项式1 -= 多项式2(此时应该还是原来的多项式1): ";
	p1 -= p2;
	p1.display();
	cout << "多项式1 *= 多项式2: ";
	p1 *= p2;
	p1.display();
	return 0;

}