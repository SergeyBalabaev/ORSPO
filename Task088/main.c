#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int x[10];   //4 * N
	for (int i = 0; i < N; ++i) {
		x[i] = i;
	}
	for (int i = 0; i < N; ++i) {
		printf("%d ", x[i]);
	}
	return 0;
}
