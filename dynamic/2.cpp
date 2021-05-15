#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	int b, s = 0;
	while (cin >> b) {
		a.push_back(b);
		s += b;
	}
	vector<int> dp(s);
	dp[0] = 1;
	for (int i = 1; i < a.size(); i++) {
		vector<int> v;
		for (int j = 0; j < s; j++) {
			if (dp[j]) {
				v.push_back(j + a[i]);
			}
		}
		for (auto j : v) {
			dp[j] = 1;
		}
	}
	if (dp[(s - n) / 2]) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
