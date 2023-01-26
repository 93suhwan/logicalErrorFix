#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long nax = 2e6;
long long sub(long long x, long long y) {
  x -= y;
  x %= mod;
  x += mod;
  x %= mod;
  return x;
}
void add_self(long long &x, long long y) { x = (x + y) % mod; }
long long mul(long long a, long long b) {
  a *= b;
  return (a % mod);
}
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = mul(ans, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return ans;
}
vector<long long> fac(nax, 1);
vector<vector<long long>> memo(506, vector<long long>(506, -1));
long long dp(long long sz, long long mx) {
  if (memo[sz][mx] != -1) {
    return memo[sz][mx];
  }
  if (sz == 1) {
    return memo[sz][mx] = 1;
  }
  long long &ans = memo[sz][mx];
  ans = 0;
  for (long long i = 0; i < sz; ++i) {
    if (mx - sz + 1 < 1) {
      continue;
    }
    add_self(ans, mul(pow(sz - 1, i), dp(sz - i, mx - sz + 1)));
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (long long i = 1; i < nax; ++i) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  long long N, K;
  cin >> N >> K;
  long long answer = 0;
  for (long long i = N; i <= K; ++i) {
    add_self(answer, dp(N, i));
  }
  long long total = pow(K, N);
  answer = mul(answer, N);
  cout << sub(total, answer) << '\n';
  return 0;
}
