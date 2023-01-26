#include <bits/stdc++.h>
using namespace std;
void assume(int expr) {
  if (!expr) __builtin_unreachable();
}
constexpr int N = 1e5 + 10;
constexpr long long MOD = 998244353;
constexpr long long pw(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * pw(a * a % MOD, b / 2) % MOD;
  return pw(a * a % MOD, b / 2) % MOD;
}
long long fact[N], inv[N];
long long C(long long n, long long r) {
  if (r < 0 || n < r) return 0;
  return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}
int n, c[N][2], s[3], t[3];
long long total() {
  long long ans = 0;
  for (int b = 0; b <= n; b++) {
    if (t[1] > b || t[1] + t[2] < b) continue;
    if (s[0] > b || s[0] + s[2] < b) continue;
    ans += C(t[2], b - t[1]) * C(s[2], b - s[0]) % MOD;
    ans %= MOD;
  }
  return ans;
}
long long bad() {
  long long ans = 0;
  int p[3] = {0, 0, 0};
  for (int i = 0; i < n; i++) {
    if (c[i][0] < 2 && c[i][0] == c[i][1]) return 0;
    if (c[i][0] == c[i][1])
      p[2]++;
    else if (c[i][0] == 0)
      p[0]++;
    else
      p[1]++;
  }
  for (int b = 1; b < n; b++) {
    if (p[0] > b || p[0] + p[2] < b) continue;
    ans += C(p[2], b - p[0]);
    ans %= MOD;
  }
  return ans;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  fact[0] = inv[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = i * fact[i - 1] % MOD;
    inv[i] = pw(fact[i], MOD - 2);
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    string ss;
    cin >> ss;
    for (int j : {0, 1}) {
      if (ss[j] == 'B')
        c[i][j] = 1;
      else if (ss[j] == 'W')
        c[i][j] = 0;
      else
        c[i][j] = 2;
    }
    s[c[i][0]]++;
    t[c[i][1]]++;
  }
  long long tot = total(), b = bad();
  cout << (tot + MOD - b) % MOD << endl;
  return 0;
}
