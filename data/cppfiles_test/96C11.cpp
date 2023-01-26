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
long long int memo(long long int n, long long int h, long long int t) {
  if (n == 0) return 1;
  if (n == 1 || h > t) return 0;
  if (dp[n][h] != -1) return dp[n][h];
  dp[n][h] = 0;
  long long int expo = 1;
  long long int nh = min(t, h + (n - 1));
  long long int damage = nh - h;
  for (long long int k = n; k >= 0; k--) {
    dp[n][h] =
        (dp[n][h] +
         ((ncr[n][n - k] * memo(k, nh, t) % 998244353 * expo) % 998244353)) %
        998244353;
    expo = (expo * damage) % 998244353;
  }
  return dp[n][h];
}
void solve() {
  long long int n, x;
  cin >> n >> x;
  precompute_binomial();
  memset(dp, -1, sizeof(dp));
  cout << memo(n, 0, x);
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
