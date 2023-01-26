#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int limit = (a + b + 1) >> 1;
    vector<int> ans(a + b + 1);
    for (int i = 0; i <= limit; i++) {
      int s1 = limit, s2 = a + b - limit;
      s2 -= i;
      if (s2 < 0) continue;
      int aa = a - i;
      if (aa < 0) continue;
      s1 -= aa;
      if (s1 < 0) continue;
      ans[i + s1] = 1;
    }
    for (int i = 0; i <= limit; i++) {
      int s1 = a + b - limit, s2 = limit;
      s1 -= i;
      if (s1 < 0) continue;
      int bb = b - i;
      if (bb < 0) continue;
      s2 -= bb;
      if (s2 < 0) continue;
      ans[i + s2] = 1;
    }
    vector<int> v;
    for (int i = 0; i <= a + b; i++) {
      if (ans[i]) {
        v.push_back(i);
      }
    }
    cout << v.size() << '\n';
    for (auto u : v) cout << u << ' ';
    cout << '\n';
  }
  return 0;
}
