#include <bits/stdc++.h>
using namespace std;
constexpr static int MOD = 998244353;
constexpr static int MAXN = 1e6 + 10;
int64_t p2[MAXN];
int rstart[MAXN][2];
int cstart[MAXN][2];
void solve() {
  p2[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    p2[i] = p2[i - 1] * 2;
    if (p2[i] >= MOD) p2[i] -= MOD;
  }
  int n, m, q;
  cin >> n >> m >> q;
  unordered_map<int64_t, int> cells;
  int rfree = n;
  int rboth = 0;
  int cfree = m;
  int cboth = 0;
  vector<int> used(2);
  while (q--) {
    int r, c, t;
    cin >> r >> c >> t;
    r--, c--;
    auto it = cells.find(1LL * m * r + c);
    if (it != cells.end()) {
      int& cs = cstart[c][(r + it->second) % 2];
      cs--;
      if (cs == 0) {
        if (cstart[c][0] + cstart[c][1] == 0)
          cfree++;
        else
          cboth--;
      }
      int& rs = rstart[r][(c + it->second) % 2];
      rs--;
      if (rs == 0) {
        if (rstart[r][0] + rstart[r][1] == 0)
          rfree++;
        else
          rboth--;
      }
      used[(r + c + it->second) % 2]--;
    }
    if (t == -1) {
      if (it != cells.end()) cells.erase(it);
    } else {
      int& cs = cstart[c][(r + t) % 2];
      cs++;
      if (cs == 1) {
        if (cstart[c][0] + cstart[c][1] == 1)
          cfree--;
        else
          cboth++;
      }
      int& rs = rstart[r][(c + t) % 2];
      rs++;
      if (rs == 1) {
        if (rstart[r][0] + rstart[r][1] == 1)
          rfree--;
        else
          rboth++;
      }
      used[(r + c + t) % 2]++;
      cells[1LL * m * r + c] = t;
    }
    int64_t total = 0;
    if (cboth == 0) {
      assert(cfree >= 0);
      assert(cfree <= m);
      total += p2[cfree];
    }
    if (rboth == 0) {
      assert(rfree >= 0);
      assert(rfree <= n);
      total += p2[rfree];
      if (used[0] == 0) total += MOD - 1;
      if (used[1] == 0) total += MOD - 1;
    }
    while (total >= MOD) total -= MOD;
    cout << total << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
