#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
		arr[i] = 1000000;
	arr[n] = 0;
	for (int i = n; i >= 1; i--)
	{
		if (i % 3 == 0)
		{
			if (arr[i / 3] > arr[i] + 1)
				arr[i / 3] = arr[i] + 1;
		}
		if (i % 2 == 0)
		{
			if (arr[i / 2] > arr[i] + 1)
				arr[i / 2] = arr[i] + 1;
		}
		if (arr[i - 1] > arr[i] + 1)
			arr[i - 1] = arr[i] + 1;
	}
	cout << arr[1];
	return 0;
}