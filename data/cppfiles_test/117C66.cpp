#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1 << 20;
int n, m;
bool out(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
string s[SIZE];
bool good(int x, int y) {
  return !out(x, y) && (s[x][y] == 'L' || s[x][y] == '+');
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool check(pair<int, int> me) {
  int cnt = 0;
  for (int i = 0; i < (4); ++i) {
    pair<int, int> nxt{me.first + dx[i], me.second + dy[i]};
    if (out(nxt.first, nxt.second)) continue;
    if (s[nxt.first][nxt.second] == '#') continue;
    if (s[nxt.first][nxt.second] == '.') cnt++;
  }
  return cnt <= 1;
}
pair<int, int> bfs[SIZE];
void solve() {
  pair<int, int> lab;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) {
      if (s[i][j] == 'L') lab = {i, j};
    }
  int rr = 0;
  bfs[rr++] = lab;
  for (int i = 0; i < (rr); ++i) {
    auto now = bfs[i];
    for (int j = 0; j < (4); ++j) {
      pair<int, int> nxt = {now.first + dx[j], now.second + dy[j]};
      if (out(nxt.first, nxt.second)) continue;
      if (s[nxt.first][nxt.second] != '.') continue;
      if (check(nxt)) {
        s[nxt.first][nxt.second] = '+';
        bfs[rr++] = nxt;
      }
    }
  }
  for (int i = 0; i < (n); ++i) W(s[i]);
}
void input() {
  R(n, m);
  for (int i = 0; i < (n); ++i) R(s[i]);
}
int main() {
  int ___T;
  scanf("%d", &___T);
  for (int cs = 1; cs <= ___T; cs++) {
    input();
    solve();
  }
  return 0;
}
