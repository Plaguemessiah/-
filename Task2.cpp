#include <iostream>
#include <omp.h>
#include <string>
using namespace std;

int main(const int argc, char* argv[])
{
	int n;
	double sum = 0.;
	if (argc > 1)
	{
		n = stoi(argv[1]);
	}
	else
	{
		throw runtime_error("No arguments passed!");
	}
	
	const int block_size = (n < 12) ? 1 : n / 12;

#pragma omp parallel num_threads(12)
	{
#pragma omp for reduction(+:sum) schedule(static, block_size)
		for (int i = 1; i <= n; i++)
		{
			sum += 1./i;
		}
		cout << "Thread " << omp_get_thread_num() << " finished!\n";
	}
	
	cout << "The result sum: " << sum << endl;
	return 0;
}
