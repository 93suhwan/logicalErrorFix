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
long long two[SIZE];
int cnt[2][SIZE][2];
map<int, int> col[SIZE];
int err_cnt[2], fixed_cnt[2];
int sp_fixed[2];
void del(int ty, int x, int v) {
  cnt[ty][x][v]--;
  if (!cnt[ty][x][v] && cnt[ty][x][v ^ 1]) err_cnt[ty]--;
  if (!cnt[ty][x][0] && !cnt[ty][x][1]) fixed_cnt[ty]++;
}
void add(int ty, int x, int v) {
  cnt[ty][x][v]++;
  if (cnt[ty][x][v] == 1 && cnt[ty][x][v ^ 1]) err_cnt[ty]++;
  if (cnt[ty][x][v] == 1 && !cnt[ty][x][v ^ 1]) fixed_cnt[ty]--;
}
void rm(int x, int y) {
  auto it = col[x].find(y);
  int v = it->second;
  sp_fixed[(x + y + v) % 2]--;
  col[x].erase(it);
  del(0, x, v ^ (y & 1));
  del(1, y, v ^ (x & 1));
}
void ins(int x, int y, int v) {
  col[x][y] = v;
  sp_fixed[(x + y + v) % 2]++;
  add(0, x, v ^ (y & 1));
  add(1, y, v ^ (x & 1));
}
void solve() {
  int n, m, k;
  R(n, m, k);
  fixed_cnt[0] = n;
  fixed_cnt[1] = m;
  while (k--) {
    int x, y, v;
    R(x, y, v);
    if (col[x].count(y)) {
      rm(x, y);
    }
    if (v != -1) {
      ins(x, y, v);
    }
    long long an = 0;
    for (int i = 0; i < (2); ++i) {
      if (!err_cnt[i]) ADD(an, two[fixed_cnt[i]]);
    }
    if (!err_cnt[0] && !err_cnt[1]) {
      for (int i = 0; i < (2); ++i)
        if (!sp_fixed[i]) ADD(an, -1);
    }
    W(an);
  }
}
int main() {
  MOD = 998244353;
  two[0] = 1;
  for (int i = (1); i < (SIZE); ++i) two[i] = two[i - 1] * 2 % MOD;
  solve();
  return 0;
}
