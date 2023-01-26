#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, M = 2 * N, mod = 998244353;
long long inv[N], fac[N], ifac[N];
void init(int n) {
  inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    ifac[i] = ifac[i - 1] * inv[i] % mod;
  }
}
long long C(int m, int n) { return fac[m] * ifac[n] % mod * ifac[m - n] % mod; }
int pre[N], fix[N];
string s;
int pos[N];
void solve() {
  int n, k;
  cin >> n >> k >> s;
  s = " " + s;
  int last = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') pre[i] = last, last = i + 1;
  }
  last = n;
  for (int i = n; i >= 1; i--) {
    if (s[i] == '1') fix[i] = last, last = i - 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') pos[++cnt] = i;
  if (cnt < k || k == 0) {
    cout << 1 << '\n';
    return;
  }
  long long res = 0;
  for (int i = 1; i <= cnt - k + 1; i++) {
    int L = pre[pos[i]], R = fix[pos[i + k - 1]];
    int L1 = pre[pos[i + 1]], R1 = R;
    res += C(R - L + 1, k);
    if (i != cnt - k + 1) res -= C(R1 - L1 + 1, k - 1);
    res = (res + mod) % mod;
  }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cout.precision(2), cout.setf(ios::fixed);
  init(1e4 + 10);
  solve();
  return 0;
}
