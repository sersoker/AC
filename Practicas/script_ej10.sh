#!/bin/bash
#Se asigna al trabajo el nombre
#PBS -N ej10
#Se asigna al trabajo la cola ac
#PBS -q ac
for ((P=1;P<=12;P=P+1))
do
#Se fija el nº de threads
export OMP_NUM_THREADS=$P
echo Para $P threads:
	$PBS_O_WORKDIR/pmm-OpenMP 50
	$PBS_O_WORKDIR/pmm-OpenMP 100
	$PBS_O_WORKDIR/pmm-OpenMP 500
	$PBS_O_WORKDIR/pmm-OpenMP 1000
done
