#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const int DIM = 14;
const int MOD = 1e9 + 7;
int arr[DIM], coef[DIM][DIM], dp[1 << DIM], aux[1 << DIM][DIM], lsb[1 << DIM];
int log_pow(int x, int n) {
  int y = 1;
  for (; n; n >>= 1) {
    if (n & 1) y = 1LL * y * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return y;
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int lgp = log_pow(arr[i] + arr[j], MOD - 2);
      coef[i][j] = 1LL * arr[i] * lgp % MOD;
      coef[j][i] = 1LL * arr[j] * lgp % MOD;
    }
  }
  for (int msk = 2; msk < (1 << n); msk += 2) lsb[msk] = lsb[msk >> 1] + 1;
  for (int msk = 0; msk < (1 << n); ++msk) {
    for (int msk2 = (((1 << n) - 1) ^ msk); msk2; msk2 ^= (1 << lsb[msk2])) {
      int x = lsb[msk2];
      aux[msk][x] = 1;
      for (int msk3 = msk; msk3; msk3 ^= (1 << lsb[msk3])) {
        int y = lsb[msk3];
        aux[msk][x] = 1LL * aux[msk][x] * coef[x][y] % MOD;
      }
    }
  }
  int ans = 0;
  for (int msk = 1; msk < (1 << n); ++msk) {
    int nr = 0, ex = 1;
    for (int msk2 = msk; msk2; msk2 ^= (1 << lsb[msk2])) {
      ++nr;
      int x = lsb[msk2];
      ex = 1LL * ex * aux[((1 << n) - 1) ^ msk][x] % MOD;
    }
    int sum = 0;
    for (int msk2 = ((msk - 1) & msk); msk2; msk2 = ((msk2 - 1) & msk)) {
      int in = 1;
      for (int msk3 = msk2; msk3; msk3 ^= (1 << lsb[msk3])) {
        int x = lsb[msk3];
        in = 1LL * in * aux[msk ^ msk2][x] % MOD;
      }
      sum = (1LL * dp[msk2] * in % MOD + sum) % MOD;
    }
    dp[msk] = (1 - sum + MOD) % MOD;
    ans = (1LL * nr * dp[msk] % MOD * ex % MOD + ans) % MOD;
  }
  cout << ans << endl;
  return 0;
}
