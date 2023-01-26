#include <bits/stdc++.h>
using namespace std;
const long long mod = (119 << 23) + 1, root = 62;
long long modpow(long long b, long long e) {
  long long ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1) ans = ans * b % mod;
  return ans;
}
void ntt(vector<long long> &a) {
  int n = (int)(a).size(), L = 31 - __builtin_clz(n);
  static vector<long long> rt(2, 1);
  for (static int k = 2, s = 2; k < n; k *= 2, s++) {
    rt.resize(n);
    long long z[] = {1, modpow(root, mod >> s)};
    for (int i = k; i < (2 * k); ++i) rt[i] = rt[i / 2] * z[i & 1] % mod;
  }
  vector<int> rev(n);
  for (int i = 0; i < (n); ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < (n); ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      for (int j = 0; j < (k); ++j) {
        long long z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? mod : 0);
        ai += (ai + z >= mod ? z - mod : z);
      }
}
vector<long long> conv(const vector<long long> &a, const vector<long long> &b) {
  if (a.empty() || b.empty()) return {};
  int s = (int)(a).size() + (int)(b).size() - 1, B = 32 - __builtin_clz(s),
      n = 1 << B;
  int inv = modpow(n, mod - 2);
  vector<long long> L(a), R(b), out(n);
  L.resize(n), R.resize(n);
  ntt(L), ntt(R);
  for (int i = 0; i < (n); ++i)
    out[-i & (n - 1)] = (long long)L[i] * R[i] % mod * inv % mod;
  ntt(out);
  return {out.begin(), out.begin() + s};
}
const int MAXN = 250000;
vector<int> adjList[MAXN + 1];
int children[MAXN + 1];
int fac[MAXN + 1];
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void dfs(int v, int p) {
  for (int adj : adjList[v]) {
    if (adj == p) continue;
    dfs(adj, v);
    children[v]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    fac[i] = (int)((long long)fac[i - 1] * i % mod);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  dfs(1, 1);
  deque<vector<long long> > poly;
  for (int i = 1; i <= n; i++) {
    if (children[i]) poly.push_back({1, children[i]});
  }
  while (poly.size() >= 2) {
    vector<long long> first = poly.front();
    poly.pop_front();
    vector<long long> second = poly.front();
    poly.pop_front();
    poly.push_back(conv(first, second));
  }
  int ans = 0;
  for (int i = 0; i < (int)poly[0].size(); i++) {
    if (i > n) break;
    int ways = (int)((long long)poly[0][i] * fac[n - i] % mod);
    if (i & 1)
      add(ans, mod - ways);
    else
      add(ans, ways);
  }
  cout << ans << "\n";
  return 0;
}
