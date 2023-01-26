#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long mod = 998244353;
int n, k, cnt;
vector<pair<int, int>> ch;
vector<int> f, good, add;
string s;
inline void dfs1(const int &u) {
  if (ch[u].first != -1) dfs1(ch[u].first);
  f[cnt++] = u;
  if (ch[u].second != -1) dfs1(ch[u].second);
}
int dfs(int u, int k) {
  int ret = 0;
  bool added = 0;
  if (ch[u].first != -1) {
    int l = dfs(ch[u].first, k - 1);
    ret += l;
    if (l) added = 1;
  }
  if (k > 0 && good[u]) added = 1;
  if (added) ret++, add[u] = 1;
  if (ch[u].second != -1) {
    int r;
    if (added)
      r = dfs(ch[u].second, k - ret);
    else
      r = dfs(ch[u].second, 0);
    ret += r;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  ch.resize(n);
  f.resize(n);
  good.resize(n);
  add.resize(n);
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> ch[i].first >> ch[i].second;
    ch[i].first--;
    ch[i].second--;
  }
  dfs1(0);
  for (int i = n - 2; i >= 0; i--) {
    if (s[f[i]] == s[f[i + 1]])
      good[f[i]] = good[f[i + 1]];
    else if (s[f[i]] < s[f[i + 1]])
      good[f[i]] = 1;
    else
      good[f[i]] = 0;
  }
  dfs(0, k);
  string ans;
  for (int i = 0; i < n; i++) {
    ans += s[f[i]];
    if (add[f[i]]) ans += s[f[i]];
  }
  cout << ans;
}
