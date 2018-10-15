#include<stdio.h>

void main()
{
	char a = getchar();
	switch (a)
	{
	case 'w':
		printf("w");
		break;
	case 'e':
		printf("e");
	case 'f':
		printf("f");
		break;
	case 'p':
		printf("p");
	default:
		break;
	}
	getchar();
	getchar();
}