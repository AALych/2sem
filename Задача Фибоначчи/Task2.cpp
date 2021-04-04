#include <iostream>

using namespace std;

int main() {
    int f1 = 1, f2 = 1, f3, n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (!(f1 % 2))
            sum += f1;
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    cout << sum << endl;
    return 0;
}
