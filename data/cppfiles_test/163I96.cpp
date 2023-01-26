#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
const int MOD = 1e9 + 7;
int64_t mult(int64_t a, int64_t b) {
  a %= MOD, b %= MOD;
  return (a * b) % MOD;
}
int64_t binPow(int64_t x, int64_t y) {
  x %= MOD;
  int64_t res = x;
  int64_t ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = mult(ans, res);
    }
    res = mult(res, res);
    y /= 2;
  }
  return ans;
}
int64_t inv(int64_t a) { return binPow(a, MOD - 2); }
int64_t frac(int64_t a, int64_t b) {
  assert(b != 0);
  return mult(a, inv(b));
}
int64_t solver(int64_t x, int64_t a, int64_t b, int64_t c, int64_t d) {
  int64_t x1 = mult(mult(a, binPow(x, c)), MOD + 1 - binPow(x, d)) +
               mult(b, binPow(x, c + d));
  x1 %= MOD;
  int64_t x2 = ((binPow(x, d) - 1) * (binPow(x, d) - 1)) % MOD;
  return frac(x1, x2);
}
void solve() {
  int n, m, r_b, c_b, r_d, c_d, p;
  cin >> n >> m >> r_b >> c_b >> r_d >> c_d >> p;
  vector<pair<pair<int, int>, pair<int, int>>> used, cycle;
  set<pair<pair<int, int>, pair<int, int>>> u, c;
  pair<int, int> d = {1, 1};
  pair<int, int> cur = {r_b, c_b};
  while (true) {
    if (cur.first + d.first == 0 || cur.first + d.first == n + 1) {
      d.first = -d.first;
    }
    if (cur.second + d.second == 0 || cur.second + d.second == m + 1) {
      d.second = -d.second;
    }
    cur.first += d.first, cur.second += d.second;
    if (c.count({cur, d})) {
      break;
    }
    if (u.count({cur, d})) {
      cycle.push_back({cur, d}), c.insert({cur, d});
    }
    used.push_back({cur, d}), u.insert({cur, d});
  }
  vector<pair<pair<int, int>, pair<int, int>>> new_used;
  for (auto& i : used) {
    if (!c.count(i)) {
      new_used.push_back(i);
    }
  }
  for (auto& p : new_used) {
    cout << p.first.first << " " << p.first.second << " " << p.second.first
         << " " << p.second.second << '\n';
  }
  int64_t ans = 0;
  for (int i = 0; i < new_used.size(); i++) {
    if (new_used[i].first.first == r_d || new_used[i].first.second == c_d) {
      ans += mult(p, binPow(1 - frac(p, 100), i));
    }
  }
  int cnt_black_cycle = 0;
  for (int i = 0; i < cycle.size(); i++) {
    cnt_black_cycle +=
        (cycle[i].first.first == r_d || cycle[i].first.second == c_d);
  }
  int cnt_black = 0;
  int cnt = new_used.size();
  for (int i = 0; i < cycle.size(); i++) {
    int64_t X = (MOD + 1 - frac(p, 100)) % MOD;
    int64_t A = cnt;
    int64_t B = cycle.size();
    int64_t C = cnt_black;
    int64_t D = cnt_black_cycle;
    ans += solver(X, A, B, C, D);
    cnt_black += (cycle[i].first.first == r_d || cycle[i].first.second == c_d);
    cnt++;
    ans %= MOD;
  }
  ans = mult(ans, frac(p, 100));
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
