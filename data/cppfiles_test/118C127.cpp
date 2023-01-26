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
const int MAXN = 250005;
int n, cnt[MAXN];
vector<int> adj[MAXN];
void dfs(int now, int prv) {
  for (int u : adj[now]) {
    if (u != prv) {
      dfs(u, now);
      cnt[now]++;
    }
  }
}
long long ft[MAXN];
void init() {
  ft[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    ft[i] = ft[i - 1] * i % mod;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 1);
  vector<vector<long long> > pols;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 0) {
      vector<long long> f(2);
      f[0] = 1;
      f[1] = cnt[i];
      pols.push_back(f);
    }
  }
  while (pols.size() > 1) {
    vector<vector<long long> > nxt;
    for (int i = 1; i < (int)pols.size(); i += 2) {
      nxt.push_back(conv(pols[i], pols[i - 1]));
    }
    if (pols.size() % 2) {
      nxt.push_back(pols.back());
    }
    swap(pols, nxt);
  }
  vector<long long> f = pols[0];
  long long ans = 0;
  for (int i = n, j = 0; j < (int)f.size(); i--, j++) {
    long long tmp = ft[i] * f[j] % mod;
    if (j % 2) {
      ans = (ans - tmp) % mod;
    } else {
      ans = (ans + tmp) % mod;
    }
  }
  if (ans < 0) ans += mod;
  cout << ans << '\n';
  return 0;
}
