#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
const int MOD = 998244353;
int n;
vector<int> adj[MAXN];
int ans[MAXN + 1];
int par[MAXN], sz[MAXN];
void dfsinit(int at) {
  sz[at] = 1;
  for (int to : adj[at]) {
    if (to == par[at]) continue;
    par[to] = at;
    dfsinit(to);
    sz[at] += sz[to];
  }
}
void solve() {
  par[0] = -1;
  dfsinit(0);
  for (int i = (1); i <= (n); ++i) ans[i] = 0;
  ans[1] = 1;
  for (int i = (0); i < (n - 1); ++i) ans[1] = (long long)ans[1] * 2 % MOD;
  for (int i = (2); i <= (n); ++i)
    if ((n - 1) % i == 0) {
      bool ok = true;
      for (int j = (0); j < (n); ++j)
        if ((sz[j] - 1) % i != 0 && sz[j] % i != 0) ok = false;
      if (ok) ++ans[i];
    }
  for (int i = n; i >= 1; --i)
    for (int j = i + i; j <= n; j += i) ans[i] -= ans[j];
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  solve();
  for (int i = (1); i <= (n); ++i) {
    if (i != 1) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
  for (int i = (0); i < (n); ++i) adj[i].clear();
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
