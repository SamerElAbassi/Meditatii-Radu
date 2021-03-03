#include <iostream>
#include <string.h>

using namespace std;

/* TODO:Scrieţi definiția completă a unui subprogram C++ i_prim care primește prin singurul său parametru, n, un număr natural cu cel mult 9 cifre
 *   și returnează diferența minimă p2-p1 în care p1 şi p2 sunt numere prime și p1<=n<=p2.
 *   n=28, i_prim(28)=6 pentru ca p1=23 p2=29
 *   n=14 -> p1=13 p2=17
 */
int prim(int x) {
    // Returneaza 1 daca numarul e prim, altfel returneaza 0
    int div;
    if (x == 1)
        return 0;
    for (div = 2; div <= x / 2; div++) {
        if (x % div == 0)
            return 0;
    }
    return 1;
}

int i_prim(int n) {
    int p1 = n, p2 = n;
    while (!prim(p1) ||
           !prim(p2)) { //cat timp inca n-am gasit numerele p1 si p2, care de fapt inseamna ca cel putin unu dintre ele nu e prim/bun
        if (!prim(p1))
            p1--;
        if (!prim(p2))
            p2++;
    }
    cout << p1 << " " << p2;
    return 0;
}

/* TODO:
 *  Funcția primește ca parametru un număr natural n și
 *  trebuie să returneze numărul de numere naturale nenule prime cu n și strict mai mici decât n.
 *  Phi(12) = 4
 */

int cmmdc(int x, int y) {
    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

int Phi(int n) {
    int x, C = 0;
    for (x = 1; x < n; x++) {
        if (cmmdc(x, n) == 1)
            C++;
    }
    return C;
}

/* TODO:
 *  Subprogramul rearanjează elementele tabloului astfel încât toate valorile impare să se afle pe primele poziţii,
 *  iar valorile pare în continuarea celor impare. Ordinea în cadrul secvenţei de elemente pare, respectiv în cadrul secvenţei
 *  de elemente impare, poate fi oricare.
 *  Pentru n=7 şi v=(21, 37, 42, 7, 48, 25, 9), după apel, elementele vectorului ar putea fi (21, 37, 7, 25, 9, 42, 48).
 *  -daca e impar il las in pace
 *  -daca e par -> v=(21,37,7,48,25,9,9) -> (21,37,7,48,25,9,42)
 *  operatia generala:
 *  v[j]=v[j+1]
 *  for j de la i la n-2
 *  j=i -> v[i]=v[i+1]
 *  j=i+1 -> v[i+1]=v[i+2]
 *  j=i+2 -> v[i+2]=v[i+3]
 *  ...
 *  j=n-2 -> v[n-2]=v[n-1]
 *  v[i]=v[i+1]; v[i+1]=v[i+2]....v[n-2]=v[n-1]
 *  De ce nu merge?
 *  n=7;
 *  v=(21,37,42,7,48,25,9);
 *  v[i]=42
 *  temp=
 *  i=2
 *  n-1
 *  1 element -> n-2
 *  1 element -> n-3
 *  1 element -> n-4
 *  am gasit alt element si merg pana la n-3 inseamna ca pe v[n-2] si pe v[n-1] le ignor
 *  am gasit alt eleemnt merg pana la -> n-4
 */
void aranjare(int v[], int n) {
    int temp,i,j,C=0;
    for (i = 0; i < n-C; i++) {
        if (v[i] % 2 == 0) {
            cout<<"Am gasit "<<v[i]<<". Incepem mutarile."<<endl;
            // il punem la coada
            temp=v[i];
            for (j=i;j<=n-2;j++)
                v[j]=v[j+1];
            v[n-1]=temp;
            i--;
            C++;
            cout<<"Vectorul dupa mutari:";
        }
    }
}
void afisare(int v[],int n){
    for (int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

