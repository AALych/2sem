#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<double>> m(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	long long len;
	double det, a = 1, b = 0, c = 1, d = 0;
	for (int i = 0; i < n; i++)
	{
		a = c = 1;
		len = (2 * n) - 1 - i;
		for (int j = 0; j < n; j++)
		{
			a *= m[j][(i + j) % (n)];
			c *= m[j][len % n];
			len--;
		}
		d += c;
		b += a;
	}
	det = b - d;
	cout << det;
}
