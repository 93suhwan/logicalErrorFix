#include <bits/stdc++.h>
using namespace std;
typedef const int& cint;
const int mod = 1e9 + 7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const long long inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;
int t, n, d;
bool vis[1001000];
bool a[1001000];
int ans[1001000];
void dfs(cint loc, int step) {
  if (vis[loc]) return;
  if (!a[loc]) step = 0;
  ans[loc] = step;
  vis[loc] = 1;
  dfs((loc + n - d) % n, step + 1);
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) vis[i] = ans[i] = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (!vis[i] && !a[i]) {
        dfs(i, 0);
      }
    }
    bool flag = 1;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] && !vis[i]) {
        flag = 0;
        break;
      }
      mx = max(mx, ans[i]);
    }
    if (!flag)
      cout << -1 << endl;
    else
      cout << mx << endl;
  }
  return 0;
}
