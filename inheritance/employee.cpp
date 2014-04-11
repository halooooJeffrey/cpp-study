#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class CPerson
{
protected:
	char *m_szName;
	char *m_szId;
	int m_nSex;
	int m_nAge;
public:
	CPerson(char *name, char *id, int sex, int age);
	void Show1();
	~CPerson();
};
CPerson::CPerson(char *name, char *id, int sex, int age){
	m_szName = new char[strlen(name) + 1];
	memcpy(m_szName, name, sizeof(char) * (strlen(name) + 1));
	m_szId = new char[strlen(id) + 1];
	memcpy(m_szId, id, sizeof(char) * (strlen(id) + 1));
	m_nSex = sex;
	m_nAge = age;
}
void CPerson::Show1(){
	cout << setw(10) << m_szName << setw(25) << m_szId;
	if (m_nSex == 0)
		cout << setw(7) << "women";
	else
		cout << setw(7) << "man";
	cout << setw(5) << m_nAge << endl;
}
CPerson::~CPerson(){
	delete []m_szName;
	m_szName = NULL;
	delete []m_szId;
	m_szId = NULL;
}
class CEmployee: public CPerson
{
private:
	char *m_szDepartment;
	float m_Salary;
public:
	CEmployee(char *name, char *id, int sex, int age, char *department, float salary);
	void Show2();
	~CEmployee();
};
CEmployee::CEmployee(char *name, char *id, int sex, int age, char *department, float salary): CPerson(name, id, sex, age){
	m_szDepartment = new char[strlen(department) + 1];
	memcpy(m_szDepartment, department, sizeof(char) * (strlen(department) + 1));
	m_Salary = salary;
}
void CEmployee::Show2(){
	cout << setw(10) << "name" << setw(25) << "id" << setw(7) << "sex" << setw(5) << "age" << setw(12) << "department" << setw(10) << "salary" << endl;
	cout << setw(10) << m_szName << setw(25) << m_szId;
	if (m_nSex == 0)
		cout << setw(7) << "women";
	else
		cout << setw(7) << "man";
	cout << setw(5) << m_nAge;
	cout << setw(12) << m_szDepartment << setw(10) << m_Salary << endl;
}
CEmployee::~CEmployee(){
	delete []m_szDepartment;
	m_szDepartment = NULL;
}
int main(){
	char name[10], id[19], department[10];
	int sex, age;
	float salary;
	cout << "input employee's name, id, sex(0:women,1:man), age, department, salary:\n";
	cin >> name >> id >> sex >> age >> department >> salary;
	CEmployee employee1(name, id, sex, age, department, salary);
	employee1.Show2();
	return 0;
}