#include <cstdio>
#include <vector>
#include <iostream>
using namespace std; 

typedef struct robot
{
	pair<int, int> pos;
	char dir;
};

int A, B, n, m;
vector<robot> vec;
int arr[101][101] = { 0 };

int main()
{
	cin >> A >> B >> n >> m;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> cur;
		char D;
		cin >> cur.first >> cur.second >> D;
		vec.push_back({ cur, D });
		arr[cur.first][cur.second] = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int number, iter;
		char command;
		cin >> number >> command >> iter;
		for (int x = 0; x < iter; x++)
		{
			int tempi = vec[number - 1].pos.first;
			int tempj = vec[number - 1].pos.second;
			if (command == 'L')
			{
				if (vec[number - 1].dir == 'W')
					vec[number - 1].dir = 'S';
				else if (vec[number - 1].dir == 'S')
					vec[number - 1].dir = 'E';
				else if (vec[number - 1].dir == 'E')
					vec[number - 1].dir = 'N';
				else if (vec[number - 1].dir == 'N')
					vec[number - 1].dir = 'W';
			}
			else if (command == 'R')
			{
				if (vec[number - 1].dir == 'W')
					vec[number - 1].dir = 'N';
				else if (vec[number - 1].dir == 'N')
					vec[number - 1].dir = 'E';
				else if (vec[number - 1].dir == 'E')
					vec[number - 1].dir = 'S';
				else if (vec[number - 1].dir == 'S')
					vec[number - 1].dir = 'W';
			}
			else if (command == 'F')
			{
				if (vec[number - 1].dir == 'W')
					vec[number - 1].pos.first--;
				else if (vec[number - 1].dir == 'N')
					vec[number - 1].pos.second++; 
				else if (vec[number - 1].dir == 'E')
					vec[number - 1].pos.first++;
				else if (vec[number - 1].dir == 'S')
					vec[number - 1].pos.second--;
			}
			if (vec[number - 1].pos.first<1 || vec[number - 1].pos.first>A || vec[number - 1].pos.second<1 || vec[number - 1].pos.second>B)
			{
				cout << "Robot " << number << " crashes into the wall";
				return 0;
			}
			else if (arr[vec[number - 1].pos.first][vec[number - 1].pos.second] != 0 &&
				arr[vec[number - 1].pos.first][vec[number - 1].pos.second] !=arr[tempi][tempj])
			{
				cout << "Robot " << number << " crashes into robot " << arr[vec[number - 1].pos.first][vec[number - 1].pos.second];
				return 0;
			}
			else
			{
				arr[tempi][tempj] = 0;
				arr[vec[number - 1].pos.first][vec[number - 1].pos.second] = number;
			}
		}
	}
	cout << "OK";
	return 0;
}