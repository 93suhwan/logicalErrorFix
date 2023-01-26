#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<long>> dp;
vector<vector<char>> board;
pair<long long, long long> trans(long long x, long long y) {
  switch (board[x][y]) {
    case 'U':
      x--;
      break;
    case 'D':
      x++;
      break;
    case 'R':
      y++;
      break;
    case 'L':
      y--;
      break;
  }
  return make_pair(x, y);
}
bool valid(long long x, long long y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  return true;
}
pair<pair<long long, long long>, long long> dfs(long long x, long long y) {
  if (!valid(x, y)) {
    return make_pair(make_pair(-1, -1), 0);
  }
  if (dp[x][y] == 0) {
    return make_pair(make_pair(x, y), 0);
  }
  if (dp[x][y] != -1) {
    return make_pair(make_pair(-1, -1), dp[x][y]);
  }
  dp[x][y] = 0;
  auto next = trans(x, y);
  auto ret = dfs(next.first, next.second);
  auto anchor = ret.first;
  auto dist = ret.second;
  dist++;
  if (anchor.first == x && anchor.second == y) {
    auto cur = anchor;
    while (1) {
      dp[cur.first][cur.second] = dist;
      cur = trans(cur.first, cur.second);
      if (cur.first == x && cur.second == y) {
        break;
      }
    }
    return make_pair(make_pair(-1, -1), dist);
  } else {
    dp[x][y] = dist;
    return make_pair(anchor, dist);
  }
}
stack<pair<long long, long long>> p;
void non_recur(long long x, long long y) {
  auto head = make_pair(x, y);
  pair<long long, long long> anchor = make_pair(-1, -1);
  long long dist = 1;
  while (1) {
    dp[head.first][head.second] = 0;
    p.push(head);
    head = trans(head.first, head.second);
    long long x = head.first, y = head.second;
    if (!valid(x, y)) break;
    if (dp[x][y] == 0) {
      anchor = make_pair(x, y);
      break;
    }
    if (dp[x][y] != -1) {
      dist = dp[x][y] + 1;
      break;
    }
  }
  while (!p.empty()) {
    head = p.top();
    if (anchor.first == head.first && anchor.second == head.second) {
      auto cur = anchor;
      while (1) {
        dp[cur.first][cur.second] = dist;
        cur = trans(cur.first, cur.second);
        if (cur.first == head.first && cur.second == head.second) {
          break;
        }
      }
      anchor = make_pair(-1, -1);
    } else {
      dp[head.first][head.second] = dist;
    }
    dist++;
    p.pop();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    board.assign(n, vector<char>(m));
    dp.assign(n, vector<long>(m, -1));
    for (long long i = (0); i < (n); i++) {
      for (long long j = (0); j < (m); j++) {
        cin >> board[i][j];
      }
    }
    long long mxx, mxy, mx = 0;
    for (long long i = (0); i < (n); i++) {
      for (long long j = (0); j < (m); j++) {
        if (dp[i][j] == -1) {
          non_recur(i, j);
        }
        if (dp[i][j] > mx) {
          mx = dp[i][j];
          mxx = i;
          mxy = j;
        }
      }
    }
    cout << mxx + 1 << ' ' << mxy + 1 << ' ' << mx << '\n';
  }
}
