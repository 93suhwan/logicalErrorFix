#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500;
const int N = 1e3 + 7, M = N * 2;
const int inf = 0x3f3f3f3f;
const long long INF = 0xFFFFFFFFFF;
const long long mod = 1e9 + 7;
inline long long read();
int p[N];
int b[N];
int find1(int x) {
  if (p[x] != x) p[x] = find1(p[x]);
  return p[x];
}
int find2(int x) {
  if (b[x] != x) b[x] = find2(b[x]);
  return b[x];
}
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<pair<int, int> > ans;
  for (int i = 1; i <= n; i++) {
    p[i] = b[i] = i;
  }
  for (int i = 1; i <= m1; i++) {
    int x, y;
    cin >> x >> y;
    p[find1(x)] = find1(y);
  }
  for (int i = 1; i <= m2; i++) {
    int x, y;
    cin >> x >> y;
    b[find2(x)] = find2(y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int x, y, c, d;
      x = find1(i), y = find1(j);
      c = find2(i), d = find2(j);
      if (x != y && c != d) {
        p[x] = y;
        b[c] = d;
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x.first << ' ' << x.second << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  for (int cas = 1; cas <= T; cas++) {
    solve();
  }
  return 0;
}
inline long long read() {
  char ch = getchar();
  long long p = 1, data = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + (ch ^ 48);
    ch = getchar();
  }
  return p * data;
}
