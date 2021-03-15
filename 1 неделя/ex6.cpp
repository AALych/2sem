#include <iostream>
using namespace std;

int main()
{
    int N, i, m, p;
    char c;
    cin >> N >> c;
    p = 0;
    m = N;
    while (m>0) {
        for (i = 0; i < p; i++)
            cout << ' ';
        for (i = 0; i < m; i++)
            cout << c;
        p++;
        m -= 2;
        cout << endl;
    }
    return 0;
}
