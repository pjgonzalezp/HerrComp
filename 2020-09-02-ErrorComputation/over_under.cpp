#include <iostream>

int main (int argc, char **argv)
{
    float under=1.0, over=1.0;
    int N=150;

    for(int ii=0; ii<N; ii++)
    {
        under /=2.0;
        over *=2.0;
        std::cout << ii
                  << "\t" << under
                  << "\t" << over
                  << "\n";
    }

    return 0;
}
