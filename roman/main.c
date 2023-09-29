#include <stdio.h>
#include <math.h>

int f(int x);

int main(void) {
	int x;
	int y;
	printf("Insert x: ");
	scanf("%i", &x);
	y = f(x);
	printf("y = %d\n", y);
	return 0;
}

int f(int x) {
	int y = pow(x, 2)-2*x-4;
	return y;
}
