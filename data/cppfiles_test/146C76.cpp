#include <bits/stdc++.h>
using namespace std;
void solution() {
  constexpr long long S = 300;
  long long n, q;
  cin >> n >> q;
  vector<long long> p(n + 1);
  vector<long long> rev(n + 1);
  for (long long i = 1; i <= n; ++i) {
    cin >> p[i];
    rev[p[i]] = i;
  }
  vector<long long> next(n + 1);
  for (long long i = 1; i <= n; ++i) {
    long long x = i;
    for (long long j = 0; j < S; ++j) x = p[x];
    next[i] = x;
  }
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, y;
      cin >> x >> y;
      swap(rev[p[x]], rev[p[y]]);
      swap(p[x], p[y]);
      long long sx = x;
      for (long long i = 0; i < S; ++i) {
        sx = p[sx];
      }
      long long sy = y;
      for (long long i = 0; i < S; ++i) {
        sy = p[sy];
      }
      for (long long i = 0; i <= S; ++i) {
        next[x] = sx, next[y] = sy;
        x = rev[x], y = rev[y];
        sx = rev[sx], sy = rev[sy];
      }
    } else {
      long long i, k;
      cin >> i >> k;
      while (k >= S) {
        i = next[i];
        k -= S;
      }
      while (k >= 1) {
        i = p[i];
        k -= 1;
      }
      cout << i << "\n";
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solution();
}
