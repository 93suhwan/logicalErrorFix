#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
const int M = 8e3 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 1004535809;
const double eps = 1e-13;
const double pi = acos(-1.0);
const int S = 100;
long long read() {
  long long x = 0, t = 1;
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') t = -1;
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * t;
}
int n, m;
struct node {
  int c[N];
  void update(int x, int y) {
    for (int i = x; i <= m; i += i & -i) c[i] += y;
  }
  int ask(int x) {
    int res = 0;
    for (int i = x; i; i -= i & -i) res += c[i];
    return res;
  }
  void cls() {
    for (int i = 1; i <= m; i++) c[i] = 0;
  }
} tree[N];
int len;
vector<pair<int, int> > mp[N * N];
int p[N * N], a[N][N], t[N * N];
inline int getid(int &x) { return lower_bound(t + 1, t + len + 1, x) - t; }
int main() {
  int T = read();
  while (T--) {
    int tot = 0, ans = 0;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] = read(), t[++tot] = a[i][j];
    sort(t + 1, t + tot + 1);
    len = tot;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        mp[getid(t[(i - 1) * m + j])].emplace_back(i, j);
    for (int i = 1; i <= len; i++)
      sort(mp[i].begin(), mp[i].end(), [&](pair<int, int> x, pair<int, int> y) {
        return x.second > y.second;
      });
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int k = getid(a[i][j]);
        pair<int, int> x = mp[k][p[k]++];
        tree[x.first].update(x.second, 1);
        ans += tree[x.first].ask(x.second - 1);
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= tot; i++) mp[i].clear(), p[i] = 0;
    for (int i = 1; i <= n; i++) tree[i].cls();
  }
  return 0;
}
