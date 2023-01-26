#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long t, n, m, vis[100000], mst[100000], num[100000];
vector<long long> p[100000], ok[100000];
bool check(long long x) {
  fill(vis, vis + m, 0);
  fill(mst, mst + n, 0);
  fill(num, num + n, 0);
  for (long long i = 0; i < m; i++) ok[i].clear();
  for (long long i = 0; i < m; i++)
    for (long long l = 0; l < n; l++) ok[i].push_back(0);
  for (long long i = 0; i < n; i++)
    for (long long l = 0; l < m; l++)
      if (p[i][l] >= x) {
        ok[l][i] = 1;
        vis[l]++;
        num[i]++;
      }
  for (long long i = 0; i < m; i++)
    if (!vis[i]) return 0;
  for (long long i = 0; i < m; i++)
    for (long long l = 0; l < n; l++)
      if (vis[i] == 1 && ok[i][l]) mst[l] = 1;
  long long res = 0;
  for (long long i = 0; i < n; i++) res += mst[i];
  if (res >= m) return 0;
  for (long long i = 0; i < n; i++)
    if (num[i] > 1) return 1;
  return 0;
}
void solve() {
  n = read();
  m = read();
  for (long long i = 0; i < n; i++) {
    p[i].clear();
    for (long long l = 1; l <= m; l++) p[i].push_back(read());
  }
  long long l = 1, r = 1000000000;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << l - 1 << endl;
}
signed main() {
  t = read();
  while (t--) solve();
  return 0;
}
