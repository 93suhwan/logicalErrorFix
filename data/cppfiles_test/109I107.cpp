#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<long long, long long>;
using pll = pair<ll, ll>;
mt19937 rng((long long)chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 998244353;
const long long MAXN = 2e5 + 5;
const ll INF = 2e18;
long long fexp(ll b, long long e) {
  ll resp = 1;
  while (e) {
    if (e & 1) resp = (resp * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return resp;
}
long long fat[MAXN], inv[MAXN];
ll nck(long long n, long long k) {
  return (((1ll * fat[n] * inv[k]) % MOD) * 1ll * inv[n - k]) % MOD;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fat[0] = 1;
  for (long long i = 1; i < MAXN; i++) {
    fat[i] = (1ll * fat[i - 1] * i) % MOD;
  }
  inv[MAXN - 1] = fexp(fat[MAXN - 1], MOD - 2);
  for (long long i = MAXN - 2; i >= 0; i--) {
    inv[i] = (1ll * (i + 1) * inv[i + 1]) % MOD;
  }
  long long n;
  cin >> n;
  long long b = 0, w = 0, cnt = 1;
  bool wb = true, bw = true;
  string s;
  for (long long i = 0; i < n; i++) {
    cin >> s;
    wb &= (s != "WW" && s != "BB" && s != "B?" && s != "?W");
    bw &= (s != "WW" && s != "BB" && s != "?B" && s != "W?");
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
