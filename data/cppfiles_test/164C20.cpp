#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long __gcd(long long a, long long b) {
  return b == 0 ? a : __gcd(b, a % b);
}
typedef pair<pair<int, int>, int> III;
int par[1 << 18][18];
void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> l(n), r(n);
  par[0][0] = -1;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    if (l[i] >= 0) par[l[i]][0] = i;
    if (r[i] >= 0) par[r[i]][0] = i;
  }
  for (int j = 0; j < 17; j++) {
    for (int i = 0; i < n; i++) {
      if (par[i][j] < 0)
        par[i][j + 1] = -1;
      else
        par[i][j + 1] = par[par[i][j]][j];
    }
  }
  vector<int> ids;
  function<void(int)> dfs = [&](int id) {
    if (l[id] >= 0) dfs(l[id]);
    ids.push_back(id);
    if (r[id] >= 0) dfs(r[id]);
  };
  dfs(0);
  vector<bool> b(n);
  for (int i = 0; i < n; i++) {
    int le = i;
    while (i + 1 < n && s[ids[i]] == s[ids[i + 1]]) i++;
    if (i + 1 == n || s[ids[i + 1]] < s[ids[i]]) {
      for (int j = le; j <= i; j++) b[ids[j]] = true;
    }
  }
  vector<bool> used(n);
  string ans;
  function<void(int)> dfs3 = [&](int id) {
    if (l[id] >= 0) dfs3(l[id]);
    ans.push_back(s[id]);
    if (r[id] >= 0) dfs3(r[id]);
  };
  function<void(int)> dfs2 = [&](int id) {
    if (l[id] >= 0) dfs2(l[id]);
    if (!used[id]) {
      if (!b[id]) {
        int cur = id;
        int ad = 1;
        for (int j = 17; j >= 0; j--) {
          int p = par[cur][j];
          if (p >= 0 && !used[p]) {
            ad += (1 << j);
            cur = p;
          }
        }
        if (ad <= k) {
          k -= ad;
          cur = id;
          while (cur >= 0 && !used[cur]) {
            used[cur] = true;
            cur = par[cur][0];
          }
        }
      }
    }
    if (used[id]) {
      ans.push_back(s[id]);
      ans.push_back(s[id]);
      if (r[id] >= 0) dfs2(r[id]);
    } else {
      ans.push_back(s[id]);
      if (r[id] >= 0) dfs3(r[id]);
    }
  };
  dfs2(0);
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
