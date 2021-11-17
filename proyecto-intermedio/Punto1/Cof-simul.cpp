#include "Cof-simul.h"
#include <random>
#include <stdio.h>
#include <cmath>

//Definicion de funciones

//Funcion que posiciona a las particulas en su posicion inicial
void Initial (std::vector<Molecule> & pars,std::vector<std::vector<int>> & ests, int Lini, double dx, int Lcon)
{
	for(int ii=0; ii < pars.size(); ii++)
	{

        //Ubicacion de moleculas en su posicion inicial y conteo en cuadricula 
      	pars[ii].Rx = (ii % Lini) - (Lini/2);
      	pars[ii].Ry = (Lini/2) - (ii / Lini);

        int gi = int(((Lcon/2) - pars[ii].Ry)/dx);
        int gj = int(((Lcon/2) + pars[ii].Rx)/dx);

        ests[gi][gj]++;
        
    }

    //Calculo entropia inicial
    
       double S_0 = 0.0;

        for(int i = 0; i < ests.size(); i++){
            for(int j = 0; j < ests[i].size(); j++){
                
                double Pr = double(ests[i][j])/pars.size();
                
                if(Pr > 0.0){ 
                    S_0 -= Pr*log(Pr);
                }
            }
        }

       std::cout << 0 << "\t" << S_0 << std::endl;
    
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



    //Random walk y conteo en cuadricula
    for (int i = 0; i < Nsteps; ++i)
    {
        int Par = disPar(gen);
        int Dir = disDir(gen);

        //Posicion cuadriacula pasada para particula escogida
        
        int giold = int(((Lcon/2) - pars[Par].Ry)/dx);
        int gjold = int(((Lcon/2) + pars[Par].Rx)/dx);

        //Corrección error para moleculas en el borde

        if(giold == ests.size()){
            giold--;
        } else if (gjold == ests.size()){
            gjold--;
        }
        
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

        //Posicion cuadricula nueva para particual escogida
        
        int ginew =  int(((Lcon/2) - pars[Par].Ry)/dx);
        int gjnew =  int(((Lcon/2) + pars[Par].Rx)/dx);

        //Corrección error para moleculas en el borde

        if(ginew == ests.size()){
            ginew--;
        } else if (gjnew == ests.size()){
            gjnew--;
        }

        //Modificacion de conteo en cuadricula en caso de que haya cambiado

        if(giold != ginew || gjold != gjnew){
            ests[giold][gjold]--;
            ests[ginew][gjnew]++;
        }

       //Calculo entropia para este paso 
        
       double S = 0.0;

        for(int i = 0; i < ests.size(); i++){
            for(int j = 0; j < ests[i].size(); j++){
                
                double Pr = double(ests[i][j])/pars.size();
                
                if(Pr > 0.0){ 
                    S -= Pr*log(Pr);
                }
            }
        }

       std::cout << i+1 << "\t" << S << std::endl;
        
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
