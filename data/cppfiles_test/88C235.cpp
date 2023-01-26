#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int mod = 1e9 + 7;
const int base = 300;
long long m, n, t, k, a[N * N], ans, b[N * N], tong, d[N * N], c[N * N],
    st[N * 4], lazy[N * 4], fe[N][N], l[N * N], r[N * N];
vector<long long> val[N], adj[N], kq;
string s;
long long pw(long long k, long long n) {
  long long total = 1;
  for (; n; n >>= 1) {
    if (n & 1) total = total * k % mod;
    k = k * k % mod;
  }
  return total;
}
void add(long long id, long long fe[]) {
  for (; id <= m * 2; id += id & -id) ++fe[id];
}
long long get(long long id, long long fe[]) {
  long long total = 0;
  for (; id; id -= id & -id) total += fe[id];
  return total;
}
long long lwr(long long x, vector<long long>& kq) {
  return lower_bound(kq.begin(), kq.end(), x) - kq.begin() + 1;
}
void sol() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i <= m * n; i++) {
    cin >> a[i];
    kq.push_back(a[i]);
  }
  sort(kq.begin(), kq.end());
  kq.erase(unique(kq.begin(), kq.end()), kq.end());
  fill_n(b, n * m + 1, 0);
  fill_n(c, n * m + 1, 0);
  fill_n(d, n * m + 1, 0);
  for (int i = 1; i <= n * m; i++) {
    a[i] = lwr(a[i], kq);
    ++b[a[i]];
  }
  for (int i = 1; i <= m * n; i++) c[i] = c[i - 1] + b[i];
  for (int i = 1; i <= n; i++) fill_n(fe[i], 2 * m + 2, 0);
  kq.clear();
  ans = 0;
  for (int i = 1; i <= n * m; i++) {
    if (!b[i]) break;
    k = c[i - 1];
    l[i] = k / m + 1;
    r[i] = (k % m + 1);
    for (int j = l[i]; j <= c[i] / m + 1; j++) adj[j].push_back(i);
  }
  for (int i = 1; i <= n * m; i++) {
    ans += get(lwr(a[i], adj[l[a[i]]]) - 1, fe[l[a[i]]]);
    add(lwr(a[i], adj[l[a[i]]]), fe[l[a[i]]]);
    ++r[a[i]];
    if (r[a[i]] > m) {
      r[a[i]] = 1;
      ++l[a[i]];
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int ntest = 1;
  cin >> ntest;
  while (ntest-- > 0) sol();
}
