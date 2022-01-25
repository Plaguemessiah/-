#include <iostream>
#include <omp.h>
#include <string>
using namespace std;

int main(const int argc, char* argv[])
{
	int number = 0;

#pragma omp parallel shared(number) num_threads(12)
	{
#pragma omp for ordered	
		for (int i = 1; i <= omp_get_num_threads(); i++)
		{
#pragma omp ordered
			cout << "Thread " << omp_get_thread_num() << " finished, number = " << number++ <<" \n";
		}
	}
	
	return 0;
}
