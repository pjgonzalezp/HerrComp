#include "Cof-simul.h"
#include <random>
#include <stdio.h>
#include <cmath>

//Definicion de funciones

//Funcion que posiciona a las particulas en su posicion inicial
void Initial (std::vector<Molecule> & pars,std::vector<std::vector<int>> & ests, int Lini, double dx, int Lcon)
{
	for(int ii = 0; ii < pars.size(); ii++)
	{

        //Ubicacion de moleculas en su posicion inicial
      	pars[ii].Rx = (ii % Lini) - (Lini/2);
      	pars[ii].Ry = (Lini/2) - (ii / Lini);
        
    }

    
}


//Funcion que realiza la difusion de las moleculas
void Step (std::vector<Molecule> & pars,std::vector<std::vector<int>> & ests, int seed, int Nsteps,double dx, int Lcon)
{
    //se declara el generador de numeros aleatorios
    std::mt19937 gen(seed);
    //disPar=>distribucion para escoger la particula
    std::uniform_int_distribution<int> disPar(0,pars.size() - 1);
    //disDir=>distribucion para escoger la dirreccion (1-der,2-abj,3-izq,4-arb)
    std::uniform_int_distribution<int> disDir(1,4);

    //Numero inicial de moleculas en el contenedor
    int Nin = pars.size();

    //Random walk 
    for (int i = 0; i < Nsteps; ++i)
    {
        int Par = disPar(gen);
        int Dir = disDir(gen);

        //Se expulsa y aleja las particulas que entren al orificio, tambien se 
        if(pars[Par].Ry <= (Lcon/10) && pars[Par].Ry >= -(Lcon/10) && pars[Par].Rx >= (Lcon/2)){
            if(pars[Par].Rx == (Lcon/2)){
                Nin--;
            }
             pars[Par].Rx++;
        } else {

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
        }

        std::cout << i << "\t" << Nin << std::endl;
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

