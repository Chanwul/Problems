#include<iostream>
using namespace std;

int c, p;
int arr[101];

int main()
{
	int result = 0;
	cin >> c >> p;
	for (int i = 0; i < c; i++)
		cin >> arr[i];
	if (p == 1)
	{
		for(int i=0;i<c;i++)
			result++;
		for (int i = 0; i + 3 < c; i++)
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2] && arr[i] == arr[i + 3])
				result++;
	}
	else if (p == 2)
	{
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1])
				result++;
	}
	else if (p == 3)
	{
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] && arr[i + 2] == arr[i] + 1)
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1] + 1)
				result++;
	}
	else if (p == 4)
	{
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] + 1 && arr[i + 1] == arr[i + 2])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1] - 1)
				result++;
	}
	else if (p == 5)
	{
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1] - 1)
				result++;
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] + 1 && arr[i] == arr[i + 2])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1] + 1)
				result++;
	}
	else if (p == 6)
	{
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1])
				result++;
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] - 1 && arr[i + 1] == arr[i + 2])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1] + 2)
				result++;
	}
	else if (p == 7)
	{
		for (int i = 0; i + 2 < c; i++)
			if (arr[i] == arr[i + 1] && arr[i] == arr[i + 2])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1])
				result++;
		for (int i = 0; i + 2 < c; i++)
			if (arr[i]==arr[i+2]+1 && arr[i] == arr[i+1])
				result++;
		for (int i = 0; i + 1 < c; i++)
			if (arr[i] == arr[i + 1] - 2)
				result++;
	}
	cout << result;
	return 0;
}