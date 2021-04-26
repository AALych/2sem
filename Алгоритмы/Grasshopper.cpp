#include <iostream>;
using namespace std;
#include <cmath>;

int Number_of_routs(int n){
    int P[n+1];
    P[0]=1;
    P[1]=1;
    P[2]=2;
    for (int i = 3; i <= n; ++i)
        P[i]=P[i-1]+P[i-2]+P[i-3];
    return P[n];
}

int main(){
    int n, p;
    cin >> n;
    p = Number_of_routs(n);
    cout << p << endl;
    return 0;
}
