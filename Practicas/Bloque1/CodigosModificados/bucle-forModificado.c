#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

main() {
#pragma omp parallel
{
	#pragma omp sections
	{
		#pragma omp section
			#pragma omp for
			for (i=0; i<n; i++)
				printf("thread %d ejecuta la iteración %d del bucle\n",
			omp_get_thread_num(),i);		
		#pragma omp section
			#pragma omp for
			for (i=0; i<n; i++)
				printf("thread %d ejecuta la iteración %d del bucle\n",
			omp_get_thread_num(),i);
		
	}
}
