#include <bits/stdc++.h>
using namespace std;
int n, len;
long long t[4 * 200007], dp[200007], mod[4 * 200007], total, modulo;
void push(int v, int tl, int tr) {
  int tm = (tl + tr) >> 1;
  t[2 * v + 1] += (mod[v] * (tm - tl + 1)) % modulo;
  t[2 * v + 2] += (mod[v] * (tr - tm)) % modulo;
  t[2 * v + 1] %= modulo;
  t[2 * v + 2] %= modulo;
  mod[2 * v + 1] += mod[v];
  mod[2 * v + 2] += mod[v];
  mod[2 * v + 1] %= modulo;
  mod[2 * v + 2] %= modulo;
  mod[v] = 0;
  return;
}
void update(int v, int tl, int tr, int L, int R, int val) {
  if (tr < L || R < tl) return;
  if (L <= tl && tr <= R) {
    mod[v] += val;
    mod[v] %= modulo;
    t[v] += (tr - tl + 1) * val;
    t[v] %= modulo;
    return;
  }
  push(v, tl, tr);
  int tm = (tl + tr) >> 1;
  update(2 * v + 1, tl, tm, L, R, val);
  update(2 * v + 2, tm + 1, tr, L, R, val);
  t[v] = (t[2 * v + 1] + t[2 * v + 2]) % modulo;
  return;
}
long long get_dp(int v, int tl, int tr, int x) {
  if (tr < x || x < tl) return 0;
  if (tl == tr) return t[v];
  push(v, tl, tr);
  int tm = (tl + tr) >> 1;
  long long dp1 = get_dp(2 * v + 1, tl, tm, x);
  long long dp2 = get_dp(2 * v + 2, tm + 1, tr, x);
  return dp1 + dp2;
}
int main() {
  cin >> n >> modulo;
  dp[1] = 1;
  total = 1;
  len = 2;
  for (int i = 1 + 1; i <= n; i += 1) {
    update(0, 1, n, i, min(n, i + len - 1), dp[1]);
    len++;
  }
  for (int i = 2; i <= n; i++) {
    dp[i] = (total + get_dp(0, 1, n, i)) % modulo;
    total += dp[i];
    total %= modulo;
    len = 2;
    for (int j = 2 * i; j <= n; j += i) {
      update(0, 1, n, j, min(n, j + len - 1), dp[i]);
      len++;
    }
  }
  cout << dp[n];
  return 0;
}
