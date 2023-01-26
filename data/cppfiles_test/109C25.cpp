#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 998244353;
const int MAXN = 4e5 + 5;
const ll INF = 2e18;
int fexp(ll b, int e) {
  ll resp = 1;
  while (e) {
    if (e & 1) resp = (resp * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return resp;
}
int fat[MAXN], inv[MAXN];
ll nck(int n, int k) {
  return (((1ll * fat[n] * inv[k]) % MOD) * 1ll * inv[n - k]) % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fat[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fat[i] = (1ll * fat[i - 1] * i) % MOD;
  }
  inv[MAXN - 1] = fexp(fat[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 0; i--) {
    inv[i] = (1ll * (i + 1ll) * inv[i + 1]) % MOD;
  }
  int n;
  cin >> n;
  int b = 0, w = 0, cnt = 1;
  bool wb = true, bw = true;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    wb &= (s != "WW" && s != "BB" && s != "B?" && s != "?W" && s != "BW");
    bw &= (s != "WW" && s != "BB" && s != "?B" && s != "W?" && s != "WB");
    if (s == "WW" || s == "BB") cnt = 0;
    if (s == "??") cnt = (2ll * cnt) % MOD;
    if (s[0] == 'B') b++;
    if (s[0] == 'W') w++;
    if (s[1] == 'B') b++;
    if (s[1] == 'W') w++;
  }
  if (b > n || w > n)
    cout << "0\n";
  else {
    cout << (nck(2 * n - b - w, n - b) - cnt + bw + wb + MOD) % MOD << '\n';
  }
  return 0;
}
