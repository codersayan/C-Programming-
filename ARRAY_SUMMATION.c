#include <stdio.h>
int main()
{
	int a[100];
	int n, i;

	printf("How many items do you want to enter: ");
	scanf("%d", &n);

	printf("Enter the items:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int sum = 0;
	for (i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	printf("After summation, result = %d", sum);
}
