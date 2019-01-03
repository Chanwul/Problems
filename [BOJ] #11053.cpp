#include<iostream>
using namespace std;

int n;
int arr[1001];
int d[1001];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
				if (d[j] + 1 > d[i])
					d[i] = d[j] + 1;
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
		if (max < d[i])
			max = d[i];
	cout << max;
	return 0;
}