#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class C>
void mini(C& a, C b) {
  a = min(a, b);
}
template <class C>
void maxi(C& a, C b) {
  a = max(a, b);
}
double PI = acos(-1.0);
const ll mod = 998244353;
const ll INF = 5e18;
const double eps = 0.000000001;
const int N = 100;
ll dp[N + 1][N + 1][N + 1];
ll comb[N + 1][N + 1];
ll fact[N + 1];
ll p;
void precalc() {
  for (int i = 0; i < N + 1; i++)
    for (int j = 0; j < N + 1; j++)
      for (int l = 0; l < N + 1; l++) dp[i][j][l] = -1;
  fact[0] = 1;
  for (int(i) = 1; i <= N; i++) fact[i] = fact[i - 1] * (ll)i % p;
  for (int i = 0; i < N + 1; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int(j) = 1; j <= i - 1; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % p;
  }
}
ll f(int n, int m, int k) {
  if (n == 0) {
    if (k == 0)
      return 1;
    else
      return 0;
  }
  if (m > n and k != 0) return 0;
  if (m == 1) {
    if (k == 1)
      return fact[n];
    else
      return 0;
  }
  if (k > m) return 0;
  if (dp[n][m][k] == -1) {
    dp[n][m][k] = 0;
    for (int(i) = 1; i <= n; i++) {
      for (int k1 = 0; k1 < k + 1; k1++) {
        int k2 = k - k1;
        dp[n][m][k] += (f(i - 1, m - 1, k1) * f(n - i, m - 1, k2) % p) *
                       comb[n - 1][i - 1];
        dp[n][m][k] %= p;
      }
    }
  }
  return dp[n][m][k];
}
void a() {
  int n, m, k;
  cin >> n >> m >> k >> p;
  precalc();
  cout << f(n, m, k) << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  a();
  return 0;
}
