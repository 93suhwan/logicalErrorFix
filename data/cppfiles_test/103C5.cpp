#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int mx = 1e6 + 5;
const int INF = 1000000007;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y >>= 1;
    x = (x * x) % 1000000007;
  }
  return (res % 1000000007);
}
bool isValid(long long X, long long Y, long long x, long long y) {
  return X >= 0 && X < x && Y >= 0 && Y < y;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  vector<vector<int>> vis(n, vector<int>(m, 0));
  cin >> arr;
  vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
  vector<vector<long long>> ans(n, vector<long long>(m, -1));
  long long res = 0;
  long long srcX, srcY;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] == -1) {
        vector<pair<int, int>> stack;
        int currX = i, currY = j;
        vis[currX][currY] = 1;
        stack.push_back({currX, currY});
        long long extra = 0;
        int cycleX = -1, cycleY;
        while (true) {
          if (arr[currX][currY] == 'L') {
            currY--;
          } else if (arr[currX][currY] == 'R') {
            currY++;
          } else if (arr[currX][currY] == 'U') {
            currX--;
          } else {
            currX++;
          }
          if (isValid(currX, currY, n, m)) {
            if (!vis[currX][currY]) {
              vis[currX][currY] = 1;
              stack.push_back({currX, currY});
            } else if (vis[currX][currY] && ans[currX][currY] == -1) {
              extra = 0;
              cycleX = currX, cycleY = currY;
              break;
            } else {
              extra = ans[currX][currY];
              break;
            }
          } else
            break;
        }
        if (cycleX != -1) {
          long long vals = 0;
          for (int i = (int)stack.size() - 1; i >= 0; i--) {
            vals++;
            if (cycleX == stack[i].first && cycleY == stack[i].second) {
              while (stack.size() > i) {
                currX = stack.back().first, currY = stack.back().second;
                stack.pop_back();
                ans[currX][currY] = vals + extra;
              }
              break;
            }
          }
          extra += vals;
        }
        while (stack.size()) {
          currX = stack.back().first, currY = stack.back().second;
          stack.pop_back();
          ans[currX][currY] = ++extra;
        }
      }
      if (ans[i][j] > res) {
        res = max(res, ans[i][j]);
        srcX = i;
        srcY = j;
      }
    }
  }
  cout << srcX + 1 << ' ' << srcY + 1 << ' ' << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
