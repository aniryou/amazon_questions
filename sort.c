#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000	/* Number of elements to sort */
#define UPPER_LIM 3		/* Upper limit for integer elements, for given problem UPPER_LIM=3 */

void sort1(int A[], int n);		/* sorting similar to quicksort partitioning step */
void sort2(int A[], int n);		/* counting based sort */
void sort3(int A[], int n);		/* one pass sort, works only for 0's and 1's (i.e. UPPER_LIM=2) */

void print_arr(int A[], int n);
void copy_arr(int To[], int From[], int n);
void swap(int A[], int i, int j);

/* sort an array of {0,1,2}s in O(n) time */
int main() {
	int A[SIZE];
	int B[SIZE];
	time_t start, end;

	srand(time(NULL));

	for(int i=0; i<SIZE; i++)
		A[i] = rand() % UPPER_LIM;

	//print_arr(A, SIZE);

	copy_arr(B, A, SIZE);
	start = clock();
	sort1(B, SIZE);
	end = clock();
	printf("Sort 1 Time Taken: %ld\n", end-start);
	//print_arr(B, SIZE);

	copy_arr(B, A, SIZE);
	start = clock();
	sort2(B, SIZE);
	end = clock();
	printf("Sort 2 Time Taken: %ld\n", end-start);
	//print_arr(B, SIZE);

	copy_arr(B, A, SIZE);
	start = clock();
	sort3(B, SIZE);
	end = clock();
	printf("Sort 3 Time Taken: %ld\n", end-start);
	//print_arr(B, SIZE);

}

/* Iterate through elements of A
   c = {0,1,2,..}
   pivot = position where elements change e.g. 0->1, 1->2
*/
void sort1(int A[], int n) {
	int pivot = -1;
	for(int c=0; c<UPPER_LIM; c++) {
		for(int i=pivot+1; i<n; i++) {
			if(A[i]<c) {
				pivot++;
				swap(A, i, pivot);
			}
		}
	}
}

/* counting sort */
void sort2(int A[], int n) {
	int C[UPPER_LIM];
	for(int i=0; i<UPPER_LIM; i++) {
		C[i] = 0;
	}
	for(int i=0; i<n; i++) {
		C[A[i]]++;
	}
	for(int i=0, j=0; i<n; i++) {
		if(C[j]>0) {
			A[i] = j;
			C[j]--;
		} else {
			j++;
		}
	}
}

/* one-pass sort */
void sort3(int A[], int n) {
	int i,j;
	j = n-1;
	while(i<j) {
		while(A[i]==0)
			i++;
		while(A[j]==1)
			j--;
		swap(A, i, j);
	}
}

void swap(int A[], int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void copy_arr(int To[], int From[], int n) {
	for(int i=0; i<n; i++)
		To[i] = From[i];
}

void print_arr(int A[], int n) {
	for(int i=0; i<n; i++) {
		printf("%d", A[i]);
		printf("%s", i==(n-1) ? "\n" : ", ");
	}
}