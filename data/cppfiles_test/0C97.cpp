#include <bits/stdc++.h>
using namespace std;
long long modpow(long long x, long long y) {
  long long xs = x;
  long long answer = 1;
  while (y) {
    if (y & 1) {
      answer = (answer * xs) % 1000000007;
    }
    y >>= 1;
    xs = (xs * xs) % 1000000007;
  }
  return answer;
}
long long dp[2][4];
vector<int> qids[3333333];
long long ans[333333];
long long inv[3333333];
int main() {
  int n, Q;
  cin >> n >> Q;
  for (int k = 1; k <= 3; k++) {
    if (k <= 2) {
      dp[0][k] = n;
    } else {
      dp[0][k] = n + 1;
    }
  }
  for (int q = 1; q <= Q; q++) {
    int x;
    scanf("%d", &x);
    qids[x].push_back(q);
  }
  long long threeinv = modpow(3, 1000000007 - 2);
  long long numer, denom;
  numer = denom = 1;
  for (int i = 2; i <= 3 * n + 1; i++) {
    numer *= i;
    numer %= 1000000007;
    denom *= i - 1;
    denom %= 1000000007;
  }
  for (int x = 1; x <= 7; x++) {
    inv[x] = modpow(x, 1000000007 - 2);
  }
  for (int x = 8; x <= 3 * n + 1; x++) {
    inv[x] = -1;
    for (int p : {2, 3, 5, 7}) {
      if (x % p == 0) {
        inv[x] = (inv[p] * inv[x / p]) % 1000000007;
        break;
      }
    }
    if (inv[x] == -1) {
      inv[x] = modpow(x, 1000000007 - 2);
    }
  }
  long long B = numer * modpow(denom, 1000000007 - 2) % 1000000007;
  for (int x = 1; x <= 3 * n; x++) {
    B = (B * (3 * n - x + 1)) % 1000000007;
    B *= inv[x + 1];
    B %= 1000000007;
    dp[x & 1][2] = dp[(x - 1) & 1][1] - dp[(x - 1) & 1][2] + B;
    dp[x & 1][2] %= 1000000007;
    dp[x & 1][2] *= threeinv;
    dp[x & 1][2] %= 1000000007;
    dp[x & 1][1] = dp[x & 1][2] - dp[(x - 1) & 1][1];
    dp[x & 1][3] = dp[x & 1][2] + dp[(x - 1) & 1][2];
    for (int i = 1; i <= 3; i++) {
      dp[x & 1][i] %= 1000000007;
      if (dp[x & 1][i] < 0) dp[x & 1][i] += 1000000007;
    }
    for (int q : qids[x]) {
      ans[q] = dp[x & 1][3];
    }
  }
  for (int q = 1; q <= Q; q++) {
    printf("%lld\n", ans[q]);
  }
}
