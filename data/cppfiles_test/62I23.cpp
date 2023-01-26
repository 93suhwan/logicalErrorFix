#include <bits/stdc++.h>
using namespace std;
const int DIM = 1000 + 7;
int n, m, q, dp[DIM][DIM], sol;
bool active[DIM][DIM];
int goright[DIM][DIM];
int godown[DIM][DIM];
void upd(int r, int c) {
  if (active[r][c]) {
    sol -= (goright[r][c] + godown[r][c] - 1);
    goright[r][c] = 1 + active[r][c + 1] * (godown[r][c + 1]);
    godown[r][c] = 1 + active[r + 1][c] * (goright[r + 1][c]);
    sol += goright[r][c] + godown[r][c] - 1;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int r = n; r >= 1; r--) {
    for (int c = m; c >= 1; c--) {
      goright[r][c] = 1;
      active[r][c] = 1;
      upd(r, c);
    }
  }
  for (int it = 1; it <= q; it++) {
    int r, c;
    cin >> r >> c;
    if (active[r][c]) {
      sol -= (goright[r][c] + godown[r][c] - 1);
    } else {
      goright[r][c] = godown[r][c] = 0;
      goright[r][c] = 1;
    }
    active[r][c] ^= 1;
    vector<pair<int, int>> path;
    path.push_back({r, c});
    int i = r - 1, j = c - 1;
    while (i >= 1 && j >= 1) {
      path.push_back({i, j + 1});
      path.push_back({i + 1, j});
      path.push_back({i, j});
      i--;
      j--;
    }
    for (auto &it : path) {
      upd(it.first, it.second);
    }
    cout << sol << "\n";
  }
  return 0;
}
