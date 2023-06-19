#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define I 0x40000000
#define IN 0x20000000

void sort(int A[], unsigned n) {
	unsigned l = 0, r = n - 1;
	int x;
	if (n < 2)
		return;
	x = A[n/2];
	//divide on 2 parts: less and greater x
	while (l < r) {
		//pass elements
		while (A[l] > x)
			l++;
		while (A[r] < x)
			r--;
		//swap
		if (l <= r) {
			int tmp = A[l];
			A[l] = A[r];
			A[r] = tmp;
			l++; r--;
		}
	}
	sort(A, r + 1); //recursively sort left array
	sort(A + l, n - l); //recursively sort right array
}


int main()
{
	int *p, n, i;
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	p = (int*) malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		p[i] = rand() % I - IN;
		printf("%d ", p[i]);
	}
	printf("\n");
	sort(p, n);
	for (i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
	free(p);
	return 0;
}
