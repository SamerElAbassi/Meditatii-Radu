#include <iostream>
#include <string.h>

using namespace std;

int F(int n) {
    if (n == 0 || n == 1) return 1;
    else
        return 2 * F(n - 1) + 2 * F(n - 2);
}

/* TODO:
    F(3)=2*F(2)+2*F(1)=2*4+2*1=10
    F(2)=2*F(1)+2*F(0)=2*1+2*1=4
    F(1)=1;
    F(0)=1;
*/
void f(long n) {
    if (n > 9) {
        cout << n / 100;
        f(n / 10);
    }
}

/*  TODO: f(12345)=?
 *   f(12345) = Afisez 123 si fac f(1234)
 *   f(1234) = Afisez 12 si fac f(123)
 *   f(123) = Afisez 1 si fac f(12)
 *   f(12) = Afisez 0 si fac f(1)
 *   f(1) = Stop
 *   AFISARE: 1231210
 */
int F1(int x) {
    if (x <= 1) return x;
    else return x + F1(x - 2);
}

/* TODO:
 *  F(18)=18+F(16)=18+16+F(14)=18+16+14+F(12)+...=18+16+14+..+2+F(0)
 *  = 18+16+14+...+2+0=2(9+8+7+...+1)=90
 *  F(16)=16+F(14)
 *  F(14)=14+F(12)
 *  F(2)=2+F(0)=2+0=2
 */

int F2(int x) {
    if (x != 0) return x + F2(x - 1);
    else
        return x;
}

/* TODO:
 *  F(5)=5+F(4)=5+4+F(3)=5+4+3+F(2)
 *  F(4)=4+F(3)=10
 *  F(3)=3+F(2)=6
 *  F(2)=2+F(1)=3
 *  F(1)=1+F(0)=1
 *  F(0)=0
 */

/* TODO:
 *  Sa se calculeze f(n) in sirul lui fibonacci
 *  Sirul lui fibonaacci=
 *  f(0)=1 daca x=0,1
 *  altfel  f(x)=f(x-1)+f(x-2)
 *  1 1 2 3 5 8 13 21 34 .....
 *  EX:
 *  f(6)=?
 *  f(6)=f(5)+f(4)=13
 *  f(5)=f(4)+f(3)=8
 *  f(4)=f(3)+f(2)=5
 *  f(3)=f(2)+f(1)=2+1=3
 *  f(2)=f(1)+f(0)=2
 */
int f_recursiv(int x) {
    if (x == 0 || x == 1)
        return 1;
    else
        return f_recursiv(x - 1) + f_recursiv(x - 2);
}

/*TODO:
 * Se da un numar n. Sa se calculeze produsul n*(n-1)*(n-2)*...*1
 * f(5)=5*4*3*2*1=5*f(4)
   f(4)=4*3*2*1=4*f(3)
   f(3)=3*f(2)
   f(n)=n*f(n-1)
   EX:
    f(5)=5*f(4)=5*4*3*2*1
    f(4)=4*f(3)=4*3*2*1
    f(3)=3*f(2)=3*2*1
    f(2)=2*f(1)=2*1
    f(1)=1
 */
int functie(int n) {
    if (n == 1)
        return 1;
    else
        return n * functie(n - 1);
}

void f_afis(int n) {
    if (n >= 1) {
        cout << n << " sus ";
        f_afis(n - 1);
        cout << n << " jos ";
    }
}
/*TODO:
 * f(5)= Ce afis?
 * 5 sus 4 sus 3 sus 2 sus 1 sus 1 jos2 jos 3 jos 4 jos 5 jos
 */

/*TODO:
 * Să se scrie o funcție C++ recursivă care să returneze numărul de cifre egale
 * cu zero ale unui număr natural transmis ca parametru.
 * n=12345
 *  1. Conditia de stop
 *  2. Daca nu suntem in conditie de stop
 *  2.1. Verificam daca ultima cifra e egala cu 0.
 *       Daca cifra e egala cu 0 returnam 1+nr_cif_zero(x/10)
 *       Daca nu e egala ->nr_cif_zero(x/10)
 */
/* TODO:
 *  nr_cif_zero(1001)=nr_cif_zero(100)=1+nr_cif_zero(10)=1+1+nr_cif_zero(1)=1+1+0=2
 */
int nr_cif_zero(int x) {
    //Conditie de stop
    if (x == 0) {
        return 0;
    } else {
        if (x % 10 == 0)
            return 1 + nr_cif_zero(x / 10);
        else
            return nr_cif_zero(x / 10);
    }
}

/*TODO:
 * 12345
 * Se citeste un nr n. Sa se afiseze cate cifre pare are
 * 1.Conditie de stop
 * 2. Altfel:
 *  2.1 Daca ultima cifra e para = 1+nr_cif_para(n/10)
 *  2.2 Daca nu e para atunci = nr_cif_para(n/10)
*/
int nr_cif_pare(int n) {
    if (n == 0)
        return 0;
    else {
        if (n % 2 == 0)
            return 1 + nr_cif_pare(n / 10);
        else
            return nr_cif_pare(n / 10);
    }
}
/* TODO: Se citeste un nr n. Sa se returneze 1 daca e prim si 0 altfel
 *  n=13;
 *  div=
 *  1. Conditia de stop -> Daca div==n return 1;
 *  2. Ne intrebam daca n%div==0.
 *      Daca n se imparte la divizor return 0;
 *      Daca nu se imparte return prim_recursiv(n,div+1)
 *  EX:
 *  n=35;
 *  div=2
 *  prim_recursiv(35,2)=prim_recursiv(35,3)=prim_recursiv(35,4)=prim_recursiv(35,5)=0
 *   n=7
 *   div=2
 *   prim_recursiv(7,2)=prim_recursiv(7,3)=prim_recursiv(7,4)=prim_recursiv(7,5)
 *   =prim_recursiv(7,6)=prim_recursiv(7,7)=1
 */
int prim_recursiv(int n, int div) {
    if (div == n)
        return 1;
    else {
        if (n % div == 0)
            return 0;
        else {
            return prim_recursiv(n, div + 1);
        }
    }
}


int main() {
    cout << prim_recursiv(14,2);
    return 0;
}
