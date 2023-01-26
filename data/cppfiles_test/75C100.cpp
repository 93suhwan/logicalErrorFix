#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  static char c;
  static int f;
  for (c = getchar(), f = 1; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c & 15);
  x *= f;
}
template <typename T>
void write(T x) {
  static char q[65];
  int cnt = 0;
  if (x < 0) putchar('-'), x = -x;
  q[++cnt] = x % 10, x /= 10;
  while (x) q[++cnt] = x % 10, x /= 10;
  while (cnt) putchar(q[cnt--] + '0');
}
const int N = 2e5 + 10;
int n;
int a[N];
int cnt = 0;
int idx, idy;
map<pair<int, int>, int> S;
int sg(int x, int y) {
  if (x > y) return 0;
  if (S.count({x, y})) return S[{x, y}];
  int mx = max(a[x - 1], a[y + 1]);
  if (mx >= max(a[x], a[y])) {
    return S[{x, y}] = 0;
  } else {
    int a1, a2;
    if (a[x] >= a[y]) {
      int dis = idx - x;
      a1 = !(dis % 2);
      if (a1 == 0) {
        return S[{x, y}] = 1;
      } else {
        if (a[y] <= mx) return S[{x, y}] = 0;
        a2 = sg(x, y - 1);
        if (a2 == 0)
          return S[{x, y}] = 1;
        else
          return S[{x, y}] = 0;
      }
    } else {
      int dis = y - idy;
      a1 = !(dis % 2);
      if (a1 == 0)
        return S[{x, y}] = 1;
      else {
        if (a[x] <= mx) return S[{x, y}] = 0;
        a2 = sg(x + 1, y);
        if (a2 == 0)
          return S[{x, y}] = 1;
        else
          return S[{x, y}] = 0;
      }
    }
  }
}
void solve() {
  memset(a, -1, sizeof a);
  scanf("%d", &n);
  for (auto i = 1; i <= n; ++i) scanf("%d", &a[i]);
  idx = 1, idy = n;
  while (a[idx] > a[idx - 1]) {
    idx++;
  }
  while (a[idy] > a[idy + 1]) {
    idy--;
  }
  puts(sg(1, n) == 1 ? "Alice" : "Bob");
}
signed main(int argc, char const *argv[]) {
  solve();
  return 0;
}
