#include <stdlib.h> // biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h> // biblioteca donde se encuentra la función printf()
#include <omp.h>
#include <iostream>


/* SumaVectoresC.c
Suma de dos vectores: v3 = v1 + v2
Para compilar usar (-lrt: real time library):
gcc -O2 SumaVectores.c -o SumaVectores -lrt
Para ejecutar use: SumaVectoresC longitud */

#define VECTOR_GLOBAL// descomentar para que los vectores sean variables ...
#ifdef VECTOR_GLOBAL
#define MAX 33554432 //=2^25
double v1[MAX], v2[MAX], v3[MAX];
#endif

int main(int argc, char** argv){
	int i;
	double cgt1,cgt2; double ncgt; //para tiempo de ejecución
	//Leer argumento de entrada (nº de componentes del vector)


	if (argc<2){
		printf("Faltan nº componentes del vector\n");
		exit(-1);
	}

	unsigned int N = atoi(argv[1]); // Máximo N =2^32-1=4294967295 (sizeof(unsigned int) = 4 B)

	#ifdef VECTOR_GLOBAL
		if (N>MAX) N=MAX;
	#endif


    int nProcessors=omp_get_max_threads();

    std::cout<<"Max Threads:"<<nProcessors<<std::endl;


    //omp_set_num_threads(nProcessors);
    //std::cout<<omp_get_num_threads()<<std::endl;



#pragma omp parallel
{

	//Inicializar vectores
	#pragma omp for
		for(i=0; i<N; i++){
			v1[i] = N*0.1+i*0.1; 
			v2[i] = N*0.1-i*0.1; //los valores dependen de N
		}
	cgt1=omp_get_wtime();
	
	//Calcular suma de vectores
	#pragma omp for
		for(i=0; i<N; i++)
			v3[i] = v1[i] + v2[i];
}
	cgt2=omp_get_wtime();
	ncgt=cgt2-cgt1;
		printf("Tiempo(seg.):%11.9f\t / Tamaño Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / / V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n",
		ncgt,N,v1[0],v2[0],v3[0],N-1,N-1,N-1,v1[N-1],v2[N-1],v3[N-1]);

		//printf("Valor V1[0]:%d.Valor V2[0]:%d.Valor V3[0]:%d. Valor V1[u]:%d.Valor V2[u]:%d.Valor V3[u]:%d.",	v1[0],v2[0],v3[0],v1[N-1],v2[N-1],v3[N-1])
return 0;
}
