

#include<iostream>
#include<vector>
#include<iomanip>
#include<time.h>
#include<omp.h>

using namespace std;

int main()

{
	srand(time(NULL));

	int n, m, q, i, j;
	cout << "Enter size of vector A: ";
	cin >> n;
	cout << "Enter size of vector B: ";
	cin >> m;
	
	vector <int> vector_a;
	for (i = 0; i < n; i++) {
		vector_a.push_back (rand() % 20 + 1);
	}
/*	cout << "Vector A: " << endl;

	for (auto& v : vector_a)
	{
	    cout << setw(5) << v;
	}
	*/
	vector <int> vector_b;
	for (i = 0; i < m; i++) {
		vector_b.push_back(rand() % 20 + 1);
	}
/*	cout << endl << "Vector B: " << endl;

	for (auto& v : vector_b)
	{
		cout << setw(5) << v;
	}
	*/
	int result1 = 0;
	double time_of_openmp1 = omp_get_wtime();

#pragma omp paralel for 
	for (auto a : vector_a)
		for (auto b : vector_b)
			result1+=a*b;
	double time_of_openmp2 = omp_get_wtime();

	cout << "Time of compiling with OpenMP = " << time_of_openmp2 - time_of_openmp1;

	int result2 = 0;
	double time_of_function1 = omp_get_wtime();
	for (auto a : vector_a)
		for (auto b : vector_b)
			result2 += a * b;
	double time_of_function2 = omp_get_wtime();

	cout << endl << "Time of compiling without OpenMP = " << time_of_function2 - time_of_function1;

	if (result1 == result2)
	cout << endl << "Multiplication of Vector A & B = " << result1;
		
	return 0;
}
