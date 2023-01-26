#include <bits/stdc++.h>
using namespace std;
int N, M;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dp[2005][2005][2], dp2[2005][2005][2];
bool arr[2005][2005];
set<int> s[2005];
long long dist(long long x1, long long y1, long long x2, long long y2) {
  if (x1 == -1 || x2 == -1) return 1e15;
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i <= N; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j <= M; ++j) {
      arr[i][j] = str[j] - '0';
      if (arr[i][j]) {
        s[i].insert(j);
      }
    }
  }
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      auto p = s[i].lower_bound(j);
      int m = -1;
      if (p != s[i].end()) {
        m = *p;
      }
      if (p != s[i].begin() &&
          (p == s[i].end() || abs(j - *p) > abs(j - *prev(p)))) {
        m = *prev(p);
      }
      if (~m) {
        dp[i][j][0] = dp2[i][j][0] = i;
        dp[i][j][1] = dp2[i][j][1] = m;
      }
      for (int k = 0; k < 8; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx > N || ny < 0 || ny > M || dp[nx][ny][0] == -1)
          continue;
        if (dist(dp[nx][ny][0], dp[nx][ny][1], i, j) <
            dist(dp[i][j][0], dp[i][j][1], i, j)) {
          dp[i][j][0] = dp[nx][ny][0];
          dp[i][j][1] = dp[nx][ny][1];
        }
      }
    }
    for (int j = M; j >= 0; --j) {
      for (int k = 0; k < 8; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx > N || ny < 0 || ny > M || dp[nx][ny][0] == -1)
          continue;
        if (dist(dp[nx][ny][0], dp[nx][ny][1], i, j) <
            dist(dp[i][j][0], dp[i][j][1], i, j)) {
          dp[i][j][0] = dp[nx][ny][0];
          dp[i][j][1] = dp[nx][ny][1];
        }
      }
    }
  }
  for (int i = N; i >= 0; --i) {
    for (int j = 0; j <= M; ++j) {
      for (int k = 0; k < 8; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx > N || ny < 0 || ny > M || dp2[nx][ny][0] == -1)
          continue;
        if (dist(dp2[nx][ny][0], dp2[nx][ny][1], i, j) <
            dist(dp2[i][j][0], dp2[i][j][1], i, j)) {
          dp2[i][j][0] = dp2[nx][ny][0];
          dp2[i][j][1] = dp2[nx][ny][1];
        }
      }
    }
    for (int j = M; j >= 0; --j) {
      for (int k = 0; k < 8; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx > N || ny < 0 || ny > M || dp2[nx][ny][0] == -1)
          continue;
        if (dist(dp2[nx][ny][0], dp2[nx][ny][1], i, j) <
            dist(dp2[i][j][0], dp2[i][j][1], i, j)) {
          dp2[i][j][0] = dp2[nx][ny][0];
          dp2[i][j][1] = dp2[nx][ny][1];
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) {
      ans += min(dist(dp[i][j][0], dp[i][j][1], i, j),
                 dist(dp2[i][j][0], dp2[i][j][1], i, j));
    }
  }
  cout << ans << endl;
  return 0;
}
