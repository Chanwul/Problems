#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n, k;
bool check[26];
int MAX = INT32_MIN;
string str[50];

void set()
{
	memset(check, false, sizeof(check));
	check[(int)'a' - 97] = true;
	check[(int)'c' - 97] = true;
	check[(int)'t' - 97] = true;
	check[(int)'i' - 97] = true;
	check[(int)'n' - 97] = true;
	return;
}

bool work(string str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (check[str[i] - 97] == false)
		{
			return false;
		}
		i++;
	}
	return true;
}

void go(int len, int cnt)
{
	if (len >= 26 || cnt == k)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
			if (work(str[i]))
			{
				count++;
			}
		if (MAX < count)
			MAX = count;
		return;
	}

	if (check[len] == false)
	{
		check[len] = false;
		go(len + 1, cnt);
		check[len] = true;
		go(len + 1, cnt + 1);
		check[len] = false;
	}
	else
		go(len + 1, cnt);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	if (k < 5)
	{
		cout << 0;
		return 0;
	}
	set();
	go(0, 5);
	cout << MAX;
	return 0;
}