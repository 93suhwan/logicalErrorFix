#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
int i, j, k, n, m, t, x, y, z;
int l[100500], r[100500], l300[100500], r300[100500], k2;
vector<pair<int, int> > v1, v2;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> t;
  for (i = 1; i <= n; i++) {
    cin >> r[i];
    l[r[i]] = i;
  }
  for (i = 1; i <= n; i++) {
    k = i;
    for (j = 1; j <= 100; j++) {
      k = r[k];
    }
    r300[i] = k;
    l300[k] = i;
  }
  while (t--) {
    cin >> x >> y >> z;
    if (x == 1) {
      swap(r[y], r[z]);
      l[r[y]] = y;
      l[r[z]] = z;
      k = y;
      for (i = 1; i < 100; i++) {
        k = l[k];
      }
      v1.clear();
      k2 = r[y];
      for (i = 1; i <= 100; i++) {
        v1.push_back({k, k2});
        k = r[k];
        k2 = r[k2];
      }
      k = z;
      for (i = 1; i < 100; i++) {
        k = l[k];
      }
      v2.clear();
      k2 = r[z];
      for (i = 1; i <= 100; i++) {
        v2.push_back({k, k2});
        k = r[k];
        k2 = r[k2];
      }
      for (auto [i, j] : v1) {
        r300[i] = j;
        l300[j] = i;
      }
      for (auto [i, j] : v2) {
        r300[i] = j;
        l300[j] = i;
      }
    } else {
      while (z > 100) {
        y = r300[y];
        z -= 100;
      }
      while (z) {
        y = r[y];
        z--;
      }
      cout << y << '\n';
    }
  }
}
