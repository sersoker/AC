#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
 #include <omp.h>
#else
 #define omp_get_thread_num() 0
#endif
#include <time.h> // biblioteca donde se encuentra la función clock_gettime()

int v1[5000], v2[5000],M[5000][5000];

main(int argc, char **argv){
struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

int i,j,k,n;
n=5000;
int sumalocal=0;

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
		if(i>=j)
		M[i][j]=i+j;
		else
		M[i][j]=0;
	
clock_gettime(CLOCK_REALTIME,&cgt1);
#pragma omp parallel for default(none) private(i,k) shared(M,v1,v2,n)schedule(guided)
	for (i=0; i<n; i++)
	{
		for(k=0;k<n;k++)
			if(i>=k)
			v2[i] += M[i][k]*v1[k];
	}

clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
	
printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%d\n",ncgt,n);
printf("Valor v2[0]= %d v2[n-1]=%d\n",v2[0],v2[n-1]);

	/*printf("Vector resultante tras calculo:");
	for (i=0; i<n; i++)
	printf(" %f ", v2[i]);
		printf("\n")*/;
	// 2= 1 2 
	// 3= 5 - 11
	// 4= 14 - - 32

}
