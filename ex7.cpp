#include <iostream>

using std::cout;
using std::endl;

int main(){
    int a = 1, b = 2, c, S, i = 0, N = 4000000;
    S += b;
    while (a + b < N) {
        c = a;
        a = b;
        b = b + c;
        i++;
        if (i % 2 == 0) S += b;
    }
    cout << S << endl;
    return 0;
}
