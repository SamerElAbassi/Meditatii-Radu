//
// Created by Samer on 2/17/2021.
//
#include <iostream>
#include <string.h>

using namespace std;

/* TODO: f(121,1)=?
 *  = f(40,2) = f(13,3) = f(4,4) = f(1,5) = f(0,6) = 6
 */
void f(long n, int i) {
    if (n == 0) cout << i;
    if (n % 3 > 0) f(n / 3, i + 1);
}


/*TODO: f(125) = "5" + "5" si f(1)
 *      f(1)="1" + "1" + f(0)
 *      f(0)="0"
 * afisare:55110
 */
void f(int n) {
    cout << n % 10;
    if (n != 0) {
        cout << n % 10;
        f(n / 100);
    }
}

/*TODO:f(15,2) =
 * f(15,6) + "2" =
 * f(15,10) + "6" + "2" =
 * f(15,14) + "0" + "6" +"2"
 * f(15,18) + "4" + "0" +"6" +"2"
 * = "*" + "4" + "0" +"6"+"2"
 * afisare:*4062
 */

void f(int n, int x) {
    if (x > n)
        cout << '*';
    else {
        f(n, x + 4);
        cout << x % 10;
    }
}

/*TODO: f(12345) = "5" + f(1234)
 * f(1234) = f(123) + "4"
 * f(123) = "3" + f(12)
 * f(12) = f(1) + "2"
 * f(1) = "1" + f(0)
 * f(0) = rand nou
 * afis:53124
 */
void f(long n) {
    if (n != 0) {
        if (n % 2 != 0)
            cout << n % 10;
        f(n / 10);
        if (n % 2 == 0)
            cout << n % 10;
    } else cout << endl;
}

/*TODO: suma(3,2)=1+suma(2,2)=2+suma(1,2)=
 * 3+suma(0,2)=4+suma(0,1)=5+suma(0,0)=5+0= 5
 *
 */
int suma(int a, int b) {
    if ((a == 0) && (b == 0)) return 0;
    if (a == 0) return 1 + suma(a, b - 1);
    return 1 + suma(a - 1, b);
}

/*TODO: f(17),f(22)
 * f(17)=1+f(14)=2+f(11)=3+f(8)=3+0=3
 * f(22)=1+f(19)=2+f(16)=2
 */
int f_var_24(int n){
    if (n<=9) return 0;
    if (n%4==0) return 0;
    return 1+f_var_24(n-3);
}

/*TODO:f(16), f(n)=2 cu n de 2 cifre
 * f(16)=0
 * Prima conditie: n nu se imparte la 2,3 si nu e negativ
 * f(n)= 1+f(n-10) = 2 -> f(n-10)=1
 * f(n-10)= 1 + f(n-20), daca si numai daca n-10 nu se imparte la 2,3 si e poz
 * dar f(n-10)=1 deci f(n-20)=0
 * dar f(n-20)=0 daca si numai daca n-20 se imarte la 2 la 3
 * Raspuns:35
 */
int f_25(int n){
    if (n<=0) return -1;
    if (n%2==0) return 0;
    if (n%3==0) return 0;
    return 1+f_25(n-10);
}

/*TODO:
 * f(7,11),f(11,7)
 * f(7,11)=-4
 * --------------------------
 * f(11,7)=f(-4,10)+3=-4-10+3=-11
 */
int f_37(int x,int y){
    if (x<=y) return x-y;
    return f_37(y-x,x-1)+3;
}
/*TODO:
 * sc(1000)=?
 * sc(1000)=sc(100)+0=sc(10)+0=sc(1)+0=1
 * --------------------------
 * sc(901324)=?
 * sc(901324)=sc(90132)+4=sc(9013)+2+4=sc(901)+3+2+4=sc(90)+1+3+2+4=sc(9)+1+3+2+4=9+1+3+2+4
 */
int sc(long x){
    if (x<10) return x;
    return sc(x/10)+x%10;
}
/*TODO:
 * f(7)=?
 * f(7)=f(6)=6
 * --------------
 * f(100)=f(96)=96
 */
int f_42(int x){
    if (x%6==0) return x;
    else return f_42(x-1);
}

/*TODO:
 * f(6,5)=?
 * =f(5,5)=5
 * ---------------
 * f(5,10)=7
 * Medie aritmetica fara ,
 */
int f_44(int x,int y){
    if (x==y) return x;
    else if (x<y) return f_44(x+1,y-1);
    else return f_44(x-1,y);
}