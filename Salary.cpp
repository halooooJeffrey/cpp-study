/*=====================================================
*Copyright:Fang Jie
*
*Author: Fang Jie
*
*Date:2014-02-23
*
*Description:设计一个工资类，其中的数据成员包括职工人数和工资数，
*	     动态分配内存来输入职工工资，加钱后进行排序后输出。
*
========================================================*/
#include <iostream>
#include <cstdio>
using namespace std;

//定义一个工资类
class Salary
{
public:
    void set_salary();		//设置工资
    void add_salary(int);	//加工资
    void sort_salary();	//工资排序
    void output_salary();	//输出工资
private:
    double *salary;		//数据成员为指针类型，动态分配内存
    int number;		//职工数
};

void Salary::set_salary()
{
    int max_len = 20;				//初始的最大容量
    const int increment = 10;			//每次增加的容量
    double n;			
    salary = new double[max_len];		//分配内存
    int count = 0;				//计数
    cin >> n;
    while (n != -1)				//没有输入完毕
    {
        if(count >= max_len)			//当内存不够用时进行再分配
        {
            max_len += increment;		//内存扩大
            double *p = new double[max_len];	//创立新的指针指向一块新分配的内存
            for (int i = 0; i < count; i++)	//将原来内存中的内容复制到新的内存中
                p[i] = salary[i];
            delete []salary;			//删除原来的内存
            salary = p;				//指向新的内存
            
        }
        salary[count] = n;			//输入赋值
        count++;				//计数加1
        cin >> n;
    }
	number = count;
}

void Salary::add_salary(int n)		//工资加n
{
    for (int i = 0; i < number; i++)
        salary[i] = salary[i] + n;
}

void Salary::sort_salary()			//进行工资排序
{
    int min_index;
    double temp;
    for (min_index = 0; min_index < number; min_index++)
    {
        for (int i = min_index; i < number; i++)
        {
            if (salary[i] < salary[min_index])
            {
                temp = salary[i];
                salary[i] = salary[min_index];
                salary[min_index] = temp;
            }
        }
    }
}

void Salary::output_salary()			//输出工资
{
    for (int i = 0; i < number; i++)
        cout << salary[i] << ' ';
    cout << endl;
}

int main()
{
    Salary salary;
	cout << "enter salary:" << endl;
    salary.set_salary();
    salary.add_salary(100);
    salary.sort_salary();
    salary.output_salary();
}
