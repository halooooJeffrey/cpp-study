/*利用动态数组实现对键盘输入的数（个数不限）进行排序*/

/*当可以输入个数*/
#include <iostream>
using namespace std;
void sort(int *, int);

int main()
{
    int n;  /*输入数组的个数*/
    cin >> n;
    int *p = new int[n];    /*创建一个动态数组，数组的大小为n*/
    for (int i=0; i < n; i++)   /*给数组的每个元素从键盘赋值*/
        cin >> *(p+i);
    sort(p, n); /*排序*/
    cout << "排序结果是:";
    for (int i=0; i < n; i++)   /*输出排序结果*/
        cout << *(p+i) << ' ';
    cout << endl;
    delere[] p;
}

/*排序函数*/
void sort(int *p, int n)
{
    for (int min_index = 0; min_index < n; min_index++)
    {
        for (int i=min_index; i < n; i++)
        {
            if (*(p + i) < *(p + min_index))
            {
                int temp;
                temp = *(p + i);
                *(p + i) = *(p + min_index);
                *(p + min_index) = temp;
            }
        }
    }
}

/*当不可以输入个数，以-1结束*/
#include <iostream>
using namespace std;
void sort(int *, int);

int main()
{
    int len = 20; /*设定初始大小为20*/
    const int increment = 10; /*动态数组扩充的增量大小*/
    int *p = new int[len];
    int count = 0;  /*输入的个数进行计数*/
    int n;  /*存储的数*/
    cin >> n;   /*输入第一个数*/
    while ( n != -1)    /*循环，直到输入-1*/
    {
        if (count >= len)   /*如果计数超过了数组大小就要创建更大的数组*/
        {
            len += increment;   /*新的数组大小*/
            int *q = new int[len];  /*创建新的数组*/
            for (int i=0; i < len; i++)
                q[i] = p[i];    /*将原来数组中的元素复制到新的数组*/
            delete[] p; /*撤销原来的数组*/
            p = q;  /*p指向新的数组*/
        }
        p[count] = n;   /*存储*/
        count++;    /*输入的数加1*/
        cin >> n;   /*输入下一个数*/
    }
    sort(p,count);  /*排序*/
    for (int i=0; i < count; i++)
        cout << p[i];
    delete[] p;
}

/*排序函数*/
void sort(int *p, int n)
{
    for (int min_index = 0; min_index < n; min_index++)
    {
        for (int i=min_index; i < n; i++)
        {
            if (*(p + i) < *(p + min_index))
            {
                int temp;
                temp = *(p + i);
                *(p + i) = *(p + min_index);
                *(p + min_index) = temp;
            }
        }
    }
}
