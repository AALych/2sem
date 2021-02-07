#include <iostream>
using namespace std;

int main()
{
    char c;
    int N, i, j, m;
    cin >> N >> c;
    m = 1;
    for (j=0; j<N; j++){
        for (i=0; i<m; i++)
            cout << c;
        m++;
        cout << endl;}
    return 0;
}
