#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> mp;
unordered_map<char, bool> opening;

int main() {
    stack <char> a;
    int n;
    cin >> n;
    string pairs;
    for (int i = 0; i < n; i++) {
        cin >> pairs;
        mp[pairs[0]] = pairs[1];
        opening[pairs[0]] = true;
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (opening[s[i]]) {
            a.push(s[i]);
        }
        else {
            if ((a.size() != 0) && ((mp[a.top()] == s[i]))) {
                a.pop();
            }
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    if (a.empty()) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
