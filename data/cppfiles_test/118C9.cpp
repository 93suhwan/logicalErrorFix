#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vec = vector<int>;
const int maxn = 250005;
const int mod = 998244353;
const int inv2 = 499122177;
const int G = 3;
inline int add(int x, int y) { return (x + y >= mod) ? x + y - mod : x + y; }
inline int sub(int x, int y) { return (x - y < 0) ? x - y + mod : x - y; }
inline int mul(int x, int y) { return (ll)x * y % mod; }
inline int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}
namespace NTT {
int w[maxn * 8], pos[maxn * 8], k;
inline void dft(vec &a) {
  for (int i = 1; i < k; i++)
    if (pos[i] > i) swap(a[pos[i]], a[i]);
  for (int bl = 1; bl < k; bl <<= 1) {
    int tl = bl << 1, wn = power(3, (mod - 1) / tl);
    w[0] = 1;
    for (int i = 1; i < bl; i++) w[i] = mul(w[i - 1], wn);
    for (int bg = 0; bg < k; bg += tl)
      for (int j = 0; j < bl; j++) {
        int &t1 = a[bg + j], &t2 = a[bg + j + bl], t = mul(t2, w[j]);
        t2 = sub(t1, t);
        t1 = add(t1, t);
      }
  }
}
inline void func(vec &A, vec &B) {
  int nn = (int)(A.size()) + (int)(B.size()) - 2;
  k = 1;
  while (k <= nn) k <<= 1;
  for (int i = 1; i < k; i++)
    pos[i] = (i & 1) ? ((pos[i >> 1] >> 1) ^ (k >> 1)) : (pos[i >> 1] >> 1);
  A.resize(k);
  B.resize(k);
  dft(A);
  dft(B);
  for (int i = 0; i < k; i++) A[i] = mul(A[i], B[i]);
  dft(A);
  reverse(A.begin() + 1, A.begin() + k);
  int inv = power(k, mod - 2);
  for (int i = 0; i < k; i++) A[i] = mul(A[i], inv);
  A.resize(nn + 1);
}
}  // namespace NTT
void solve(vector<vec> &p, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  solve(p, l, mid);
  solve(p, mid + 1, r);
  NTT::func(p[l], p[mid + 1]);
}
int n;
vec g[maxn];
int cnt[maxn];
void dfs(int u, int pre) {
  for (int v : g[u]) {
    if (v == pre) continue;
    dfs(v, u);
    cnt[u]++;
  }
}
int jc[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  jc[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = 1LL * jc[i - 1] * i % mod;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  vector<vec> p(n);
  for (int i = 0; i < n; i++) p[i] = {1, cnt[i + 1]};
  solve(p, 0, n - 1);
  auto res = move(p[0]);
  res.resize(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += ((i & 1) ? -1LL : 1LL) * res[i] * jc[n - i] % mod;
  }
  cout << ((ans % mod) + mod) % mod << "\n";
  return 0;
}
