#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vector<char> st1;
		vector<char> st2;
		for (int a = 0; a < str.length(); a++)
		{
			if (str[a] == '<')
			{
				if (!st1.empty())
				{
					char temp = st1[st1.size() - 1];
					st1.pop_back();
					st2.push_back(temp);
				}
			}
			else if (str[a] == '>')
			{
				if (!st2.empty())
				{
					char temp = st2[st2.size() - 1];
					st2.pop_back();
					st1.push_back(temp);
				}
			}
			else if (str[a] == '-')
			{
				if(!st1.empty())
					st1.pop_back();
			}
			else
				st1.push_back(str[a]);
		}
		if (!st2.empty())
		{
			for (int k = st2.size() - 1; k >= 0; k--)
				st1.push_back(st2[k]);
		}
		for (int i = 0; i < st1.size(); i++)
			printf("%c", st1[i]);
		printf("\n");
	}
	return 0;
}