#include <iostream>
using namespace std;

int main()
{
    char c;
    int N, i, j;
    cin >> N >> c;
    for (j=0; j<N; j++){
        for (i=0; i<N; i++)
            cout << c;
        cout << endl;}
    return 0;
}
