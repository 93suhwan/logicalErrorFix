#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++) {
      if (m[s[i]] == 2) {
        continue;
      }
      m[s[i]]++;
      ans++;
    }
    cout << ans / 2 << "\n";
  }
  return 0;
}
