#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    map<int, int> m;
    int a = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = 0;
      }
      if (m[s[i]] != -1 && m[s[i]] == 1) {
        ans++;
        m[s[i]] = -1;
      } else if (m[s[i]] != -1) {
        m[s[i]]++;
      }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second == 1) a++;
    }
    cout << ans + (int)a / 2 << "\n";
  }
  return 0;
}
