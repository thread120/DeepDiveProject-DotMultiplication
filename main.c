// CRUZ, Airon John R.
// CEPARCO - S11
// C-main Program (Caller)

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


extern long long dotproduct_simd(long long n, long long* A, long long* B, long long* sdot); //simd-implemented kernel
extern long long dotproduct_x8664(long long n, long long* A, long long* B, long long* sdot); //x86-64-implemented kernel

//C-implemented kernel
void  dotproduct_C(long long n, long long* A, long long* B, long long* sdot) {
	for (int i = 0; i < n; i++)
		*sdot += (A[i] * B[i]);

}


// Function to check errors within the returned 'sdot' of the implemented kernels
void checkErrors(long long* A, long long* B, long long n, long long sdot) {

	long long sanityChecker = 0;
	dotproduct_C(n, A, B, &sanityChecker);
	if (sanityChecker != sdot) {
		printf("\n PROGRAM ERROR: Your kernel's output is incorrect");
	}
	else printf("\n CORRECT PROGRAM");

	printf("\nExpected Result = %lld", sanityChecker);
	printf("\nActual Result = %lld\n", sdot);

}


// This calls all the implemented kernels, and displays the performance (time and results) of the implemented kernels
int main() {
	//number of runs
	int runs = 30;
	//initialize 'n' or the vectors' length
	int n_count = 0;

	// prompt1: Ask user for the number of vector sizes to test (Limited to power of 2 inputs as prescribed in the specification)
	printf("How many vector sizes do you want to test? ");
	scanf_s("%d", &n_count);

	// Allocate memory for the vector sizes and copy_sdot arrays
	int* n_initial = (int*)malloc(n_count * sizeof(int));
	long long* n = malloc(n_count * sizeof(long long));
	
	for (int i = 0; i < n_count; i++)
	{
		printf("Enter the exponent #%d (for the base-2 vector sizes): ", i+1);
		scanf_s("%d", &n_initial[i]);
		n[i] = (long long)1 << n_initial[i];
	}

	//must convert the input to 1 << n[i]

	for (int count = 0; count < n_count; count++) {
		//initialize input vectors' and their respective data
		long long* A = malloc(n[count] * sizeof(long long));
		long long* B = malloc(n[count] * sizeof(long long));
		long long* copy_sdot = malloc(n_count * sizeof(long long));
		long long* sdot = malloc(sizeof(long long)); //allocate memory for the output

		for (int i = 0; i < n[count]; i++) {
			A[i] = (long long)i;
			B[i] = (long long)i % (1 << 7);
		}

		//declare time variables
		clock_t start, end;
		//flush out cache 
		dotproduct_C(n[count], A, B, sdot);
		//time here
		double sum[3] = { 0, 0, 0 };
		double* time_taken1; //for C-program
		double* time_taken2;  //for x86-64
		double* time_taken3; //for simd
		time_taken1 = (double*)malloc(runs * sizeof(double));
		time_taken2 = (double*)malloc(runs * sizeof(double));
		time_taken3 = (double*)malloc(runs * sizeof(double));

		
		for (int i = 0; i < runs; i++) {
			//for C-program
			*sdot = 0;
			start = clock();
			dotproduct_C(n[count], A, B, sdot);
			end = clock();
			time_taken1[i] = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;
			copy_sdot[0] = *sdot;
			sum[0] += time_taken1[i];

		}

		for (int i = 0; i < runs; i++) {
			//for x86-64 program
			*sdot = 0;
			start = clock();
			dotproduct_x8664(n[count], A, B, sdot);
			end = clock();
			time_taken2[i] = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;
			copy_sdot[1] = *sdot;
			sum[1] += time_taken2[i];
		}

		for (int i = 0; i < runs; i++) {
			//for x86-64 SIMD program
			*sdot = 0;
			start = clock();
			dotproduct_simd(n[count], A, B, sdot);
			end = clock();
			time_taken3[i] = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;
			copy_sdot[2] = *sdot;
			sum[2] += time_taken3[i];
		}
		printf("\n---------------- For ARRAY-SIZE: %lld-----------------", n[count]);



		//for C-program
		double average_time[3] = { 0, 0, 0 };
		average_time[0] = sum[0] / runs;
		printf("\nC function took %.2f microseconds ave. time for array size of %lld throughout %d runs", average_time[0], n[count], runs);
		//Checking for errors
		checkErrors(A, B, n[count], copy_sdot[0]);

		//for x86-64 program
		average_time[1] = sum[1] / runs;
		printf("\nx86-64 kernel took %.2f microseconds ave. time for array size of %lld throughout %d runs", average_time[1], n[count], runs);
		//Checking for errors
		checkErrors(A, B, n[count], copy_sdot[1]);

		//for SIMD program
		average_time[2] = sum[2] / runs;
		printf("\nx86-64 SIMD kernel took %.2f microseconds ave. time for array size of %lld throughout %d runs", average_time[2], n[count], runs);
		//Checking for errors
		checkErrors(A, B, n[count], copy_sdot[2]);
		
		free(A);
		free(B);
		free(copy_sdot);

	}
	free(n_initial);


	return 0;
}