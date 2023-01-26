#include <bits/stdc++.h>
using namespace std;
long long k, m, n, q, v, x, y, a[150006], p[150006], w[10], wp[1000005],
    z[1000005];
set<long long> S;
int F(int x) {
  if (x != p[x]) return p[x] = F(p[x]);
  return x;
}
int U(int x, int y) {
  if (x != p[x] || y != p[y]) return p[x] = p[y] = U(p[x], p[y]);
  return p[y] = x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  iota(p, p + n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    z[a[i]] = i;
  }
  for (long long i = 2; i <= 1000000; i++) {
    x = 0;
    for (long long j = i; j <= 1000000; j += i) {
      if (z[j]) {
        if (!x)
          x = z[j];
        else
          U(x, z[j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    x = a[i];
    for (long long t = 2; t * t <= x; t++) {
      if (x % t == 0) {
        wp[t] = F(i);
        while (x % t == 0) x /= t;
      }
    }
    if (x > 1) wp[x] = F(i);
  }
  for (int i = 1; i <= n; i++) {
    x = a[i] + 1;
    v = 0;
    for (long long t = 2; t * t <= x; t++) {
      if (x % t == 0) {
        w[v++] = t;
        if (wp[t]) S.insert(300000 * wp[t] + F(i));
        while (x % t == 0) x /= t;
      }
    }
    if (x > 1) {
      w[v++] = x;
      if (wp[x]) S.insert(300000 * wp[x] + F(i));
    }
    for (int j = 0; j < v; j++) {
      for (int k = j + 1; k < v; k++) {
        if (wp[w[j]] && wp[w[k]]) S.insert(300000 * wp[w[j]] + wp[w[k]]);
      }
    }
  }
  for (; q--;) {
    cin >> x >> y;
    if (F(x) == F(y))
      cout << 0 << '\n';
    else if (S.find(300000 * F(x) + F(y)) != S.end() ||
             S.find(300000 * F(y) + F(x)) != S.end())
      cout << 1 << '\n';
    else
      cout << 2 << '\n';
  }
}
