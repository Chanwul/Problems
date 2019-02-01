#include <cstdio>
using namespace std;

int main()
{
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	int max = 0;
	int x = a / c;
	if (a%c != 0)
		x++;
	int y = b / d;
	if (b%d != 0)
		y++;
	if (x > y)
		printf("%d", l - x);
	else
		printf("%d", l - y);


	return 0;
}