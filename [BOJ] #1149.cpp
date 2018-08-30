#include<iostream>
using namespace std;
int n;
int arr[3][1001];
int d[3][1001];

int min(int a, int b)
{
	if (a > b)
		return b;
	else return a;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	for (int i = 1; i <= t; i++)
	{
		d[0][i]= min(d[2][i - 1], d[1][i - 1]) + arr[0][i];
		d[1][i] = min(d[2][i - 1], d[0][i - 1]) + arr[1][i];
		d[2][i] = min(d[1][i - 1], d[0][i - 1]) + arr[2][i];
	}
	cout << min(d[0][t], min(d[1][t], d[2][t]));
	return 0;
}