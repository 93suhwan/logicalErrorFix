#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0, j = 0; i < v.size(); i++, j++)
    if (j >= 5) {
      j = 0;
      puts("");
    } else
      os << v[i] << " ";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  for (auto c : v) os << c << " ";
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v) {
  for (auto c : v) os << c.first << " " << c.second << '\n';
  return os;
}
template <typename T>
inline void rd(T& a) {
  char c = getchar();
  T x = 0, f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  a = f * x;
}
const int N = 2e5 + 10, M = 1e9 + 7;
int n, m;
vector<int> res;
int mp[1010][1010];
bool st[1010][1010];
int cnt;
void dfs(int x, int y) {
  cnt++;
  if (x < 1 || x > n || y < 1 || y > m) return;
  st[x][y] = 1;
  int t = mp[x][y];
  for (int i = 0; i < 4; i++) {
    int dir = (t >> i) & 1;
    if (i == 0) {
      if (dir == 0 && !st[x][y - 1]) {
        dfs(x, y - 1);
      }
    } else if (i == 1) {
      if (dir == 0 && !st[x + 1][y]) dfs(x + 1, y);
    } else if (i == 2) {
      if (dir == 0 && !st[x][y + 1]) dfs(x, y + 1);
    } else {
      if (dir == 0 && !st[x - 1][y]) dfs(x - 1, y);
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (m); ++j) cin >> mp[i][j];
  }
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (m); ++j) {
      if (!st[i][j]) {
        cnt = 0;
        dfs(i, j);
        res.push_back(cnt);
      }
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  for (auto c : res) {
    cout << c << " ";
  }
}
int main() {
  solve();
  return 0;
}
