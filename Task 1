#include <iostream>
#include <omp.h>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	#pragma omp parallel num_threads(4)
	{
	cout << "The node " << omp_get_thread_num() << " said: \" Hello world! \" \n";
	}
	
	return 0;
}
