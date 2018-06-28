#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
 #include <omp.h>
#else
 #define omp_get_thread_num() 0
#endif
#include <time.h> // biblioteca donde se encuentra la función clock_gettime()
unsigned int y[114748364];
unsigned int x[114748364];

main(int argc, char **argv){
struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución

if(argc < 2) {
	fprintf(stderr,"Falta constante N.\n");
	exit(-1);
}
int i,n,a
a= atoi(argv[1]);
n=114748364;

// Inicio vector x e y
for (i=0; i<n; i++){
		x[i]=1;
		y[i]=1;
	}

clock_gettime(CLOCK_REALTIME,&cgt1);

for (i=1;i<=n;i++) 
	y[i]= a*x[i] + y[i];

clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,n);
printf("Valor M[0][0]= %d M[n-1][n-1]=%d\n",y[0],y[n-1]);
}
