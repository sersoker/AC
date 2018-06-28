#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

main(int argc, char **argv) {
	int i, n=200,chunk,a[n],suma=0;
	int modifier=0,modifier2=0;
	omp_sched_t kind,kind2;

	if(argc < 3) {
	fprintf(stderr,"\nFalta iteraciones o chunk \n");
	exit(-1);
	}
	n = atoi(argv[1]); if (n>200) n=200; chunk = atoi(argv[2]);
	for (i=0; i<n; i++) a[i] = i;
	
	#pragma omp parallel
	{
	#pragma omp for schedule(dynamic,chunk) lastprivate(suma) firstprivate(suma)
		for (i=0; i<n; i++)
		{ suma = suma + a[i];
		printf(" thread %d suma a[%d]=%d suma=%d \n",
		omp_get_thread_num(),i,a[i],suma);
		}

	#pragma omp single	
	{
	omp_get_schedule(&kind, &modifier);
	printf("Antes: dyn-var: %d  nthreads-var:%d run-sched-var: Modifier:%d Kind:%d\n",
	omp_get_dynamic(),omp_get_max_threads(),modifier,kind);

	omp_set_dynamic(1);
	omp_set_num_threads(15);
	omp_set_schedule(omp_sched_auto,0);

	omp_get_schedule(&kind2, &modifier2);
	printf("Despues: dyn-var: %d  nthreads-var:%d run-sched-var: Modifier:%d Kind:%d\n",
	omp_get_dynamic(),omp_get_max_threads(),modifier2,kind2);
	}
	}
	printf("Fuera de 'parallel for' suma=%d\n",suma);
}
