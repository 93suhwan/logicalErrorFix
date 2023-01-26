#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, MOD;
namespace combination {
const int MAXN = 200000;
int fact[MAXN + 1], ifact[MAXN + 1];
int quick(int k1, int k2) {
  int k3 = 1;
  for (; k2; k2 >>= 1, k1 = 1LL * k1 * k1 % MOD)
    if (k2 & 1) k3 = 1LL * k3 * k1 % MOD;
  return k3;
}
int inv(int A) { return quick(A, MOD - 2); }
void genmath() {
  fact[0] = 1;
  for (int i = 1; i <= MAXN; ++i) fact[i] = 1ll * fact[i - 1] * i % MOD;
  ifact[MAXN] = inv(fact[MAXN]);
  for (int i = MAXN - 1; i >= 0; --i)
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % MOD;
}
int comb(int A, int B) {
  if (A < B) return 0;
  return 1ll * fact[A] * ifact[B] % MOD * ifact[A - B] % MOD;
}
void add(int &A, int B) {
  A += B;
  if (A >= MOD) A -= MOD;
}
void sub(int &A, int B) {
  A += MOD - B;
  if (A >= MOD) A -= MOD;
}
}  // namespace combination
using namespace combination;
unordered_map<int, int> dp[202];
int main() {
  cin >> n >> MOD;
  genmath();
  int ans = 0;
  for (int f = 1; f <= n + 1; ++f) {
    for (int i = 1; i <= n; ++i) dp[i].clear();
    for (int i = f * n; i <= f + (n - 1) * (n + 1); ++i) {
      for (int j = max(f, (i + f - 1) / f); j <= n + 1; ++j) {
        dp[n][i * 202 + j] = 1;
      }
    }
    for (int i = n; i >= 2; --i) {
      for (auto ite = dp[i].begin(); ite != dp[i].end(); ite++) {
        int j, k;
        j = ite->first / 202;
        k = ite->first % 202;
        int val = ite->second;
        for (int prej = i - 1; prej >= 1; --prej) {
          int s = j - (i - prej) * k;
          if (s < 0) break;
          if (s >= f * prej)
            for (int preval = max(f, (s + f - 1) / f); preval <= k - 1;
                 ++preval) {
              if (s >= f * (prej - 1) + preval) {
                add(dp[prej][s * 202 + preval],
                    1ll * val * ifact[i - prej] % MOD);
              }
            }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      add(ans, 1ll * dp[i][i * f * 202 + f] * ifact[i] % MOD * fact[n] % MOD);
    }
  }
  cout << ans << endl;
  return 0;
}
