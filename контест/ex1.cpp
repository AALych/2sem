#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    cin >> M;
    while (M!=N) {
        if (M>N) M = M - N;
        else if (M<N) N = N - M;
    }
    cout << M << endl;
    return 0;
}
