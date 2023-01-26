#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string test;
    cin >> test;
    unordered_map<char, int> mp;
    for (int p = 0; p < test.size(); p++) {
      mp[test[p]] = p;
    }
    string s;
    cin >> s;
    int sum = 0;
    for (int j = 1; j < s.size(); j++) {
      sum += abs(mp[s[j]] - mp[s[j - 1]]);
    }
    cout << sum << endl;
  }
  return 0;
}
