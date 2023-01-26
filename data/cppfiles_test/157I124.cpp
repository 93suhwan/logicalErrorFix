#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
const int mod = 998244353;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
long long f[N];
long long fp(long long b, long long p) {
  if (p == 0) return 1;
  return fp(b * b % mod, p / 2) * (p & 1 ? b : 1) % mod;
}
long long inv(long long x) { return fp(x, mod - 2); }
long long nCk(long long n, long long k) {
  return f[n] * inv(f[n - k]) % mod * inv(f[k]) % mod;
}
void Ineedhelp() {
  f[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = f[i - 1] * i % mod;
  }
  int n, k;
  string s;
  cin >> n >> k >> s;
  int i = 0, j = -1, cnt1 = 0, last1 = -1;
  while (j < n - 1 && cnt1 + (s[j + 1] == '1') <= k) {
    ++j;
    cnt1 += s[j] == '1';
    if (s[j] == '1') last1 = j;
  }
  if (cnt1 < k || k == 0) {
    cout << "1\n";
    return;
  }
  long long ways = nCk(j - i + 1, k);
  while (j < n - 1) {
    ways = ways - nCk(j - i, k - 1) + mod;
    ways %= mod;
    ++j;
    while (j < n - 1 && s[j + 1] == '0') ++j;
    while (i < j && s[i] == '0') ++i;
    ++i;
    ways += nCk(j - i + 1, k);
    ways %= mod;
  }
  cout << ways << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) Ineedhelp();
}
