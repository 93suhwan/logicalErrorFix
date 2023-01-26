#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long inf = 0x3f3f3f3f;
const long long INF = 1e18;
long long fpow(long long x, long long y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
long long fac[300005];
long long C(long long x, long long y) {
  return fac[y] * fpow(fac[y - x], mod - 2) % mod * fpow(fac[x], mod - 2) % mod;
}
long long f1[100005], f2[100005];
long long find1(long long x) {
  if (f1[x] == x) return x;
  return f1[x] = find1(f1[x]);
}
long long find2(long long x) {
  if (f2[x] == x) return x;
  return f2[x] = find2(f2[x]);
}
void merge1(long long x, long long y) {
  long long xx = find1(x), yy = find1(y);
  if (xx != yy) f1[xx] = yy;
}
void merge2(long long x, long long y) {
  long long xx = find2(x), yy = find2(y);
  if (xx != yy) f2[xx] = yy;
}
void solve() {
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  for (long long i = 1; i <= n; i++) f1[i] = f2[i] = i;
  while (m1--) {
    long long u, v;
    cin >> u >> v;
    merge1(u, v);
  }
  while (m2--) {
    long long u, v;
    cin >> u >> v;
    merge2(u, v);
  }
  vector<long long> vec;
  vector<long long> v1, v2;
  long long ans = 0;
  for (long long j = 1; j <= n; j++)
    if (find1(1) != find1(j) && find2(1) != find2(j))
      merge1(1, j), merge2(1, j), v1.push_back(1), v2.push_back(j),
          vec.push_back(j);
  long long idx = 0;
  for (long long i = 1; i <= n; i++) {
    if (idx < vec.size() && i == vec[idx]) {
      idx++;
      continue;
    }
    if (find1(1) != find1(i)) merge1(1, i), v1.push_back(i);
    if (find2(1) != find2(i)) merge2(1, i), v2.push_back(i);
  }
  cout << min(v1.size(), v2.size()) << endl;
  for (long long i = 0; i < min(v1.size(), v2.size()); i++)
    cout << v1[i] << " " << v2[i] << endl;
}
signed main() {
  long long _ = 1;
  while (_--) solve();
  return 0;
}
