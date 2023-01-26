#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int x = t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    int ct_1 = 0;
    int ct_0 = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        ct_1++;
      } else if (s[i] == '0') {
        ct_0++;
        pos.push_back(i);
      }
    }
    if (ct_1 == n) {
      cout << 0 << '\n';
      continue;
    }
    if (ct_0 == n) {
      cout << 1 << '\n';
      continue;
    }
    if ((int)pos.size() == 1) {
      cout << 1 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < (int)pos.size() - 1; i++) {
      if (pos[i] + 1 == pos[i + 1]) {
        continue;
      }
      ans += 2;
    }
    cout << min(ans, 2) << '\n';
  }
  return 0;
}
