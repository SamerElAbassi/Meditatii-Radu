#include <iostream>
#include <string.h>

using namespace std;

void ex1() {
    int n, i, j, v[100];
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i <= n - 1; i++) {
        if (v[i] % 2 == 0) {
            for (j = n; j >= i + 1; j--)
                v[j + 1] = v[j];
            v[i + 1] = 2;
            n = n + 1;
            i = i + 1;
        }
    }
    for (i = 1; i <= n; i++)
        cout << v[i] << " ";
}

int prim(int x) { // Returneaza 1 daca numarul este prim. 0 altfel. prim(1)
    // Ce inseamna ca x sa fie numar prim? Se imparte doar la 1 si la el
    int nr;
    if (x < 2)
        return 0;
    for (nr = 2; nr <= x / 2; nr++)
        if (x % nr == 0)
            return 0;
    return 1;
}

void ex2() {
    int n, i, v[100], C, j;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    for (i = 1; i <= n; i++) {
        if (prim(v[i])) {
            for (j = i; j <= n - 1; j++)
                v[j] = v[j + 1];
            n = n - 1;
            i = i - 1;
        }
    }
    for (i = 1; i <= n; i++)
        cout << v[i] << " ";
}

int Suma(int V[], int st, int dr) {
    if (st == dr)
        return V[st]; // problemă elementară
    else {
        int m = (st + dr) / 2; // împărțim problema în subprobleme
        int s1 = Suma(V, st, m); // rezolvăm prima subproblemă
        int s2 = Suma(V, m + 1, dr); // rezolvăm a doua subproblemă
        return s1 + s2; // combinăm rezultatele
    }
}

// Se dă un şir cu n elemente, numere naturale. Folosind metoda Divide et Impera să se verifice dacă în şir există elemente impare.
int numere_impare(int V[], int st, int dr) {
    if (st == dr) {
        if (V[st] % 2 == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        int m = (st + dr) / 2;
        int c_st = numere_impare(V, st, m);
        int c_dr = numere_impare(V, m + 1, dr);
        return c_st + c_dr;
    }
}
// Se consideră un șir cu n elemente, numere naturale. Folosind metoda Divide et Impera, determinați suma elementelor pare din acest șir.
int suma_pare(int V[], int st, int dr) {
    if (st == dr) {
        if (V[st]%2==0)
            return V[st];
        else
            return 0;
    }
    else
    {
        int m = (st + dr) / 2;
        int s_st = suma_pare(V, st, m);
        int s_dr = suma_pare(V, m + 1, dr);
        return s_st+s_dr
    }
}
//Se consideră un șir cu n elemente, numere naturale. Folosind metoda Divide et Impera, determinați cel mai mare element din acest șir.
int maxim(int V[], int st, int dr) {
    if (st == dr) {
        return numai_cifre_pare(V[st]);
    }
    else
    {
        int m = (st + dr) / 2;
        int c_st = maxim(V, st, m);
        int c_dr = maxim(V, m + 1, dr);
        return c_st+c_dr;
    }
}
int main() {
    int n,v[100],i;
    cin>>n;
    for (i=0;i<n;i++)
        cin>>v[i];
}