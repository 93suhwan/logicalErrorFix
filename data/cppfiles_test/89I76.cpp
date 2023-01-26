#include <bits/stdc++.h>
using namespace std;
long long read() {
  char c = getchar();
  long long x = 1;
  long long s = 0;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
const long long N = 2e5 + 5;
vector<long long> v[N];
long long n, x, y, siz[N], fu[N], f[N], tong, yz;
void dfs(long long u, long long fa) {
  long long cnt = 1, tmp = 0;
  f[u] = 1;
  for (long long i = 0; i < v[u].size(); i++) {
    if (v[u][i] == fa) continue;
    cnt++;
    dfs(v[u][i], u);
    if (siz[v[u][i]] == 1) tmp++;
  }
  siz[u] = cnt;
  if (f[u] && siz[u] != 1 && tmp) {
    tong = tong + tmp - 1;
  }
  if (cnt == 1) yz++;
}
void solve() {
  n = read();
  for (long long i = 1; i < n; i++) {
    x = read();
    y = read();
    v[x].push_back(y);
    v[y].push_back(x);
  }
  if (n == 2) {
    cout << 1 << '\n';
  } else {
    dfs(1, 0);
    cout << tong + 1 << '\n' << '\n';
  }
  for (long long i = 1; i <= n; i++)
    v[i].clear(), siz[i] = 0, fu[i] = 0, f[i] = 0;
  tong = yz = 0;
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
