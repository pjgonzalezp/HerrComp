#include <iostream>
#include <cmath>

float f(float x);
float fmod(float x);

int main (void)
{
    std::cout.precision(8); std::cout.setf(std::ios::scientific);

    float n=0.0;
    for(n=0.0; n<=1.0; n=n+0.01)
    {
           std::cout << n << "\t" << f(n) << "\t" <<  fmod(n) << "\n";
    }
    return 0;
}

float f(float x)
{
    float y;
    y = 5.0 - sqrt( 25-pow(x,2));

    return y;
}

float fmod (float x)
{
    float z;
    z = 5 - sqrt(25 - x*x);

    return z;
}
