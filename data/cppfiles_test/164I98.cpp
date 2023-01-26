#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod = 998244353;
int n, k, cnt;
vector<pair<int, int>> ch;
vector<int> f, good;
string s;
string dfs1(int u) {
  string ret;
  if (ch[u].first != -1) ret += dfs1(ch[u].first);
  f[cnt++] = u;
  ret += s[u];
  if (ch[u].second != -1) ret += dfs1(ch[u].second);
  return ret;
}
pair<string, int> dfs(int u, int k) {
  pair<string, int> ret;
  ret.second = 0;
  bool added = 0;
  if (ch[u].first != -1) {
    auto l = dfs(ch[u].first, k - 1);
    ret.first = l.first;
    if (l.second)
      ret.second = l.second, added = 1;
    else
      ret.second = 0;
  }
  if (k > 0) {
    if (good[u] || ret.second) {
      ret.first += s[u];
      added = 1;
    } else
      ret.first += s[u];
  } else
    ret.first += s[u];
  if (ch[u].second != -1) {
    auto r = dfs(ch[u].second, k - ret.second - 1);
    if (added) ret.second++, ret.first += s[u];
    if (added) {
      ret.second += r.second;
      ret.first += r.first;
    } else {
      ret.first += dfs1(ch[u].second);
    }
  } else {
    if (added) ret.second++, ret.first += s[u];
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
  cout << dfs(0, k).first;
}
