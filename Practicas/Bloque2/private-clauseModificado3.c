#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#else
 #define
#endif

main(){
int i, n = 7;
int a[n];
int suma=18;

	for (i=0; i<n; i++)
	 a[i] = i;
printf(	"valor suma antes del for[%d] \n",suma);
#pragma omp parallel
{
	suma=0;
	#pragma omp for
	for (i=0; i<n; i++)
	{
		suma = suma + a[i];
		printf(	"thread %d suma a[%d] / ", omp_get_thread_num(), i);
	}
	printf(
	"\n* thread %d suma= %d", omp_get_thread_num(), suma);
}

printf(	"\nvalor suma despues del for[%d] ",suma);
printf("\n");
}
