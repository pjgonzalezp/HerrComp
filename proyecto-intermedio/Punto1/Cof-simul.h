#ifndef _COF_SIMUL_H_
#define _COF_SIMUL_H_

#include "Molecule.h"
#include <iostream>
#include <vector>

//Parametros de la simulacion
const int N = 400;//numero de moleculas 
const int LL = 20;//lado lattice (cuadrado del centro)
const int IT = 1000000; //10^6(iteraciones del tiempo)
const int SEED = 0;//semilla para números aleatorios
const int LC = 100;//lado del contenedor
const int LG = 8;//lado de la cuadricula para calcular las probabilidades 
const double DXG = double(LC)/LG; //Lado de cada cuadricula

//Declaracion de funciones
void Initial (std::vector<Molecule> & pars, std::vector<std::vector<int>> & ests, int Lini, double dx, int Lcon);
void Step (std::vector<Molecule> & pars, std::vector<std::vector<int>> & ests, int seed, int Nsteps, double dx,  int Lcon);
void Print(std::vector<Molecule> & pars);


#endif // _COF_SIMUL_H_
