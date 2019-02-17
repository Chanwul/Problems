#include <iostream>
#include <string>
using namespace std;

string move[50];
pair<int, int> k, st;
int n;

void go()
{
	for (int i = 0; i < n; i++)
	{
		pair<int, int> next = k;
		pair<int, int> nextst = st;
		if (::move[i].size() == 1)
		{
			if (::move[i][0] == 'L')
				next.second--;
			else if (::move[i][0] == 'R')
				next.second++;
			else if (::move[i][0] == 'T')
				next.first++;
			else if (::move[i][0] == 'B')
				next.first--;
		}
		else if (::move[i].size() == 2)
		{
			if (::move[i][0] == 'L')
			{
				next.second--;
				if (::move[i][1] == 'T')
					next.first++;
				else
					next.first--;
			}
			else if (::move[i][0] == 'R')
			{
				next.second++;
				if (::move[i][1] == 'T')
					next.first++;
				else
					next.first--;
			}
		}
		if (next == st)
		{
			nextst.first += next.first - k.first;
			nextst.second += next.second - k.second;
		}
		if (next.first < 1 || next.first>8 || next.second < 1 || next.second>8 ||
			nextst.first < 1 || nextst.first>8 || nextst.second < 1 || nextst.second>8)
			continue;

		k = next;
		st = nextst;
	}
	return;
}

int main()
{
	string king, stone;
	cin >> king >> stone >> n;
	k.first = (int)king[1]-48;
	k.second = (int)king[0] - 64;
	st.first = (int)stone[1]-48;
	st.second = (int)stone[0] - 64;
	for (int i = 0; i < n; i++)
		cin >> ::move[i];
	go();
	cout << (char)(k.second + 64) << k.first << endl;
	cout << (char)(st.second + 64) << st.first;
	return 0;
}