#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
long long dp[8888] = {
    0,
};
set<int> s[7777];
int sidx = 0;
pair<int, int> pos[1001][1001][2];
int asgn[1001][1001][2] = {
    0,
};
int flipped[1001][1001] = {
    0,
};
long long flipcnt = 0;
int n, m, q;
bool isIn(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void god(int x, int y, int spos, int cnt);
void gor(int x, int y, int spos, int cnt) {
  if (!isIn(x, y)) {
    s[spos].insert(cnt);
    return;
  }
  asgn[x][y][0] = 1;
  pos[x][y][0] = make_pair(spos, cnt);
  god(x + 1, y, spos, cnt + 1);
}
void god(int x, int y, int spos, int cnt) {
  if (!isIn(x, y)) {
    s[spos].insert(cnt);
    return;
  }
  asgn[x][y][1] = 1;
  pos[x][y][1] = make_pair(spos, cnt);
  gor(x, y + 1, spos, cnt + 1);
}
long long S = 0;
void toff(int si, int pos) {
  auto itr = s[si].lower_bound(pos);
  auto litr = prev(itr);
  int lpos = *litr;
  int rpos = *itr;
  int len = rpos - lpos - 1;
  if (len - 1 >= 0) S -= dp[len - 1];
  s[si].insert(pos);
  int lcnt = pos - lpos - 1;
  int rcnt = rpos - pos - 1;
  if (lcnt - 1 >= 0) S += dp[lcnt - 1];
  if (rcnt - 1 >= 0) S += dp[rcnt - 1];
}
void ton(int si, int pos) {
  auto itr = s[si].lower_bound(pos);
  auto litr = prev(itr);
  auto ritr = next(itr);
  int lpos = *litr;
  int rpos = *ritr;
  int lcnt = pos - lpos - 1;
  int rcnt = rpos - pos - 1;
  int len = rpos - lpos - 1;
  s[si].erase(pos);
  if (len - 1 >= 0) S += dp[len - 1];
  if (lcnt - 1 >= 0) S -= dp[lcnt - 1];
  if (rcnt - 1 >= 0) S -= dp[rcnt - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= 8444; i++) {
    dp[i] = dp[i - 1] + i;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (asgn[i][j][0] == 0) {
        s[++sidx].insert(0);
        gor(i, j, sidx, 1);
      }
      if (asgn[i][j][1] == 0) {
        s[++sidx].insert(0);
        god(i, j, sidx, 1);
      }
      flipped[i][j] = 1;
      ++flipcnt;
    }
  }
  for (int i = 1; i < sidx; i++) {
    int len = *s[i].rbegin() - 1;
    S += dp[len - 1];
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (flipped[a][b] == 1) {
      --flipcnt;
      for (auto sx : {0, 1}) {
        auto [psi, pidx] = pos[a][b][sx];
        toff(psi, pidx);
      }
      flipped[a][b] ^= 1;
    } else {
      ++flipcnt;
      for (auto sx : {0, 1}) {
        auto [psi, pidx] = pos[a][b][sx];
        ton(psi, pidx);
      }
      flipped[a][b] ^= 1;
    }
    cout << S + flipcnt << "\n";
  }
}
