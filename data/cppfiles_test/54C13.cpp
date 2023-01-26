#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 1e6 + 10;
const double eps = 1e-5;
bool vis[N];
bool visid[N];
vector<int> np[N];
int get(int p, int st) {
  if (st) return 2 * p - 1;
  return 2 * p;
}
void add(int u, int v) {
  np[u].push_back(v);
  np[v].push_back(u);
}
int cnt, fcnt;
void dfs(int p) {
  cnt++;
  fcnt += (p % 2 == 0);
  visid[(p + 1) / 2] = 1;
  vis[p] = 1;
  for (int nt : np[p]) {
    if (vis[nt]) continue;
    dfs(nt);
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
      vis[i] = 0;
      visid[i] = 0;
      np[i].clear();
    }
    while (m--) {
      int a, b;
      string c;
      cin >> a >> b >> c;
      bool flag = (c == "crewmate");
      add(get(a, 1), get(b, flag));
      add(get(a, 0), get(b, !flag));
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
      if (visid[(i + 1) / 2]) continue;
      cnt = fcnt = 0;
      dfs(i);
      ans += max(cnt - fcnt, fcnt);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (vis[get(i, 1)] && vis[get(i, 0)]) {
        ok = false;
        break;
      }
    }
    if (ok)
      cout << ans << '\n';
    else
      cout << -1 << '\n';
  }
}
