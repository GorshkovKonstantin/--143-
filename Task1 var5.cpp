#include <iostream>
#include <cmath>
using namespace std;

/**
 * @param x - value of variable x
 * @param y - value of variable y
 * @param z - value of variable z
 * @return - returns the calculated value
 */
double geta(const double x, const double y, const double z );

/**
 * @param x - value of variable x
 * @param y - value of variable y
 * @param z - value of variable z
 * @return - returns the calculated value
 */

double getb(const double x, const double y, const double z);
/**
 * @return - returns 0 if the program executed correctly
 */
int main()

{
    const double x = -2.9;
    const double y = 15.5;
    const double z = 1.5;
    cout<<"a = "<<geta(x,y,z)<<endl;
    cout<<"b = "<<getb(x,y,z);
    return 0;
}

double geta(const double x, const double y, const double z )
{
    return sqrt(pow(x,2)+y) - pow(y,2) * pow(sin(((x+z)/x)),3);
}

double getb(const double x, const double y, const double z)
{
    return pow(cos(pow(x,3)),2)  - x/(sqrt(pow(x,2)+ pow(y,2)));
}