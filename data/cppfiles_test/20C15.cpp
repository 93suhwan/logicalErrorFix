#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
const int N = 4e2 + 12;
char S[N][N];
int pref[N][N];
int sum_rec(pair<int, int> a, pair<int, int> b);
int inv_rec(pair<int, int> a, pair<int, int> b);
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", S[i] + 1);
  }
  for (int i = 0; i <= n + 1; i++) {
    memset(pref[i], 0, n + 2);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = int(S[i][j] == '1') + pref[i - 1][j] + pref[i][j - 1] -
                   pref[i - 1][j - 1];
    }
  }
  int res = 1e9;
  for (int k = 1; k <= n; k++) {
    for (int l = k + 4; l <= n; l++) {
      stack<int> first;
      for (int i = m; i >= 4; i--) {
        int cost_center = sum_rec({k + 1, 1}, {l - 1, i - 1});
        int cost_sides =
            inv_rec({l, 1}, {l, i - 1}) + inv_rec({k, 1}, {k, i - 1});
        int cost_end = inv_rec({k + 1, i}, {l - 1, i});
        int full_cost = cost_center + cost_sides + cost_end;
        if (!first.empty()) {
          full_cost = min(full_cost, first.top());
        }
        first.push(full_cost);
      }
      int diff = 0;
      for (int i = 1; i <= m - 3; i++) {
        int curr_diff = (inv_rec({k + 1, i}, {l - 1, i}));
        diff -= (sum_rec({k + 1, i}, {l - 1, i}) + int(S[k][i] == '0') +
                 int(S[l][i] == '0'));
        res = min(res, diff + curr_diff + first.top());
        first.pop();
      };
      ;
    }
  }
  printf("%d\n", res);
}
int sum_rec(pair<int, int> a, pair<int, int> b) {
  return pref[b.first][b.second] - pref[b.first][a.second - 1] -
         pref[a.first - 1][b.second] + pref[a.first - 1][a.second - 1];
}
int inv_rec(pair<int, int> a, pair<int, int> b) {
  return (b.first - a.first + 1) * (b.second - a.second + 1) - sum_rec(a, b);
}
