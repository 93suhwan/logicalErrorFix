#include <bits/stdc++.h>
using namespace std;
char nxt[200005];
string s;
vector<pair<int, char>> v;
int l[200005], r[200005];
int n, k;
string ans = "";
void dfs(int x) {
  if (l[x]) dfs(l[x]);
  v.push_back({x, s[x]});
  if (r[x]) dfs(r[x]);
}
bool dfs2(int x, int c, int val) {
  bool ok = 0;
  if (l[x]) ok = dfs2(l[x], c + 1, val);
  if (ok) {
    ans += s[x];
    ans += s[x];
  } else {
    if (s[x] < nxt[x]) {
      if (c + 1 <= k && val) {
        ok = 1;
        ans += s[x];
        ans += s[x];
        k -= c + 1;
      }
    }
  }
  if (!ok) ans += s[x];
  if (r[x]) {
    if (ok) {
      dfs2(r[x], 0, val);
    } else
      ok = dfs2(r[x], c + 1, 0);
  }
  return ok;
}
void solve() {
  cin >> n >> k;
  cin >> s;
  s = "." + s;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  dfs(1);
  v.push_back({n + 1, 'a' - 1});
  for (int i = n; i >= 1; i--) {
    if (v[i - 1].second != v[i].second) {
      nxt[v[i - 1].first] = v[i].second;
    } else
      nxt[v[i - 1].first] = nxt[v[i].first];
  }
  dfs2(1, 0, 1);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
