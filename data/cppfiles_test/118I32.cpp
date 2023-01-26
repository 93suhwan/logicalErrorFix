#include <bits/stdc++.h>
using namespace std;
int pop_count(long long x) { return __builtin_popcountll(x); }
int pop_count(int x) { return __builtin_popcount(x); }
template <typename S, typename T>
bool chminx(S &a, const T &b) {
  return a < b ? 1 : a = b, 0;
}
template <typename S, typename T>
bool chmaxx(S &a, const T &b) {
  return a > b ? 1 : a = b, 0;
}
template <typename T>
T mins(T a) {
  return a;
}
template <typename T, typename... Args>
T mins(T a, Args... args) {
  return min(a, mins(args...));
}
template <typename T>
T maxs(T a) {
  return a;
}
template <typename T, typename... Args>
T maxs(T a, Args... args) {
  return max(a, maxs(args...));
}
template <typename T>
void read_int(T &res) {
  int flag = 1;
  char ch;
  while (isspace(ch = getchar()))
    ;
  res = 0;
  if (ch == '-')
    flag = -1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  res *= flag;
}
void read_ints(){};
template <typename T, typename... Args>
void read_ints(T &t, Args &...args) {
  read_int(t);
  read_ints(args...);
}
template <typename T>
void int_out(T a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a > 9) int_out(a / 10);
  putchar(a % 10 + '0');
}
void int_outs() { puts(""); }
template <typename T, typename... Args>
void int_outs(T a, Args... args) {
  int_out(a);
  putchar(' ');
  int_outs(args...);
}
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int N = 1000005;
char s[N];
int n, m;
vector<array<int, 2>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool check(int x, int y, vector<vector<char>> g) {
  if (x < 0 || y < 0 || x >= n || y >= m || g[x][y] != '.') return false;
  int counts = 0;
  for (auto &dir : dirs) {
    int nx = x + dir[0];
    int ny = y + dir[1];
    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
    if (g[nx][ny] == '.') ++counts;
  }
  return counts <= 1;
}
int main() {
  int t;
  read_int(t);
  while (t--) {
    read_ints(n, m);
    vector<vector<char>> g(n, vector<char>(m));
    int x = -1, y = -1;
    for (int i = 0; i <= n - 1; ++i) {
      gets(s);
      for (int j = 0; j <= m - 1; ++j) {
        g[i][j] = s[j];
        if (s[j] == 'L') {
          x = i, y = j;
        }
      }
    }
    queue<pair<int, int>> que;
    que.push({x, y});
    while (!que.empty()) {
      pair<int, int> u = que.front();
      que.pop();
      x = u.first;
      y = u.second;
      for (auto &dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (check(nx, ny, g)) {
          g[nx][ny] = '+';
          que.push({nx, ny});
        }
      }
    }
    for (int i = 0; i <= n - 1; ++i) {
      for (int j = 0; j <= m - 1; ++j) {
        putchar(g[i][j]);
      }
      puts("");
    }
  }
  return 0;
}
