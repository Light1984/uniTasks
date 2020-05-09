#include <iostream>
#include <cmath>
using namespace std;

const double Epsilon = 0.000001;
const double PI = 3.141592653589793;

double root(double x)
{
    double u = x;
    
    while (abs(u - (0.5 * (u + x / u))) > Epsilon / 3.6)
        u = 0.5 * (u + x / u);

    return u;
}

double sh(double x)
{
    double u = x;
    double sum = u;

    for (int n = 1; abs(u) / 3 > Epsilon / 3.6; ++n)
    {
        u *= pow(x, 2) / (2*n * (2*n + 1));

        
        sum += u;

    }

    return sum;
}


double arctg(double x)
{
    double u = 1 / x;
    double sum = u;

    for (int n = 1; abs(u) > Epsilon / 3.6; ++n)
    {
        u = (-1) * u *(2 * n - 1) / (x * x * (2 * n + 1));
        

        sum += u;

    }

    if (x < 0)
        return (-1) * PI / 2 - sum;
    else return (PI / 2) - sum;
}

double QuickMath(double x)
{
    double v = sqrt(2 * x + 0.45);
    double u = (exp(v) - exp(-v)) / 2;
    double w = atan(6 * x + 1);
    return u / w;
}

double SlowMath(double x)
{
    double v = root(2 * x + 0.45);
    double u = sh(v);
    double w = arctg(6 * x + 1);
    return u / w;
}

int main()
{
    for (double x = 0.01; x < 0.061; x += 0.005)
        cout << SlowMath(x) << " " << QuickMath(x) << " " << abs(SlowMath(x) - QuickMath(x)) << endl;
    
}
