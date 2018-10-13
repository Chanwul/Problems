#include<iostream>
using namespace std;

int n;
int arr[1000000];
int b;
int c;
int main()
{
	long long result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++)
	{
		result++;
		arr[i] -= b;
		if (arr[i] <= 0)
		{
			arr[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			result += arr[i] / c;
			arr[i] %= c;
			if (arr[i] > 0)
				result++;
		}
	}
	cout << result;
	return 0;
}