#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long N = 2e5 + 10;
template <typename T>
bool ckmin(T& a, T b) {
  return b < a && (a = b, true);
}
template <typename T>
bool ckmax(T& a, T b) {
  return b > a && (a = b, true);
}
void testCase() {
  long long n, m;
  cin >> n >> m;
  vector<long long> p(n), inv_p(n), reach(n);
  long long S = sqrt(0.45 * n) + 0.5;
  for (long long& i : p) cin >> i, i--;
  auto compute = [&](long long x) {
    long long i = x;
    for (long long r = 0; r < S; r++) {
      x = p[x];
    }
    return reach[i] = x;
  };
  for (long long i = 0; i < n; i++) {
    compute(i);
    inv_p[p[i]] = i;
  }
  for (long long i = 0; i < m; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, y;
      cin >> x >> y;
      x--, y--;
      swap(inv_p[p[x]], inv_p[p[y]]);
      swap(p[x], p[y]);
      long long sx = compute(x), sy = compute(y);
      for (long long r = 0; r < S; r++) {
        reach[x] = sx, reach[y] = sy;
        x = inv_p[x], y = inv_p[y];
        sx = inv_p[sx], sy = inv_p[sy];
      }
    } else {
      long long x, k;
      cin >> x >> k;
      x--;
      while (k >= S) {
        x = reach[x];
        k -= S;
      }
      while (k--) {
        x = p[x];
      }
      cout << x + 1 << '\n';
    }
  }
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long t_c = 1;
  while (t_c--) testCase();
}
