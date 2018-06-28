#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
 #include <omp.h>
#else
 #define omp_get_thread_num() 0
#endif

main(int argc, char **argv){
int i, n=20, a[n],suma=0;

if(argc < 2) {
	fprintf(stderr,"Falta iteraciones\n");
	exit(-1);
}

n = atoi(argv[1]); if (n>20) {n=20; printf("n=%d",n);}
for (i=0; i<n; i++) a[i] = i;

#pragma omp parallel private(i) shared(n) shared(a) reduction(+:suma) default(none)
{
	#pragma omp sections 
	{
		#pragma omp section
		for (i=0; i<n/2; i++) suma += a[i];
		#pragma omp section
		for(i=n/2; i<n; i++) suma += a[i];
	}
}
printf("Tras 'parallel' suma=%d\n",suma);

}
