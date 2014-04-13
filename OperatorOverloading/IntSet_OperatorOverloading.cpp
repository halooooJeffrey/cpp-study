#include "IntSet.h"
#include <iostream>
using namespace std;
IntSet::IntSet(){
	size = 0;
	volume = 10;
	data = new int[volume];
}
IntSet::IntSet(const IntSet &s){
	data = new int[s.volume];
	volume = s.volume;
	size = s.size;
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
}
IntSet::~IntSet(){
	delete []data;
	data = NULL;
}
IntSet& IntSet::operator =(const IntSet &s){
	delete []data;
	size = s.size;
	volume = s.volume;
	data = new int[volume];
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
	return *this;
}
bool IntSet::is_element(int e) const {
	for (int i = 0; i < size; i++){
		if (data[i] == e)
			return true;
	}
	return false;
}
IntSet& IntSet::operator +=(int e){
	if (this->is_element(e))
		return *this;
	else{
		if (size < volume){
			data[size] = e;
			++size;
		}
		else{
			volume += 10;
			int *dataTemp = new int[volume];
			for (int i = 0; i < size; i++)
				dataTemp[i] = data[i];
			delete data;
			data = dataTemp;
			data[size] = e;
			++size;
		}
	}
	return *this;
}
IntSet& IntSet::operator -=(int e){
	if (this->is_element(e)){
		int pos;
		for (int i = 0; i < size; i++){
			if (data[i] == e)
				pos = i;
		}
		for (int i = pos; i < size; i++)
			data[i] = data[i + 1];
		--size;
		return *this;
	}
	else
		cout << "There is nothing to delete.";
}
bool IntSet::operator <=(const IntSet &s){
	if (size > s.size)
		return false;
	else{
		for (int i = 0; i < size; i++){
			if (!s.is_element(data[i]))
				return false;
		}
		return true;
	}
}
bool IntSet::operator ==(const IntSet &s){
	return (*this <= s && size == s.size);
}
bool IntSet::operator !=(const IntSet &s){
	return !(*this == s);
}
IntSet IntSet::operator |(const IntSet &s){
	IntSet temp;
	temp = *this;
	for (int i = 0; i < s.size; i++){
		if (!this->is_element(s.data[i]))
			temp += s.data[i];
	}
	return temp;
}
IntSet IntSet::operator &(const IntSet &s){
	IntSet temp;
	for (int i = 0; i < size; i++){
		if (s.is_element(data[i]))
			temp += data[i];
	}
	return temp;
}
IntSet IntSet::operator -(const IntSet &s){
	IntSet temp1, temp2, temp3;
	temp1 = *this;
	temp2 = s;
	if (temp2 <= temp1){
		if (temp1.size == temp2.size){
			cout << "空集" << endl;
			exit(-1);
		}
		else{
			for (int i = 0; i < temp1.size; i++){
				if (!temp2.is_element(temp1.data[i]))
					temp3 += temp1.data[i];
			}
		}
		return temp3;
	}
	else{
		cout << "无法运算" << endl;
		exit(-1);
	}
}
void IntSet::display(){
	if (size == 0)
		cout << "空集" << endl;
	else{
		for (int i = 0; i < size; i++)
			cout << data[i] << '	';
		cout << endl;
	}
}


