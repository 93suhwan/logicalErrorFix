#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long modpow(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = modpow(a, b / 2);
  ans *= ans;
  ans %= M;
  if (b % 2) ans *= a;
  ans %= M;
  return ans;
}
int inverse(int a, int mod) { return modpow(a, mod - 2); }
const int mod = 998244353;
const int root = modpow(3, 7 * 17);
const int root_1 = inverse(root, mod);
const int root_pw = 1 << 23;
void fft(vector<int>& a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)
      wlen = (int)(1LL * wlen * wlen % mod);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; j++) {
        int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = (int)(1LL * w * wlen % mod);
      }
    }
  }
  if (invert) {
    int n_1 = inverse(n, mod);
    for (int& x : a) x = (int)(1LL * x * n_1 % mod);
  }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] = (1ll * fa[i] * fb[i]) % mod;
  fft(fa, true);
  return fa;
}
vector<int> g[250001];
int children[250001];
int parent[250001];
void dfs(int u) {
  for (int x : g[u]) {
    if (parent[x]) continue;
    parent[x] = u;
    children[u]++;
    dfs(x);
  }
}
void go() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  parent[1] = -1;
  dfs(1);
  vector<vector<int>> inter;
  sort(children + 1, children + n + 1);
  for (int i = 1; i <= n; i++) {
    inter.push_back({1, children[i]});
  }
  while (inter.size() > 1) {
    vector<vector<int>> ninter;
    for (int i = 0; i < inter.size(); i += 2) {
      if (i + 1 < inter.size())
        ninter.push_back(multiply(inter[i], inter[i + 1]));
      else
        ninter.push_back(inter[i]);
    }
    inter = ninter;
  }
  vector<int> c = inter[0];
  long long ans = 0;
  vector<int> fac(n + 1);
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % M;
  for (int i = 0; i < n; i++) {
    ans += 1ll * c[i] * (i % 2 == 0 ? 1 : (M - 1)) % M * fac[n - i] % M;
    ans %= M;
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) go();
}
