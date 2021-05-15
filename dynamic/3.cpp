#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	int a;
	while (cin >> a) {
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] - arr[i - 1] > n) {
			cout << arr[i - 1] + n;
			return 0;
		}
	}
	cout << arr[arr.size() - 1] + 5;
}
