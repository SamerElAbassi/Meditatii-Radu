#include <iostream>
#include <string.h>

using namespace std;

/* TODO:Se consideră un șir cu n elemente, numere naturale. Folosind metoda Divide et Impera, determinați cel mai mare element din acest șir.
 *
 */
int divide_max(int v[], int st, int dr) {
    if (st == dr)
        return v[st];
    else {
        int m = (st + dr) / 2;
        int max_st = divide_max(v, st, m);
        int max_dr = divide_max(v, m + 1, dr);
        if (max_st > max_dr)
            return max_st;
        else
            return max_dr;
    }
}

int are_nr_par_cifre(int nr) {
    int C = 0;
    while (nr != 0) {
        C++;
        nr = nr / 10;
    }
    if (C % 2 == 0)
        return 1;
    else
        return 0;
}

/* TODO:Se dă un şir cu n elemente, numere naturale.
 *  Folosind metoda Divide et Impera să se verifice dacă toate elementele şirului au număr par de cifre. Sa returneze 1 daca e asa. 0 altfel
 *  16 5 41 32 = 0
 *  16 5 = 1 0 return 1 && 0 = 0    0 && 1 da 0
 *  41 32 = 1 1 return 1 && 1 = 1
 */

int divide_pb(int v[], int st, int dr) {
    if (st == dr) {
        return are_nr_par_cifre(v[st]);
    } else {
        int m = (st + dr) / 2;
        int par_st = divide_pb(v, st, m);
        int par_dr = divide_pb(v, m + 1, dr);
        return (par_st && par_dr);
    }

}

/* TODO: Se dă un sir cu n elemente, numere naturale nenule. Folosind metoda Divide et Impera, determinaţi cel mai mare divizor comun al elementelor acestui șir.
    18 54 24 42
    18 54 = 18    54 = 18 cmmdc_st  cmmmdc
    24 42 = 24    42 = 6  cmmdc_dr
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

int divide_cmmdc(int V[], int st, int dr) {
    if (st == dr)
        return V[st];
    else {
        int m = (st + dr) / 2;
        int cmmdc_st = divide_cmmdc(V, st, m);
        int cmmdc_dr = divide_cmmdc(V, m + 1, dr);
        cout << cmmdc_st << " " << cmmdc_dr << " " << cmmdc(cmmdc_st, cmmdc_dr) << endl;
        return cmmdc(cmmdc_st, cmmdc_dr);
    }
}

/* TODO:Se dă un şir cu n elemente, numere naturale. Folosind metoda Divide et Impera să se verifice dacă în șir există elemente prime.
 *  nr=4
 */
int prim(int nr) {
    int i;
    if (nr <= 1)
        return 0;

    for (i = 2; i <= nr / 2; i++) {
        if (nr % i == 0)
            return 0;
    }
    return 1;
}

int divide_prim(int V[], int st, int dr) {
    if (st == dr)
        return prim(V[st]);
    else {
        int m = (st + dr) / 2;
        int prim_st = divide_prim(V, st, m);
        int prim_dr = divide_prim(V, m + 1, dr);
        return prim_st || prim_dr;
    }
}

/* TODO: Se consideră un șir cu n elemente, numere naturale.
 * Folosind metoda Divide et Impera, determinați cel mai mare element prim din acest șir.
 */
int divide_prim_max(int V[], int st, int dr) {
    if (st == dr)
        if (prim(V[st]))
            return V[st];
        else
            return 0;
    else {
        int m = (st + dr) / 2;
        int max_st = divide_prim_max(V, st, m);
        int max_dr = divide_prim_max(V, m + 1, dr);
        if (max_st > max_dr)
            return max_st;
        else
            return max_dr;
    }
}

int main() {
    int i, V[100], n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> V[i];
    cout << divide_prim_max(V, 0, n - 1);
    return 0;
}