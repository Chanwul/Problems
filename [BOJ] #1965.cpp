#include<iostream>
using namespace std;
int n;
int arr[1000];
int d[1000];

int go(int i)
{
	if (d[i] != 0)
		return d[i];

	d[i] = 1;
	
	for (int x = 0; x < i; x++)
	{
		if (arr[x] < arr[i])
		{
			int temp = go(x) + 1;
			if (temp > d[i])
				d[i] = temp;
		}
	}
	return d[i];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i=0;i<n;i++)
		go(i);
	int MAX = 0;
	for (int i = 0; i < n; i++)
		if (MAX < d[i])
			MAX = d[i];
	cout << MAX;
	
	return 0;
}