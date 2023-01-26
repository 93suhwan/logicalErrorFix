#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void debug() { cerr << "\n"; }
template <typename H, typename... T>
void debug(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  debug(t...);
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 1e5 + 5, K = 18, mod = 998244353, INF = 1e9 + 5;
long long dp[K][N];
int sito[N], phi[N];
long long sum[N];
long long Cost(int l, int r) {
  long long ans = 0;
  while (r >= l * 1ll * l) {
    ans += sum[r / l];
    l++;
  }
  int k = r / l;
  for (; k >= 1; k--) {
    int m = r / k;
    ans += (m - l + 1) * sum[k];
    l = m + 1;
  }
  return ans;
}
int n;
long long cost2(int l, int r) { return Cost(n + 1 - r, n + 1 - l); }
void prop(int l, int r, int a, int b, int k) {
  int m = (l + r) / 2, skad = m;
  dp[k][m] = dp[k - 1][m];
  long long C = Cost(a, m);
  for (int i = a; i <= b && i < m; i++) {
    C -= sum[m / i];
    if (dp[k - 1][i] + C < dp[k][m]) {
      skad = i;
      dp[k][m] = dp[k - 1][i] + C;
    }
  }
  if (m > l) prop(l, m - 1, a, skad, k);
  if (m < r) prop(m + 1, r, skad, b, k);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  sum[1] = 1;
  for (int i = 2; i < N; i++) {
    if (sito[i] == 0) {
      for (int j = 1; j * i < N; j++) {
        sito[j * i] = i;
      }
    }
    phi[i] = 1;
    int k = i;
    while (k > 1) {
      int p = sito[k];
      phi[i] *= p - 1;
      k /= p;
      while (k % p == 0) {
        k /= p;
        phi[i] *= p;
      }
    }
    sum[i] = sum[i - 1] + phi[i];
  }
  for (int i = 1; i < N; i++) {
    dp[0][i] = Cost(1, i);
  }
  for (int i = 1; i < K; i++) {
    prop(1, N - 1, 1, N - 1, i);
  }
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> n >> k;
    if (k >= K || (1 << k) > n)
      cout << n << "\n";
    else {
      cout << dp[k - 1][n] << "\n";
    }
  }
}
