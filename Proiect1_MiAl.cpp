// Proiect1_MiAl.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;
double eps = 1e-9;

struct Interval
{
    double st;
    double dr;
} 
r[10];
double f(double x)
{
    return x * x * x + x * x - 40 * x - 40;
}
double fpr(double x)
{
    return 3 * x * x + 2 * x - 40;
}
int Separare(double A, double B, double h)
{
    int n = 0;
    double x0, x;
    x0 = A;
    do
    {
        x = x0 + h;
        if (f(x) == 0) {
            r[n].st = r[n].dr = x;
            n++; x0 = x + eps;
        }
        if (f(x0) * f(x) < 0)
        {
            r[n].st = x0; r[n].dr = x;
            n++;
        }
        x0 = x;
    } while (x < B);
    return n;
}
int main()
{
    int k, i, n;
    double A = -5, B = 60, h = 0.07;
    cout << "Proiect nr. 1, Mihalachi Alexandrina!" << endl;
    n = Separare(A, B, h);
    for (i = 0; i < n; i++)
    {
        cout << " O solutie separata este pe [" << r[i].st << "; " << r[i].dr << "]" << endl;
    }
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
