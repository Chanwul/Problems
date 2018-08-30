#include<iostream>
using namespace std;
int n;
int arr[41];
int d[2][41];

int fibo0(int i)
{
	if (i == 0)
		return 1;
	if (i == 1)
		return 0;
	if (d[0][i] > 0)
		return d[0][i];
	d[0][i] = fibo0(i - 1) + fibo0(i-2);

	return d[0][i];
}
int fibo1(int i)
{
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	if (d[1][i] > 0)
		return d[1][i];

	d[1][i] = fibo1(i - 1) + fibo1(i - 2);
	return d[1][i];
}

int main()
{
	int t;
	cin >> t;
	d[0][0] = 1;
	d[1][1] = 1;
	for (int i = 0; i < t; i++)
	{
		int x;
		cin >> x;
		cout << fibo0(x) << " " << fibo1(x) << endl;
	}
	
	
	return 0;
}