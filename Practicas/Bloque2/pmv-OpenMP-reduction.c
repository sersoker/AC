#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
 #include <omp.h>
#else
 #define omp_get_thread_num() 0
#endif
#include <time.h> // biblioteca donde se encuentra la función clock_gettime()


main(int argc, char **argv){
struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

if(argc < 2) {
	fprintf(stderr,"Falta numero de filas/columnas N de la matriz.\n");
	exit(-1);
}
int i,j,k,n;
n = atoi(argv[1]);
double v1[n], v2[n],M[n][n];
double sumalocal=0;

// Inicio vector 1 v1[i]=i
#pragma omp parallel for default(none) private(i) shared(v1,n)
for (i=0; i<n; i++) v1[i] = i;
// Inicio vector 2 a 0
#pragma omp parallel for default(none) private(i) shared(v2,n)
for (i=0; i<n; i++) v2[i] = 0;
// Inicio Matriz M m[i][j]=i+j
#pragma omp parallel for default(none) private(i,j) shared(M,n)
for (i=0; i<n; i++)
	for (j=0; j<n; j++)
		M[i][j]=i+j;

clock_gettime(CLOCK_REALTIME,&cgt1);
#pragma omp parallel default(none) private(i,k) shared(M,v1,v2,n) reduction(+:sumalocal)
	for (i=0; i<n; i++){
	sumalocal=0;
		#pragma omp for
		for(k=0;k<n;k++)
			sumalocal += M[i][k]*v1[k];
		#pragma omp critical
		v2[i]+=sumalocal;

	}

clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	
printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,n);
printf("Valor v2[0]= %f v2[n-1]=%f\n",v2[0],v2[n-1]);

	/*printf("Vector resultante tras calculo:");
	for (i=0; i<n; i++)
	printf(" %d ", v2[i]);
		printf("\n");*/
	// 2= 1 2 
	// 3= 5 - 11
	// 4= 14 - - 32

}
