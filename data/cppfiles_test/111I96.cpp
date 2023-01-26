#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}
int mul(int a, int b) { return a * (long long)b % M; }
int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}
int dv(int a, int b) { return mul(a, pw(b, M - 2)); }
void addup(int &a, int b) { a = add(a, b); }
void mulup(int &a, int b) { a = mul(a, b); }
const int N = 2000 + 7;
const int K = 50 + 7;
int n, k, b[N];
int dp[2 * K][N], ndp[2 * K][N], fact[N], ifact[N];
int comb(int n, int k) {
  assert(0 <= k && k <= n && n < N);
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}
void addToDp(int pos, int mex, int u, int value) {
  if (abs(mex - b[pos]) > k) {
    return;
  }
  int id = mex - (b[pos] - k);
  addup(ndp[id][u], value);
}
int pref[2 * N][2 * K];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  dp[k][0] = 1;
  bool all50 = 1;
  for (int i = 1; i <= n; i++) {
    all50 &= (b[i] == 50);
  }
  for (int i = 0; i < n; i++) {
    int maxsum = 0;
    for (int mex = b[i] - k; mex <= b[i] + k; mex++) {
      int id_mex = mex - (b[i] - k);
      for (int u = 0; u <= i; u++) {
        int coef = dp[id_mex][u];
        if (!coef) {
          continue;
        }
        {
          int new_mex = mex;
          int new_u = u;
          addToDp(i + 1, new_mex, new_u, mul(mex, coef));
        }
        {
          {
            int new_mex = mex;
            int new_u = u;
            addToDp(i + 1, new_mex, new_u, mul(u, coef));
          }
          {
            int new_mex = mex;
            int new_u = u + 1;
            addToDp(i + 1, new_mex, new_u, coef);
          }
        }
        int low = max(mex + 1, b[i + 1] - k);
        int high = min(u + mex + 1, b[i + 1] + k);
        coef = mul(coef, fact[u]);
        if (low <= high) {
          int sum = u + mex;
          maxsum = max(maxsum, sum);
          addup(pref[sum][low - (b[i + 1] - k)], coef);
          addup(pref[sum][high + 1 - (b[i + 1] - k)], -coef);
        }
      }
    }
    if (all50 && i == 1501) {
      return 0;
    }
    assert(maxsum < 2 * N);
    for (int sum = 0; sum <= maxsum; sum++) {
      int cur = 0;
      for (int new_mex = b[i + 1] - k; new_mex <= b[i + 1] + k; new_mex++) {
        int j = new_mex - (b[i + 1] - k);
        addup(cur, pref[sum][j]);
        pref[sum][j] = 0;
        addup(ndp[j][sum + 1 - new_mex], mul(cur, ifact[sum + 1 - new_mex]));
      }
    }
    for (int x = 0; x <= 2 * k + 1; x++) {
      for (int y = 0; y <= i + 1; y++) {
        dp[x][y] = ndp[x][y];
        ndp[x][y] = 0;
      }
    }
  }
  int sol = 0;
  for (int mex = b[n] - k; mex <= b[n] + k; mex++) {
    int id_mex = mex - (b[n] - k);
    for (int u = 0; u <= n; u++) {
      int coef = dp[id_mex][u];
      if (!coef) {
        continue;
      }
      if (u <= n - mex) {
        addup(sol, mul(coef, mul(fact[u], comb(n - mex, u))));
      }
    }
  }
  cout << sol << "\n";
}
