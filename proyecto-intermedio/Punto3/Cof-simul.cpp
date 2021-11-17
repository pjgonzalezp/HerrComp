#include "Cof-simul.h"
#include <random>
#include <stdio.h>
#include <cmath>

//Definicion de funciones

//Funcion que posiciona a las particulas en su posicion inicial
void Initial (std::vector<Molecule> & pars,std::vector<std::vector<int>> & ests, int Lini, double dx, int Lcon)
{

    double Sum = 0.0;
    
	for(int ii = 0; ii < pars.size(); ii++)
	{

        //Ubicacion de moleculas en su posicion inicial y conteo en cuadricula 
      	pars[ii].Rx = (ii % Lini) - (Lini/2);
      	pars[ii].Ry = (Lini/2) - (ii / Lini);

        double r2 = (pars[ii].Rx)*(pars[ii].Rx) + (pars[ii].Ry)*(pars[ii].Ry);
        Sum += r2;

    }

    //Calculo tamaño inicial

    double Size = sqrt(Sum/pars.size());
    std::cout << 0 << "\t" << Size << std::endl;

}


//Funcion que realiza la difusion de las moleculas
void Step (std::vector<Molecule> & pars,std::vector<std::vector<int>> & ests, int seed, int Nsteps,double dx, int Lcon)
{
    //Se calcula el valor inicial de la sumatoria

    double Sum = 0.0;

    for(int l = 0; l < pars.size(); l++){

        double r2 = (pars[l].Rx)*(pars[l].Rx) + (pars[l].Ry)*(pars[l].Ry);
        Sum += r2;
    }

    
    //se declara el generador de numeros aleatorios
    std::mt19937 gen(seed);
    //disPar=>distribucion para escoger la particula
    std::uniform_int_distribution<int> disPar(0,pars.size() - 1);
    //disDir=>distribucion para escoger la dirreccion (1-der,2-abj,3-izq,4-arb)
    std::uniform_int_distribution<int> disDir(1,4);



    //Random walk 
    for (int i = 0; i < Nsteps; ++i)
    {
        int Par = disPar(gen);
        int Dir = disDir(gen);

        //Se remueve la posicion inicial de la molecula de Sum
        double r2i = (pars[Par].Rx)*(pars[Par].Rx) + (pars[Par].Ry)*(pars[Par].Ry);
        Sum -= r2i;
        
        //Se realiza un paso aleatorio
        
        if (Dir == 1)
        {
            if (pars[Par].Rx < (Lcon/2)){
                pars[Par].Rx++;
            }
        }
        else if (Dir == 2)
        {
            if (pars[Par].Ry > -(Lcon/2)){
                pars[Par].Ry--;
            }
        }
        else if (Dir == 3)
        {
            if (pars[Par].Rx > -(Lcon/2)){
                pars[Par].Rx--;
            }
        }
        else
        {
            if (pars[Par].Ry < (Lcon/2)){
                pars[Par].Ry++;
            }
        }

        //Se añade la nueva posicion de la molecula a Sum y se calcula Size
        double r2n = (pars[Par].Rx)*(pars[Par].Rx) + (pars[Par].Ry)*(pars[Par].Ry);
        Sum += r2n;

        double Size = sqrt(Sum/pars.size());
       // std::cout << i+1 << "\t" << Size << std::endl;
    }
      
}


//Imprime el numero de molecula y su posicion
void Print(std::vector<Molecule> & pars){


    for(int h = 0; h < pars.size(); h++){
    std::cout << h << "\t"
              << pars[h].Rx << "\t"
              << pars[h].Ry << "\n"; 
    }
}
