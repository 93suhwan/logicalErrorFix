#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long m = 1;
    int ans = INT_MAX, flag = 1;
    string s, p;
    cin >> s;
    if (s.empty()) {
      cout << 1 << endl;
      continue;
    }
    for (int x = 0; x <= 60; x++) {
      p = to_string((long long)1 << x);
      int i, j;
      for (i = 0, j = 0; j < p.size() && i < s.size(); i++) {
        if (s[i] == p[j]) j++;
      }
      ans = min(ans, (int)(s.size() + p.size() - 2 * j));
    }
    cout << ans << endl;
  }
  return 0;
}
