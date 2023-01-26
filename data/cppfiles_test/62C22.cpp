#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<vector<bool>> a(n, vector<bool>(m, 1));
  long long total = 0;
  vector<vector<pair<long long, long long>>> dp(
      n, vector<pair<long long, long long>>(m));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      if (i == 0) {
        if (j == 0)
          ;
        else
          dp[i][j].second = 1;
      } else if (j == 0)
        dp[i][j].first = 1;
      else
        dp[i][j].first = (dp[i - 1][j].second + 1),
        dp[i][j].second = (dp[i][j - 1].first + 1);
      total += (1 + dp[i][j].first + dp[i][j].second);
    }
  }
  while (q--) {
    long long r, c;
    cin >> r >> c;
    --r, --c;
    long long cur_c = c, cur_r = r;
    bool add = 0;
    if (!a[r][c]) add = 1;
    long long ts = 0, trn = 0, t1u = 0, t2u = 0, t1d = 0, t2d = 0;
    while (cur_c >= 0 && cur_r >= 0) {
      if (cur_r == r && cur_c == c) {
        t1u += 1;
        cur_r -= 1;
        trn++;
        continue;
      }
      if (a[cur_r][cur_c] == 0) break;
      if (trn == 0)
        cur_r -= 1;
      else
        cur_c -= 1;
      trn++;
      trn %= 2;
      t1u++;
    }
    cur_r = r, cur_c = c;
    trn = 0;
    while (cur_r >= 0 && cur_c >= 0) {
      if (cur_r == r && cur_c == c) {
        cur_c -= 1;
        trn++;
        continue;
      }
      if (a[cur_r][cur_c] == 0) break;
      if (trn == 0)
        cur_c -= 1;
      else
        cur_r -= 1;
      trn++;
      trn %= 2;
      t2u++;
    }
    cur_r = r, cur_c = c;
    trn = 0;
    while (cur_r < n && cur_c < m) {
      if (cur_r == r && cur_c == c) {
        cur_r += 1;
        trn++;
        continue;
      }
      if (a[cur_r][cur_c] == 0) break;
      if (trn == 0)
        cur_r += 1;
      else
        cur_c += 1;
      trn++;
      trn %= 2;
      t1d++;
    }
    cur_r = r, cur_c = c;
    trn = 0;
    while (cur_r < n && cur_c < m) {
      if (cur_r == r && cur_c == c) {
        cur_c += 1;
        trn++;
        continue;
      }
      if (a[cur_r][cur_c] == 0) break;
      ;
      if (trn == 0)
        cur_c += 1;
      else
        cur_r += 1;
      trn++;
      trn %= 2;
      t2d++;
    }
    ts = (t1u + t2u + t1d + t2d);
    ts += ((t1u - 1) * t2d + t2u * t1d);
    a[r][c] = (!a[r][c]);
    if (add)
      total += ts;
    else
      total -= ts;
    cout << total << '\n';
  }
}
int32_t main() {
  long long nt;
  nt = 1;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  while (nt--) {
    solve();
  }
}
