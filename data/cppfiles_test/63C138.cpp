#include <bits/stdc++.h>
using namespace std;
const long double pai = 3.1415926536;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const unsigned long long bas = 2333;
const int MAXN = 6e5 + 10;
const long long mod = 998244353;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
template <typename T>
void rd(T &x) {
  char ch = getchar();
  x = 0;
  int f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
template <typename T>
inline void wt(T a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) wt(a / 10);
  putchar(a % 10 + 48);
}
int fa[3010];
int fr(int x) {
  if (fa[x] == x) return x;
  return fa[x] = fr(fa[x]);
}
vector<pair<int, int> > v;
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  while (T--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= 2500; ++i) fa[i] = i;
    for (int i = 1; i <= m1; ++i) {
      int u, v;
      cin >> u >> v;
      int x = fr(u), y = fr(v);
      fa[y] = x;
    }
    for (int i = 1; i <= m2; ++i) {
      int u, v;
      cin >> u >> v;
      int x = fr(u + 1010), y = fr(v + 1010);
      fa[y] = x;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        if (fr(i) != fr(j) && fr(i + 1010) != fr(j + 1010)) {
          ++ans;
          v.emplace_back(i, j);
          int x = fa[i], y = fa[j];
          fa[y] = x;
          x = fr(i + 1010), y = fr(j + 1010);
          fa[y] = x;
        }
      }
    cout << ans << '\n';
    for (auto x : v) {
      cout << x.first << ' ' << x.second << '\n';
    }
  }
}
