#include <iostream>
#include <cstring>
using namespace std;
class CArray
{
public:
	CArray(int s = 0);
	CArray(const CArray &a);
	~CArray();
	void push_back(int i);
	int length(){return size;}
	CArray & operator =(const CArray &a);
	int & operator [](int i);
private:
	int size;
	int *ptr;
};
CArray::CArray(int s):size(s)
{
	if (s == 0)
		ptr = NULL;
	else 
		ptr = new int[s];
}
CArray::CArray(const CArray &a)
{
	if (a.ptr == NULL){
		ptr = NULL;
		size = 0;
		return;
	}
	ptr = new int[a.size];
	memcpy(ptr, a.ptr, sizeof(int) * a.size);
	size = a.size;
}
CArray::~CArray()
{
	if (ptr)
		delete []ptr;
}
void CArray::push_back(int i)
{
	if (ptr){
		int *tempPtr = new int[size + 1];
		memcpy (tempPtr, ptr, sizeof(int) * size);
		delete []ptr;
		ptr = tempPtr;
	}
	else
		ptr = new int[1];
	ptr[size] = i;
	size++;
}
CArray & CArray::operator =(const CArray &a)
{
	if (ptr == a.ptr)
		return *this;
	if (a.ptr == NULL){
		if (ptr) 
			delete []ptr;
		ptr = NULL;
		size = 0;
		return *this;
	}
	if (size < a.size){
		if (ptr)	
			delete []ptr;
		ptr = new int(a.size);
	}
	memcpy(ptr, a.ptr, sizeof(int) * a.size);
	size = a.size;
	return *this;
}
int & CArray::operator [](int i)
{
	return ptr[i];
}
int main()
{
	CArray a;
	for (int i = 0; i < 5; ++i)
		a.push_back(i);
	CArray a2, a3;
	a2 = a;
	for (int i = 0; i < a.length(); ++i)
		cout << a2[i] << " ";
	a2 = a3;
	for (int i = 0; i < a2.length(); ++i)
		cout << a2[i] << " ";
	cout << endl;
	a[3] = 100;
	CArray a4(a);
	for (int i = 0; i < a4.length(); ++i)
		cout << a4[i] << " ";
	return 0;
}