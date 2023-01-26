#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
int T, n, ans[N], deg[N];
vector<int> v[N];
queue<int> q;
int cnt[N];
bool check(int val) {
  for (int i = 0; i < n; i++) deg[i] = v[i].size(), cnt[i] = 0;
  for (int i = 0; i < n; i++)
    if (deg[i] == 1) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    deg[now] = 0;
    bool ok = false;
    int rem;
    for (int i = 0; i < v[now].size(); i++) {
      int to = v[now][i];
      if (deg[to]) {
        ok = true;
        rem = to;
        deg[to]--;
        if (deg[to] == 1) q.push(to);
      }
    }
    if (ok) {
      if (cnt[now] % val == 0)
        cnt[rem]++;
      else if ((cnt[now] + 1) % val == 0)
        cnt[now]++;
      else
        return false;
    } else if (cnt[now] % val != 0)
      return false;
  }
  return true;
}
void solve() {
  cin >> n;
  ans[n] = 0;
  for (int i = 0; i < n; i++) v[i].clear();
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ans[1] = 1;
  for (int i = 1; i < n; i++) ans[1] = 1ll * ans[1] * 2 % mod;
  for (int i = 2; i <= n - 1; i++) {
    ans[i] = check(i), ans[1] = (ans[1] - ans[i] + mod) % mod;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
  return;
}
int main() {
  cin >> T;
  while (T--) solve();
  return 0;
}
