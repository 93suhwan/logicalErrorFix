#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int k;
    int m = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
    }
    for (auto x : mp) {
      if (x.second > 2) {
        m += 2;
      } else {
        m = m + x.second;
      }
      k = m / 2;
    }
    if (s.size() == 1) k = 0;
    cout << k << "\n";
  }
  return 0;
}
