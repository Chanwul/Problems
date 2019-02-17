#include <iostream>
#include <cstdio>
using namespace std;
int n;
int max = 4;

void go(int val)
{
	if (val <= n)
	{
		if (max < val)
			max = val;
	}
	if (10 * val + 4 > n)
		return;
	if (10 * val + 4 <= n)
		go(10 * val + 4);
	if (10 * val + 7 <= n)
		go(10 * val + 7);
	return;
}

int main()
{
	scanf("%d", &n);
	go(0);
	printf("%d", max);
	return 0;
}