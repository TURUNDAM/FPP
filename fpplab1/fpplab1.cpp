

#include<iostream>
#include<vector>
#include<iomanip>
#include<time.h>
#include<omp.h>
#include<math.h>

using namespace std;

int main()

{
	srand(time(NULL));

	int n, m;
	cout << "Enter size of vector A: ";
	cin >> n;
	cout << "Enter size of vector B: ";
	cin >> m;
	
	vector <int> vector_a;
	for (int i = 0; i < n; i++) {
		vector_a.push_back (rand() % 20 + 1);
	}
/*	cout << "Vector A: " << endl;

	for (auto& v : vector_a)
	{
	    cout << setw(5) << v;
	}
	*/
	vector <int> vector_b;
	for (int i = 0; i < m; i++) {
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
	for (int i =0;i<vector_a.size()&&i<vector_b.size();i++) 
			result1 += abs(vector_a[i] * vector_b[i]);
	
	double time_of_openmp2 = omp_get_wtime();

	cout << "Time of compiling with OpenMP = " << time_of_openmp2 - time_of_openmp1;

	int result2 = 0;
	double time_of_function1 = omp_get_wtime();
	for (int i = 0; i < vector_a.size() && i < vector_b.size(); i++)
		result2 += abs(vector_a[i] * vector_b[i]);
	double time_of_function2 = omp_get_wtime();

	cout << endl << "Time of compiling without OpenMP = " << time_of_function2 - time_of_function1;

	if (result1 == result2)
	cout << endl << "Scallar multiplication of Vector A & B = " << result1;
		
	return 0;
}
