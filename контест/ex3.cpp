#include <iostream>
using namespace std;

int main(){
    int N, A;
    A = 0;
    cin >> N;
    while (N != 0){
        if (N % 2 == 0) A++;
        cin >> N;
    }
    cout << A << endl;
    return 0;
}

