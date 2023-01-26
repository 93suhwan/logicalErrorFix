#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100;
int N, M, K, P;
int memo[NMAX + 2][NMAX + 2][NMAX + 2];
int fact[NMAX + 2], inv_fact[NMAX + 2];
int lg_put(int base, int exp) {
  int ans = 1, aux = base;
  for (long long i = 1LL; i <= exp; i <<= 1) {
    if (i & exp) {
      ans = 1LL * ans * aux % P;
    }
    aux = 1LL * aux * aux % P;
  }
  return ans;
}
int comb(int k, int n) {
  int res = fact[n];
  res = 1LL * res * inv_fact[k] % P;
  res = 1LL * res * inv_fact[n - k] % P;
  return res;
}
int ways(int len, int levels_deep, int count) {
  if (memo[len][levels_deep][count] != -1) {
    return memo[len][levels_deep][count];
  }
  if (len == 0) {
    if (count == 0) {
      return memo[len][levels_deep][count] = 1;
    } else {
      return memo[len][levels_deep][count] = 0;
    }
  }
  if (levels_deep == 1) {
    if (count == 0 || count >= 2) {
      return memo[len][levels_deep][count] = 0;
    }
    return memo[len][levels_deep][count] = (1LL * len * fact[len - 1]) % P;
  }
  int res = 0;
  res = (res + ways(len - 1, levels_deep - 1, count)) % P;
  for (int pos_me = 2; pos_me < len; pos_me++) {
    for (int c1 = 0; c1 <= count; c1++) {
      res = (res + 1LL * comb(pos_me - 1, len - 1) *
                       ways(pos_me - 1, levels_deep - 1, c1) % P *
                       ways(len - pos_me, levels_deep - 1, count - c1)) %
            P;
    }
  }
  if (len != 1) {
    res = (res + ways(len - 1, levels_deep - 1, count)) % P;
  }
  return memo[len][levels_deep][count] = res;
}
int phi(int x) {
  int f = x;
  for (int i = 2; i * i <= x; i++) {
    int e = 0;
    while (x % i == 0) {
      e++;
      x /= i;
    }
    if (e) {
      f /= i;
      f *= (i - 1);
    }
  }
  if (x != 1) {
    f /= x;
    f *= (x - 1);
  }
  return f;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M >> K >> P;
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = (1LL * i * fact[i - 1]) % P;
  }
  int f = phi(P);
  for (int i = 0; i <= N; i++) {
    inv_fact[i] = lg_put(fact[i], f - 1);
  }
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = 0; k <= N; k++) {
        memo[i][j][k] = -1;
      }
    }
  }
  cout << ways(N, M, K) << '\n';
  return 0;
}
