#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 2e3 + 5;
const long long mod = 998244353;
const long double ex = 1e-7;
long long m, n, k, a[N], ans, tong, idx, mn, c[N], d[N], t, b[N], lab[N], id[N],
    ok[N], pos[M][M], l[M], r[M];
vector<pair<long long, long long> > adj[N];
vector<pair<long long, long long> > kq;
long long pw(long long k, long long n) {
  long long total = 1;
  for (; n; n >>= 1) {
    if (n & 1) total = total * k % mod;
    k = k * k % mod;
  }
  return total;
}
void add(long long id, long long x, long long fe[]) {
  for (; id <= m; id += id & -id) fe[id] = min(fe[id], x);
}
long long lwr(long long x, vector<long long> kq) {
  long long i = lower_bound(kq.begin(), kq.end(), x) - kq.begin();
  if (i == kq.size() || kq[i] != x) return -1;
  return i;
}
long long C(long long u, long long v) {
  if (u > v) return 0;
  return a[v] * b[u] % mod * b[v - u] % mod;
}
void fixv(vector<pair<long long, long long> >& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
long long findp(long long u) { return lab[u] < 0 ? u : lab[u] = findp(lab[u]); }
bool cmp(const long long& x, const long long& y) { return a[x] < a[y]; }
void sol() {
  cin >> n >> k;
  m = (n + k - 2) / (k - 1);
  for (int i = 1; i <= n * k; i++) {
    cin >> a[i];
    ++b[a[i]];
    pos[a[i]][b[a[i]]] = i;
    adj[b[a[i]]].push_back({i, a[i]});
  }
  for (int i = 1; i <= n; i++) id[i] = i;
  for (int i = 2; i <= k; i++) {
    sort(adj[i].begin(), adj[i].end());
    long long cnt = 0;
    for (pair<long long, long long> x : adj[i]) {
      if (d[x.second]) continue;
      d[x.second] = 1;
      r[x.second] = x.first;
      l[x.second] = pos[x.second][i - 1];
      ++cnt;
      if (cnt == m) break;
    }
  }
  for (int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << '\n';
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  srand((int)time(0));
  int ntest = 1;
  while (ntest-- > 0) sol();
  return 0;
}
