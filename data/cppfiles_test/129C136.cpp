#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline long long read() {
  long long first = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    first = first * 10 + ch - '0';
    ch = getchar();
  }
  return first * f;
}
inline void ou(long long first) {
  char ch[40];
  int len = 0;
  if (first < 0) {
    putchar('-');
    first = ~first + 1;
  }
  do {
    ch[len++] = first % 10 + '0';
    first /= 10;
  } while (first > 0);
  for (int i = len - 1; i >= 0; i--) putchar(ch[i]);
  return;
}
inline int addmod(int u_, int v_, int MOD) {
  u_ += v_;
  return u_ >= MOD ? u_ - MOD : u_;
}
inline int submod(int u_, int v_, int MOD) {
  u_ -= v_;
  return u_ < 0 ? u_ + MOD : u_;
}
const double eps = 1e-8;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
const int N = 1010;
int a[maxn], st[maxn];
void solve() {
  std::vector<int> v;
  int n = read();
  for (int i = 1; i <= n; ++i) st[i] = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    if (a[i] <= n and !st[a[i]])
      st[a[i]] = 1;
    else
      v.push_back(a[i]);
  }
  vector<int> b;
  for (int i = 1; i <= n; ++i)
    if (!st[i]) b.push_back(i);
  sort((v).begin(), (v).end());
  int si = v.size();
  for (int i = 0; i <= si - 1; ++i) {
    int dod = 0;
    if (v[i] & 1)
      dod = v[i] / 2;
    else
      dod = v[i] / 2 - 1;
    if (dod < b[i]) {
      ou(-1), puts("");
      return;
    }
  }
  ou(si), puts("");
}
signed main() {
  int _ = 1;
  _ = read();
  for (int cas = 1; cas <= _; ++cas) {
    solve();
  }
  return 0;
}
