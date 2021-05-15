#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<int, vector<int>> mp;

int main() {
	int n;
	cin >> n;
	int id, value;
	for (int i = 0; i < n; i++) {
		cin >> id >> value;
		mp[id].push_back(value);
	}
	int answer = 0;
	for (auto v : mp) {
		sort(v.second.begin(), v.second.end());
		answer += v.second[v.second.size() - 1];
	}
	cout << answer;
}
