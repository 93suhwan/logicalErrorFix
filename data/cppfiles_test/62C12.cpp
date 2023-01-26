#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
long long aa[N][N];
long long n, m;
long long compute() {
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      long long r = m - j;
      long long d = n - i;
      if (r == d) {
        ans += 4 * r;
      } else if (r > d) {
        ans += 2 * d + 1;
        ans += 2 * d;
      } else {
        ans += 2 * r + 1;
        ans += 2 * r;
      }
    }
  }
  ans += n * m;
  return ans;
}
void solve(long long nn) {
  long long q;
  cin >> n >> m >> q;
  long long ans = compute();
  map<long long, set<long long>> mp;
  for (long long i = 0; i < n + 2; i++) {
    for (long long j = 0; j < m + 2; j++) aa[i][j] = 1;
  }
  for (long long i = 1; i < n + 1; i++) {
    for (long long j = 1; j < m + 1; j++) aa[i][j] = 0;
  }
  for (long long i = 0; i < n + 2; i++) {
    for (long long j = 0; j < m + 2; j++) {
      if (aa[i][j]) mp[i - j].insert(i);
    }
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    if (aa[x][y]) {
      aa[x][y] = 0;
      mp[x - y].erase(x);
      auto it2 = mp[x - y].lower_bound(x);
      long long piche2 = *it2;
      it2--;
      long long aage2 = *it2;
      auto it3 = mp[x + 1 - y].lower_bound(x + 1);
      long long piche3 = *it3;
      it3--;
      long long aage3 = *it3;
      auto it1 = mp[x - 1 - y].lower_bound(x);
      long long piche1 = *it1;
      it1--;
      long long aage1 = *it1;
      long long dup = x - (aage2)-1;
      long long d3up = x - aage3;
      long long d1up = x - 1 - aage1;
      long long dd = piche2 - x - 1;
      long long d3d = piche3 - x - 1;
      long long d1d = piche1 - x;
      long long a, b;
      if (dup == d3up) {
        a = 2 * dup;
      } else {
        if (dup < d3up)
          a = 2 * min(dup, d3up) + 1;
        else
          a = 2 * min(dup, d3up);
      }
      if (dd == d3d) {
        b = 2 * dd;
      } else {
        if (dd < d3d)
          b = 2 * min(dd, d3d) + 1;
        else
          b = 2 * min(dd, d3d);
      }
      ans += a + b + a * b;
      if (dup == d1up) {
        a = 2 * dup;
      } else {
        if (dup < d1up)
          a = 2 * min(dup, d1up) + 1;
        else
          a = 2 * min(dup, d1up);
      }
      if (dd == d1d) {
        b = 2 * dd;
      } else {
        if (dd < d1d)
          b = 2 * min(dd, d1d) + 1;
        else
          b = 2 * min(dd, d1d);
      }
      ans += a + b + a * b;
      ans++;
    } else {
      auto it2 = mp[x - y].lower_bound(x);
      long long piche2 = *it2;
      it2--;
      long long aage2 = *it2;
      auto it3 = mp[x + 1 - y].lower_bound(x + 1);
      long long piche3 = *it3;
      it3--;
      long long aage3 = *it3;
      auto it1 = mp[x - 1 - y].lower_bound(x);
      long long piche1 = *it1;
      it1--;
      long long aage1 = *it1;
      long long dup = x - (aage2)-1;
      long long d3up = x - aage3;
      long long d1up = x - 1 - aage1;
      long long dd = piche2 - x - 1;
      long long d3d = piche3 - x - 1;
      long long d1d = piche1 - x;
      long long a, b;
      if (dup == d3up) {
        a = 2 * dup;
      } else {
        if (dup < d3up)
          a = 2 * min(dup, d3up) + 1;
        else
          a = 2 * min(dup, d3up);
      }
      if (dd == d3d) {
        b = 2 * dd;
      } else {
        if (dd < d3d)
          b = 2 * min(dd, d3d) + 1;
        else
          b = 2 * min(dd, d3d);
      }
      ans -= (a + b + a * b);
      if (dup == d1up) {
        a = 2 * dup;
      } else {
        if (dup < d1up)
          a = 2 * min(dup, d1up) + 1;
        else
          a = 2 * min(dup, d1up);
      }
      if (dd == d1d) {
        b = 2 * dd;
      } else {
        if (dd < d1d)
          b = 2 * min(dd, d1d) + 1;
        else
          b = 2 * min(dd, d1d);
      }
      ans -= (a + b + a * b);
      ans--;
      aa[x][y] = 1;
      mp[x - y].insert(x);
    }
    cout << ans << "\n";
  }
  return;
}
int main() {
  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  ;
  long long t;
  t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
