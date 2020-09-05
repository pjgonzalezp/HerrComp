#include <iostream>
#include <cmath>

float f(float x);
float fmod(float x);

int main (void)
{
    std::cout.precision(8); std::cout.setf(std::ios::scientific);

    float x=0.0;
    for(int N=0; N<=100; N++)
    {
        float n=x+(N*0.01);
        std::cout << x+(N*0.01) << "\t" << f(n) << "\t" <<  fmod(x+(N*0.01)) <<"\t"<< f(n)-fmod(x+(N*0.01))<<"\n";
    }

    return 0;    
}

float f(float x)
{
    float y;
    y = 5.0 - sqrt(25+pow(x,2));

    return y;
}

float fmod (float x)
{
    float z;
    z = -x*x/(5 + sqrt(25 + x*x));

    return z;
}
