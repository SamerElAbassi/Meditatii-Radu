#include <iostream>
#include <string.h>

using namespace std;
struct elev {
    char nume[20], prenume[20];
    int nota1, nota2;
    float medie;
} v[100];

void afisare(elev v[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        cout << "-------ELEV NOU-------" << endl;
        cout << v[i].nume <<" "<< v[i].prenume << endl;
        cout << "Nota1 = " << v[i].nota1 << " Nota2 = " << v[i].nota2 << ". Medie=" << v[i].medie;
        cout << endl;
    }
}

int main1() {
    int n, i, j;
    elev aux;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> v[i].nume >> v[i].prenume;
        cin >> v[i].nota1 >> v[i].nota2;
    }
    afisare(v, n);
    cout << endl << "------------------" << endl;
    //Sa se calculeze mediile pentru fiecare elev
    for (i = 1; i <= n; i++) {
        v[i].medie = (v[i].nota1 + v[i].nota2) / (float) 2;
    }
    afisare(v, n);
    // Sa se sorteze crescator elevii dupa medie
    cout << endl << "Elevii dupa sortare" << endl;
    for (i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++)
            if (v[i].medie > v[j].medie) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;

            }
    }
    // Sa se afiseze toti corijentii (medie <5) in ordine alfabetica
    afisare(v, n);
    cout<<endl<<"Acum vom sorta alfabetic"<<endl;
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++) {
            if (strcmp(v[i].nume, v[j].nume) == 1) { // Numele nu sunt sortate
                aux=v[j];
                v[j]=v[i];
                v[i]=aux;
            }
        }
    cout<<endl<<"Sortati alfabetic"<<endl;
    afisare(v,n);
    cout<<"Afisat corijentii"<<endl;
    for (i=1;i<=n;i++)
        if (v[i].medie<5){
            cout<<v[i].nume<<" "<<v[i].prenume<<" "<<v[i].medie<<endl;
        }

    return 0;
}