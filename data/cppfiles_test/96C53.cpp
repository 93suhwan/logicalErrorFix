#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
bool mycomp(T x, T y) {
  return (x == y);
}
bool paircomp(const pair<long long int, long long int> &x,
              const pair<long long int, long long int> &y) {
  return x.second < y.second;
}
long long int dp[505][505];
long long int ncr[505][505];
long long int d, x, y;
void extendedEuclid(long long int A, long long int B) {
  if (B == 0) {
    d = A;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(B, A % B);
    long long int temp = x;
    x = y;
    y = temp - (A / B) * y;
  }
}
long long int modInverse(long long int A, long long int M) {
  extendedEuclid(A, M);
  return (x % M + M) % M;
}
long long int binomialCoeff(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (long long int i = 0; i < k; i++) {
    long long int num = (n - i);
    long long int den = modInverse(i + 1, 998244353);
    res = (res * num) % 998244353;
    res = (res * den) % 998244353;
  }
  return res % 998244353;
}
void precompute_binomial() {
  for (long long int i = 0; i < 501; i++) {
    for (long long int j = 0; j < 501; j++) ncr[i][j] = binomialCoeff(i, j);
  }
  return;
}
void solve() {
  long long int n, x;
  cin >> n >> x;
  dp[n][0] = 1;
  long long int ans = 0ll;
  precompute_binomial();
  for (long long int i = n; i >= 2; i--) {
    for (long long int j = 0; j <= x; j++) {
      if (!dp[i][j]) continue;
      long long int nh = min(x, j + i - 1);
      long long int damage = nh - j;
      long long int expo = 1;
      for (long long int k = i; k >= 0; k--) {
        long long int killed = ncr[i][i - k];
        killed = (killed * expo) % 998244353;
        dp[k][nh] += (dp[i][j] * killed) % 998244353;
        dp[k][nh] %= 998244353;
        expo = (expo * damage) % 998244353;
      }
    }
  }
  for (long long int i = 0; i < x + 1; i++) ans += dp[0][i];
  cout << ans % 998244353;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
}
