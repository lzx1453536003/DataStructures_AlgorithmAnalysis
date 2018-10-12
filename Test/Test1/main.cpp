#include<stdio.h>



void main()
{
	int datas[] = { 0,1,2,3,4,5,6 };
	int MaxSubsequenceSum(int* resDatas, const unsigned int resLen);
	int sum = MaxSubsequenceSum(datas, (sizeof(datas)/sizeof(int)));
	void MaxSubsequence(const int* resDatas, const unsigned int resLen, int* startIndex, int* endIndex);
	int startIndex = 0;
	int endIndex = 0;
	MaxSubsequence(datas, (sizeof(datas)/sizeof(int)), &startIndex, &endIndex);

	printf("sum == %d", sum);


	getchar();
	getchar();
	getchar();
}


/*
	求最大子序列
*/


//时间复杂度O(N)
//求最大子序列的和
int MaxSubsequenceSum(int* resDatas, const unsigned int resLen)
{
	int sum = 0;
	int tempSum = 0;
	for (int i = 0; i < resLen; i++)
	{
		tempSum += resDatas[i];
		if (tempSum < 0)
		{
			tempSum = 0;
		}
		else
		{
			if (tempSum > sum)
			{
				sum = tempSum;
			}
		}
	}
	return sum;
}
//求最大子序列
void MaxSubsequence(const int* resDatas, const unsigned int resLen, int* startIndex, int* endIndex)
{
	int sum = 0;
	int tempSum = 0;
	*startIndex = 0;
	int tempStartIndex = 0;
	*endIndex = -1;
	int tempEndIndex = -1;
	for (int i = 0; i < resLen; i++)
	{
		tempEndIndex = i;
		tempSum += resDatas[i];
		if (tempSum < 0)
		{
			tempSum = 0;
			tempStartIndex = i + 1;
		}
		else if(tempSum > sum)
		{
			sum = tempSum;
			*startIndex = tempStartIndex;
			*endIndex = tempEndIndex;
		}
	}

	if (*startIndex > *endIndex)
	{
		printf("没有最大子序列");
	}

}
