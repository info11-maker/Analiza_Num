// Proiect2Gauss-Seidel_MiAl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Proiect2Gauss_MiAl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define Nmax 10

int main()
{

    int k = 0, i, j, n = 5;
    double a[Nmax][Nmax] = { { 70, 1, -1, 5, 3}, { 1, 71, -2, -4, -3 }, { -2, -1, 72, 4, 2 }, { -3, 1, -4, 73, 1 }, { 5, 2, 1, -1, 74 } }, b[Nmax] = { 905, 1920, 1530, 1055, 3075 };
    //double a[Nmax][Nmax] = { { 4, 1, 1}, { 1, 5, 2}, { 1, 2, 8} }, b[Nmax] = { 12, 13, 28 };
    double d, eps = 1e-3, max, norma, r[Nmax], x[Nmax], m[Nmax][Nmax], c[Nmax];

    printf("\n Sistemul initial\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%8.2lf", a[i][j]);
        printf(" | %8.2lf\n", b[i]);
    }

    for (i = 0; i < n; i++) {
        m[i][i] = 0;
        for (j = 0; j < n; j++)
            if (j != i)
                m[i][j] = -a[i][j] / a[i][i];
        c[i] = b[i] / a[i][i];
    }
    printf("\n Matricea M si Vetorul C \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%8.2lf", m[i][j]);
        printf(" | %8.2lf\n", c[i]);
    }
    max = 0;
    for (i = 0; i < n; i++) {
        d = 0;
        for (j = 0; j < n; j++)
            d += fabs(m[i][j]);
        if (d > max)
            max = d;
    }
    if (d >= 1) {
        printf("Nu este satisfacuta conditia suficienta");
        //getch();
        return 0;
    }
    //Procesul iterativ
    printf("\nAproximatia initiala\n");
    for (i = 0; i < n; i++) {
        x[i] = c[i];
        printf(" %8.2lf", x[i]);
    }
    printf("\n");
    k = 0;
    printf("\n Restul initial, R0\n");
    norma = 0;
    for (i = 0; i < n; i++) {
        r[i] = -b[i];
        for (j = 0; j < n; j++)
            r[i] = r[i] + a[i][j] * x[j];
        printf(" %8.2lf", r[i]);
        if (fabs(r[i]) > norma) norma = fabs(r[i]);
    }
    printf("\n");
    while (norma > eps) {
        i = k % n;
        k++;
        x[i] = x[i] - r[i] / a[i][i];
        //Afisam x[i]
        printf("\nAproximatia X%d\n", k);
        for (i = 0; i < n; i++)
            printf(" %8.2lf", x[i]);
        printf("\n");
        printf("\n Restul R%d\n", k);
        norma = 0;
        for (i = 0; i < n; i++) {
            r[i] = -b[i];
            for (j = 0; j < n; j++)
                r[i] = r[i] + a[i][j] * x[j];
            printf(" %8.2lf", r[i]);
            if (fabs(r[i]) > norma) norma = fabs(r[i]);
        }
        printf("\n");
    }
    //Verificare ca la Gauss
    //R = ax-b 

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
