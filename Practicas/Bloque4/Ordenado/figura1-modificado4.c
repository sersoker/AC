#include <stdlib.h> // biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h> // biblioteca donde se encuentra la función printf()
#include <time.h> // biblioteca donde se encuentra la función clock_gettime()

struct {
	int a;
	int b;
} s[5000];

main(){
int X1,X2,X3,X4;
int ii,i;
int R[400000];

struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecución
clock_gettime(CLOCK_REALTIME,&cgt1);
for (ii=1; ii<=40000;ii=ii+2) {
	X1=ii; 
	X2=0;
	X3=ii;
	X4=0;

	for(i=0; i<5000;i++){
		X1+=s[i].a;
		X2+=s[i].b;
		X3+=s[i].a;
		X4+=s[i].b;
	}
	if (X1<X2) 
		R[ii]=2*X1+5000*ii;
	else 
		R[ii]=3*X2-5000*ii;
	
	if(X3<X4)
		R[ii+1]=2*X3+5000*(ii+1);
	else 
		R[ii+1]=3*X4-5000*(ii+1);
	
}
clock_gettime(CLOCK_REALTIME,&cgt2);
ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

printf("Tiempo(seg.):%11.9f\t",ncgt);
printf("Resultado:%d \n",R[0]);
}
