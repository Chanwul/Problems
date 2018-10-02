#include<iostream>
using namespace std;

int arr[15][15];

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= 14; i++)
		arr[0][i] = i;

	for(int i=1;i<=14;i++)
		for (int j = 1; j <= 14; j++)
		{
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	for (int t = 0; t < T; t++)
	{
		int n, k;
		cin >> n;
		cin >> k;
		cout << arr[n][k]<<endl;
	}
	return 0;
}