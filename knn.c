#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define K 10
#define UPPER_LIM 100

#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)

void kn_origin1(int A[], int n, int k);	/* heap based approach */
void kn_origin2(int A[], int n, int k);	/* k-pass based approach */

void build_max_heap(int A[], int n);
void max_heapify(int A[], int i, int n);

void swap(int A[], int i, int j);
void copy_arr(int To[], int From[], int n);
void print_arr(int A[], int n);

int main() {
	int A[SIZE];
	int B[SIZE];
	time_t start, end;

	srand(time(NULL));

	for(int i=0; i<SIZE; i++)
		A[i] = rand() % UPPER_LIM;

	copy_arr(B, A, SIZE);
	start = clock();
	kn_origin1(B, SIZE, K);
	end = clock();
	printf("Time Taken: %ld\n", end-start);
	print_arr(B, SIZE);

	copy_arr(B, A, SIZE);
	start = clock();
	kn_origin2(B, SIZE, K);
	end = clock();
	printf("Time Taken: %ld\n", end-start);
	print_arr(B, SIZE);
}

void kn_origin1(int A[], int n, int k) {
	build_max_heap(A, k);
	for(int i=k; i<n; i++) {
		if(A[i]<A[0]) {
			swap(A, i, 0);
			max_heapify(A, 0, k);
		}
	}
}

void build_max_heap(int A[], int n) {
	for(int i=n/2; i>=0; i--) {
		max_heapify(A, i, n);
	}
}

void max_heapify(int A[], int i, int n) {
	int largest = i;
	if(LEFT(i)<n && A[LEFT(i)]>A[i])
		largest = LEFT(i);
	if(RIGHT(i)<n && A[RIGHT(i)]>A[largest])
		largest = RIGHT(i);
	if(i != largest) {
		swap(A, i, largest);
		max_heapify(A, largest, n);
	}
}

void kn_origin2(int A[], int n, int k) {
	for(int i=0; i<k; i++) {
		for(int j=i+1; j<n; j++) {
			if(A[j]<A[i])
				swap(A,i,j);
		}
	}
}

void copy_arr(int To[], int From[], int n) {
	for(int i=0; i<n; i++)
		To[i] = From[i];
}

void print_array(int A[], int n) {
	for(int i=0; i<n; i++) {
	    printf("%d", A[i]);
	    printf("%s", (i<n-1) ? "," : "\n");
	}
}

void swap(int A[], int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}

void print_arr(int A[], int n) {
	for(int i=0; i<n; i++) {
		printf("%d", A[i]);
		printf("%s", i==(n-1) ? "\n" : ", ");
	}
}