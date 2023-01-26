#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2000005;
int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};
int n, m;
char a[N];
int d[N];
int id(int i, int j) { return (i * m + j); }
bool check(int x, int y) {
  return ((1 <= x && x <= n && 1 <= y && y <= m) && (a[id(x, y)] != '#'));
}
void solve() {
  queue<pair<int, int> > qu;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[id(i, j)];
      d[id(i, j)] = 0;
      if (a[id(i, j)] == 'L') {
        d[id(i, j)] = 1;
        qu.push(make_pair(i, j));
      }
    }
  }
  while (qu.size()) {
    int u = qu.front().first;
    int v = qu.front().second;
    qu.pop();
    for (int i = 0; i < 4; i++) {
      int x = u + dx[i];
      int y = v + dy[i];
      if (check(x, y) && (d[id(x, y)] == 0)) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
          if (d[id(x + dx[j], y + dy[j])] == 1) continue;
          cnt += check(x + dx[j], y + dy[j]);
        }
        if (cnt <= 2) {
          a[id(x, y)] = '+';
          qu.push(make_pair(x, y));
          d[id(x, y)] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[id(i, j)];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
