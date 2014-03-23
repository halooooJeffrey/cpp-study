#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
class BigInt
{
public:
	BigInt();
	void set();
	bool operator <(const BigInt &bigInt);
	bool operator >(const BigInt &bigInt);
	bool operator ==(const BigInt &bigInt);
	bool operator !=(const BigInt &bigInt);
	friend BigInt & operator +(BigInt &, BigInt &);
	friend BigInt & operator -(BigInt &, BigInt &);
	friend BigInt & operator *(BigInt &, BigInt &);
	friend BigInt & operator /(BigInt &, BigInt &);
	friend ostream& operator<<(ostream&,BigInt&);
	friend istream& operator<<(istream&,BigInt&);
private:
	int len;
	static const int MAXNUM = 200;
	int integer[MAXNUM];
	char flag;
};
BigInt result;
BigInt::BigInt()
{
	len = 0;
	memset(integer, 0, sizeof(int) * 100);
	flag = '+';
}
void BigInt::set()
{
	string s;
	cin >> s;
	len = s.length();
	flag = '+';
	for (int i = len - 1, j = 0; i >= 0; i--){
		integer[j] = s.at(i) - '0';
		++j;
	}
}
bool BigInt::operator >(const BigInt &bigInt)
{
	if (len < bigInt.len) return false;
	else if (len == bigInt.len){
		for (int i = len - 1; i >= 0; i--){
			if (integer[i] < bigInt.integer[i])
				return false;
			if (integer[i] > bigInt.integer[i])
				return true;
		}
	}
	else
		return true;
}
bool BigInt::operator ==(const BigInt &bigInt)
{
	if (len != bigInt.len) return false;
	else{
		for (int i = len - 1; i >= 0; i--){
			if (integer[i] != bigInt.integer[i])
				return false;
		}
		return true;
	}
}
bool BigInt::operator !=(const BigInt &bigInt)
{
	if ((*this) == bigInt) return false;
	else return true;
}
bool BigInt::operator <(const BigInt &bigInt)
{
	if ((*this) == bigInt || (*this) > bigInt)
		return false;
	else
		return true;
}
BigInt & operator +(BigInt &d1, BigInt &d2)
{
	int addtion = 0;
	int maxLen = (d1.len >= d2.len) ? d1.len : d2.len;
	for (int i = 0; i < maxLen; i++){
		result.integer[i] = (d1.integer[i] + d2.integer[i] + addtion) % 10;
		addtion = (d1.integer[i] + d2.integer[i] + addtion) / 10;
	}
	result.integer[maxLen] = addtion;
	if (result.integer[maxLen] == 0)
		result.len = maxLen;
	else
		result.len = maxLen + 1;
	return result;
}
BigInt & operator -(BigInt &d1, BigInt &d2)
{
	int maxLen = (d1.len >= d2.len) ? d1.len : d2.len;
	if (d1 == d2){
		result.len = 1;
		return result;
	}
	else if (d1 < d2){
		result.flag = '-';
		for (int i = 0; i < maxLen; i++){
			if (d2.integer[i] < d1.integer[i]){
				result.integer[i] = d2.integer[i] + 10 - d1.integer[i];
				int j = i + 1;
				d2.integer[j]--;
			}
			else
				result.integer[i] = d2.integer[i] - d1.integer[i];
		}
	}
	else{
		for (int i = 0; i < maxLen; i++){
			if (d1.integer[i] < d2.integer[i]){
				result.integer[i] = d1.integer[i] + 10 - d2.integer[i];
				int j = i + 1;
				d1.integer[j]--;
			}
			else
				result.integer[i] = d1.integer[i] - d2.integer[i];
		}
	}
	result.len = maxLen;
	for (int i = maxLen - 1; i >= 0; i--){
		if (result.integer[i] != 0)
			break;
		else
			result.len--;
	}
	return result;
}
BigInt & operator *(BigInt &d1, BigInt &d2)
{
	for (int i = 0; i < d1.len; i++){
		for (int j = 0; j < d2.len; j++){
			result.integer[i + j] += d1.integer[i] * d2.integer[j];
		}
	}
	result.len = d1.len + d2.len;
	for (int i = 0; i < (d1.len + d2.len); i++){
		if (result.integer[i] > 10){
			int temp = result.integer[i];
			result.integer[i] = temp % 10;
			int j = i + 1;
			result.integer[j] += temp / 10;
		}
	}
	for (int i = result.len - 1; i >= 0; i--){
		if (result.integer[i] != 0)
			break;
		else
			result.len--;
	}
	return result;
}
BigInt & operator /(BigInt & d1, BigInt & d2)
{

	if (d2 > d1){
		result.len = 1;
		return result;
	}
	else if (d2 == d1){
		result.len = 1;
		result.integer[0] = 1;
		return result;
	}
	else{
		BigInt temp1, temp2, temp3, temp, tempResult;
		int count = d1.len - d2.len;
		temp1.len = count + 1;
		temp1.integer[count] = 1;
		temp2 = d2 * temp1;
		if (d1 < temp2){
			temp1.len = count;
			temp1.integer[count - 1] = 1;
			temp2 = temp;
			result = temp;
			temp2 = d2 * temp1;
		}
		tempResult.len = temp1.len;
		int k = 0;
		temp3 = d1;
		while (temp1.len >= 1){
			while (temp3 > temp2){
				temp3 = temp3 - temp2;
				k++;
				result = temp;
			}
			tempResult.integer[temp1.len - 1] = k;
			temp1.len--;
			if (temp1.len == 0)
				break;
			temp1.integer[temp1.len - 1] = 1;
			temp2 = d2 * temp1;
			k = 0;
			result = temp;
		}
		tempResult.integer[0] = k;
		result = tempResult;
		return result;
	}
}
ostream& operator<<(ostream &out,BigInt &d)
{
	if (d.flag == '-')
		out << d.flag;
	for (int i = d.len - 1; i >= 0; i--)
		out << d.integer[i];
	return out;
}
int main()
{
	BigInt a, b, c;
	char option;
	a.set();
	cin >> option;
	b.set();
	switch(option)
	{
		case('+'):
			c = a + b;
			break;
		case('-'):
			c = a - b;
			break;
		case('*'):
			c = a * b;
			break;
		case('/'):
			c = a / b;
	}
	cout << c << endl;
	return 0;
}
