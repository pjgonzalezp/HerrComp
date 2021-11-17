#include "Cof-simul.h"

//Funcion main
int main(void){

    std::vector<Molecule> Mol(N);
    std::vector<std::vector<int>> Grid (LG, std::vector<int> (LG,0));
    
    
    Initial (Mol,Grid,LL,DXG,LC);
    Step (Mol,Grid,SEED,IT,DXG,LC);
//    Print (Mol);

   return 0;
}

