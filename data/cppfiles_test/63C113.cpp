#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long res = 0, flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    res = (res << 3) + (res << 1) + (ch ^ 48);
    ch = getchar();
  }
  return res * flag;
}
const long long maxn = 1e6 + 5;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-8;
long long n, fa1[maxn], fa2[maxn], m1, m2;
long long find(long long x, long long fa[]) {
  return fa[x] == x ? x : fa[x] = find(fa[x], fa);
}
vector<pair<long long, long long>> v;
signed main() {
  long long t = 1;
  while (t--) {
    n = read(), m1 = read(), m2 = read();
    for (long long i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
    for (long long i = 1; i <= m1; i++) {
      long long u = read(), v = read();
      long long fax = find(u, fa1), fay = find(v, fa1);
      if (fax != fay) {
        fa1[fax] = fay;
      }
    }
    for (long long i = 1; i <= m2; i++) {
      long long u = read(), v = read();
      long long fax = find(u, fa2), fay = find(v, fa2);
      if (fax != fay) {
        fa2[fax] = fay;
      }
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = i + 1; j <= n; j++) {
        long long fax = find(i, fa1), fay = find(j, fa1);
        long long faxx = find(i, fa2), fayy = find(j, fa2);
        if (fax != fay && faxx != fayy) {
          ans++;
          fa1[fax] = fay;
          fa2[faxx] = fayy;
          v.push_back({i, j});
        }
      }
    }
    cout << ans << '\n';
    for (auto p : v) cout << p.first << " " << p.second << '\n';
  }
  return 0;
}
