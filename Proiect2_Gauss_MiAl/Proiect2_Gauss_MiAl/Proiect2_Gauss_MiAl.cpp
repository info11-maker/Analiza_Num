// Proiect2_Gauss_MiAl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdio.h>
#define NMAX 10
using namespace std;
int main()
{
    int i, j, k, l, m, n = 5;
    //double A[NMAX][NMAX + 1] = {{4, 1, 1, 12}, {1, 5, 2, 13}, {1, 2, 8, 28}};
    double A[NMAX][NMAX + 1] = { {70, 1, -1, 5, 3, 905}, {1, 71, -2, -4, -3, 1920}, {-2, -1, 72, 4, 2, 1530},{-3, 1, -4, 73, 1, 1055},{5, 2, 1, -1, 74, 3075} };
    double a[NMAX][NMAX + 1], x[NMAX];
    double aux, det = 1;
    //Citirea datelor
    cout << "Proiect nr.2, Mihalachi Alexandrina" << endl;
    cout << "Aplicarea metodei Gauss-Jordan(clasica)" << endl;
    cout << "\n Sistemul initial" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = A[i][j];
            printf(" %8.2lf", a[i][j]);
        }
        a[i][n] = A[i][n];
        printf(" | %8.2lf\n", a[i][n]);
    }
    //Etapa 1
    for (l = 0; l < n; l++)
    {
        if (a[l][l] == 0) {
            m = l + 1;
            while ((a[m][l] == 0) && (m < n)) m++;
            if (m >= n) {
                cout << " Det = 0. Sistemul nu are o singura solutie" << endl;
                return 0;
            }
            for (j = 0; j <= n; j++) {
                aux = a[m][j]; a[m][j] = a[l][j]; a[l][j] = aux;
                det = -det;
            }
        }
        det = det * a[l][l];
        for (j = l + 1; j <= n; j++) a[l][j] /= a[l][l];
        a[l][l] = 1;
        for (i = l + 1; i < n; i++)
        {
            for (j = l + 1; j <= n; j++)
                a[i][j] = a[i][j] - a[i][l] * a[l][j];
        }
        for (i = l + 1; i < n; i++)
            a[i][l] = 0;
        cout << "\n Sistemul la pasul " << l + 1 << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf(" %8.2lf", a[i][j]);
            printf(" | %8.2lf\n", a[i][n]);
        }
    }
    for (j = 0; j < n; j++)
        det = det * a[j][j];
    cout << "\n Determinantul matricei este " << det << endl;
    //Etapa 2
    x[n - 1] = a[n - 1][n];
    for (i = n - 2; i >= 0; i--)
    {
        aux = 0;
        for (j = i + 1; j < n; j++)
            aux = aux + a[i][j] * x[j];
        x[i] = a[i][n] - aux;
    }
    cout << "\n Solutia Sistemului " << endl;
    for (i = 0; i < n; i++)
        printf(" %8.2lf", x[i]);
    printf("\n");
    cout << "\n Verificarea " << endl;
    for (i = 0; i < n; i++) {
        aux = -A[i][n];
        for (j = 0; j < n; j++)
            aux = aux + A[i][j] * x[j];
        printf("%8.2le", aux);
        cout << endl;
    }

    cout << "\n Matricea inversata " << endl;
    for (i = 1; i <= n;i++)
    {
        for (j = n + 1; j <= 2 * n; j++)
        {
            cout << a[i][j] << "\t";
            printf("%5.2lf", a);
        }
        cout << endl;
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
