#include<iostream>

using namespace std;

void main()
{
	for(int i = 0;i<100;i++)
	{
		canculate_fibonacci_sequence(i);
	}	

}

//fibonacci sequence non-recursive implementation linear time complexity O(n)
void non_recursive_fibonacci_sequence(int n)
{
	int data = 0;

	if(n<0)
	{
		cout << "n必须>=0"<<endl;
		return ;
	}
	else if (n == 0 || n == 1)
	{
		data = n;
	}
	else
	{
		int pre_data1 = 1;
		int pre_data2 = 0;
		for(int i = 2; i<n; i++)
		{
			data = pre_data1 + pre_data2;
			pre_data2 = pre_data1;
			pre_data1 = data;
		}
	}

	cout <<"data == " << data;
}

//fibonacci sequence recursive implementation linear time complexity O(n)

void recursive_fibonacci_sequence(int n)
{
	int data = 0;
}
