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
int i,j,k,n,x;
n = atoi(argv[1]);

int **M1,**M2,**M3,**M4;
M1 = (int **)malloc (n*sizeof(int *));
M2 = (int **)malloc (n*sizeof(int *));
M3 = (int **)malloc (n*sizeof(int *));
M4 = (int **)malloc (n*sizeof(int *));
for (i=0;i<n;i++){
	M1[i] = (int *) malloc (n*sizeof(int));
	M2[i] = (int *) malloc (n*sizeof(int));
	M3[i] = (int *) malloc (n*sizeof(int));
	M4[i] = (int *) malloc (n*sizeof(int));
}

// Inicio Matriz M1 m[i][j]=i+j
for (i=0; i<n; i++)
	for (j=0; j<n; j++)
		M1[i][j]=1;
// Inicio Matriz M2 m[i][j]=i+j
for (i=0; i<n; i++)
	for (j=0; j<n; j++)
		M2[i][j]=1;
// Inicio Matriz M3 m[i][j]=i+j
for (i=0; i<n; i++)
	for (j=0; j<n; j++)
		M3[i][j]=0;
		
clock_gettime(CLOCK_REALTIME,&cgt1);

// Traspuesta de la matriz M2 a M4
for (i=0; i<n; i++)
	for (j=0; j<n; j++)
		M4[j][i]=M2[i][j];

for (i=0; i<n-1; i=i+2){
	for(j=0;j<n;j++){
		for(x=0;x<n;x++){
		M3[i][j]=M3[i][j]+(M1[i][x]*M4[j][x]);
		M3[i+1][j]=M3[i+1][j]+(M1[i+1][x]*M4[j][x]);
		}

	}
}
clock_gettime(CLOCK_REALTIME,&cgt2);
	ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\n",ncgt,n);
printf("Valor M[0][0]= %d M[n-1][n-1]=%d\n",M3[0][0],M3[n-1][n-1]);

}
