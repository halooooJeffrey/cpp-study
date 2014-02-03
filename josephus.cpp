#include <iostream>
using namespace std;

int main()
{
	const int N = 11,M = 3;
	int num_of_children_remained = N,index,count;
	bool in_circle[N];
	for (index=0;index < N;index++)
		in_circle[index] = true;

	index = N - 1;
	while (num_of_children_remained != 1)
	{
		count = 0;
		while (count < M)
		{
			index = (index + 1) % N;
			if (in_circle[index])
				count ++;
		}
		in_circle[index] = false;
		num_of_children_remained--;
	}

	for (index = 0;index < N;index++)
	{
		if (in_circle[index])
			break;
	}

	cout << "The winner's number is :" << index <<endl;
	return 0;
}
