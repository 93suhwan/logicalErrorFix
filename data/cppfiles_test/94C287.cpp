#include <bits/stdc++.h>
using namespace std;
int q[19];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(q, 0, sizeof(q));
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j) q[i + j]++;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    while (n > 0) {
      v.push_back(n % 10);
      n /= 10;
    }
    long long ans = 1;
    for (int i = 0; i < (int)v.size(); ++i) ans *= q[v[i]];
    int o = (int)v.size() - 2;
    if (o < 0) {
      cout << ans - 2 << '\n';
      continue;
    }
    for (int m = 1; m < (1 << o); ++m) {
      int bad = false;
      for (int u = 0; u < o; ++u) {
        if (m & (1 << u) and v[u + 2] == 0) {
          if (!(m & (1 << (u + 2)))) {
            bad = true;
          }
        }
      }
      if (bad) continue;
      for (int u = 0; u < o; ++u) {
        if (m & (1 << u)) {
          v[u] += 10;
          v[u + 2]--;
        }
      }
      long long tmp = 1;
      for (int i = 0; i < (int)v.size(); ++i) tmp *= q[v[i]];
      ans += tmp;
      for (int u = 0; u < o; ++u) {
        if (m & (1 << u)) {
          v[u] -= 10;
          v[u + 2]++;
        }
      }
    }
    cout << ans - 2 << '\n';
  }
}
