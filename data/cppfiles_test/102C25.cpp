#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int S, T, t, tot, p[33], rA[33], k, A, h, suck;
int dfs(int k, int l, int r) {
  if (l == r) return l;
  int mid = l + r >> 1;
  int c1 = dfs(k << 1, l, mid), c2 = dfs(k << 1, mid + 1, r);
  if (S >> (tot++) & 1) swap(c1, c2);
  return p[c1] = k + 1, c2;
}
unordered_map<int, int> mp[3];
int sc[1 << 16][16];
void work(int l, int r, int w) {
  int R = 0;
  for (int i = l; i <= r; i++)
    if (i ^ w) R = (R + 1ll * i * rA[p[i]]) % mod;
  for (int _ = 1; _ < 3; _++)
    if (!mp[_][(R + 1ll * w * rA[_]) % mod]) {
      mp[_][(R + 1ll * w * rA[_]) % mod] = ++suck, p[w] = _;
      for (int i = l; i <= r; i++) sc[suck][i - l] = p[i];
    }
}
void heck(int l, int r, int w) {
  int R = p[w] = 0;
  for (int i = l; i <= r; i++)
    if (i ^ w) R = (R + 1ll * i * rA[p[i]]) % mod;
  for (int _ = 1, ut; _ < 3; _++) {
    ut = (h + mod - (R + 1ll * w * rA[_]) % mod) % mod;
    if (mp[3 - _][ut]) {
      p[w] = _;
      for (int i = l, aws = mp[3 - _][ut]; i <= r; i++)
        cout << sc[aws][i - l] << ' ';
      for (int i = l; i <= r; i++) cout << p[i] << ' ';
      exit(0);
    }
  }
}
signed main() {
  cin >> k >> A >> h, T = 1 << k;
  rA[0] = 1;
  for (int i = 1; i <= T; i++) rA[i] = 1ll * rA[i - 1] * A % mod;
  T >>= 1;
  for (S = 0, t = 1 << T; S < t; S++) tot = 0, work(1, T, dfs(2, 1, T));
  for (S = 0, t = 1 << T; S < t; S++)
    tot = 0, heck(T + 1, T + T, dfs(2, T + 1, T + T));
  cout << -1 << '\n';
  return 0;
}
