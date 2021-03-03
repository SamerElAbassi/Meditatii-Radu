#include <iostream>
#include <string.h>

using namespace std;

/* TODO:Se dau coordonatele carteziene a n puncte în plan. Să se determine distanța maximă dintre un punct dat și originea sistemului de
 *  coordonate și numărul de puncte situate la acea distanță față de origine.
 *  7
 *  2 -1
    -2 4
    2 3
    3 -1
    -2 -4
    2 -2
    -4 2
 */
struct punct {
    int x, y;
} v[100];

int main() {
    int n, i, C = 0;
    float distanta, max = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    // distanta de la un punct A(x,y) la origine = sqrt(x^2+y^2)
    for (i = 1; i <= n; i++) {
        distanta = sqrt(v[i].x * v[i].x + v[i].y * v[i].y);
        if (distanta > max)
            max = distanta;
    }
    for (i = 1; i <= n; i++) {
        distanta = sqrt(v[i].x * v[i].x + v[i].y * v[i].y);
        if (distanta == max)
            C++;
    }
    cout << max << " " << C;

    return 0;

}