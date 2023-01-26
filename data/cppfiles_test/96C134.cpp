#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
const ll mod = 998244353;
ll C[501][501];
ll F_mem[501][501];
ll pw[501][501] = {0};
ll ml(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll ad(ll a, ll b) { return (a + b + mod) % mod; }
ll F(int idx, int up_value) {
  if (idx == 0) return 1;
  if (idx == 1) return 0;
  if (up_value <= 0) return 0;
  ll &result = F_mem[idx][up_value];
  if (result != -1) return result;
  result = 0;
  for (int rem_cnt = 0; rem_cnt <= idx; ++rem_cnt) {
    result = ad(result,
                ml(pw[min(up_value, idx - 1)][rem_cnt],
                   ml(C[idx][rem_cnt], F(idx - rem_cnt, up_value - idx + 1))));
  }
  return result;
}
void solver() {
  int n, x;
  cin >> n >> x;
  C[0][0] = 1;
  for (int i = 1; i <= 500; ++i) {
    C[i][0] = 1;
    pw[i][0] = 1;
    F_mem[i][0] = -1;
    for (int j = 1; j <= 500; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      C[i][j] %= mod;
      pw[i][j] = (pw[i][j - 1] * i) % mod;
      F_mem[i][j] = -1;
    }
  }
  cout << F(n, x) << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool mt = 0;
  int tests = 1;
  if (mt) cin >> tests;
  for (int tt = 1; tt <= tests; ++tt) {
    solver();
  }
  return 0;
}
