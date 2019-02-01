#include <cstdio>
using namespace std;
int arr[4];

void swap(int a, int b)
{
	if (a == b)
		return;
	else
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
		return;
	}
}

int main()
{
	for (int i = 1; i < 4; i++)
		arr[i] = i;
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		swap(a, b);
	}
	for (int i = 1; i <= 3; i++)
		if(arr[i]==1)
			printf("%d", i);
	return 0;
}