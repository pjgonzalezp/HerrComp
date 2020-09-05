#include <iostream>
#include <cmath>

float f(float x);
float fmod(float x);

int main (void)
{
   

    float x=0.0;
    for(int N=0; N<=100; N++)
    {
        std::cout.precision(8); std::cout.setf(std::ios::scientific);
        float n=x+(N*0.01);
        std::cout << x+(N*0.01) << "\t" << f(n) << "\t" <<  fmod(x+(N*0.01)) <<"\n";
    }

    return 0;    
}

float f(float x)
{
    float y;
    y = 5.0 - sqrtf(25.0 + x*x);

    return y;
}

float fmod (float x)
{
    float z;
    z = -x*x/(5.0 + sqrtf(25.0 + x*x));
    
    return z;
}
