#include <bits/stdc++.h>
using namespace std;
vector<int> o;
vector<pair<int, int>> v;
void dfs(int u) {
  if (v[u].first != 0) dfs(v[u].first);
  o.push_back(u);
  if (v[u].second != 0) dfs(v[u].second);
}
bool dup[100008];
bool rdup[100008];
int k;
bool dfs2(int u, int d) {
  bool l, r, ret = 0;
  if (v[u].first != 0) l = dfs2(v[u].first, d + 1);
  if (l == 1) {
    rdup[u] = 1;
    if (v[u].second != 0) r = dfs2(v[u].second, 1);
    ret = 1;
  } else {
    if (dup[u] == 1 && d <= k) {
      k -= d;
      rdup[u] = 1;
      ret = 1;
      if (v[u].second != 0) r = dfs2(v[u].second, 1);
    }
  }
  return ret;
}
int main() {
  int n;
  cin >> n >> k;
  string second;
  cin >> second;
  int l, r;
  v.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    v.push_back({l, r});
  }
  dfs(1);
  for (int i = n - 2; i >= 0; i--) {
    if (second[o[i] - 1] < second[o[i + 1] - 1]) {
      dup[o[i]] = 1;
    } else if (second[o[i] - 1] == second[o[i + 1] - 1] && dup[o[i + 1]] == 1) {
      dup[o[i]] = 1;
    }
  }
  dfs2(1, 1);
  for (int i = 0; i < n; i++) {
    cout << second[o[i] - 1];
    if (rdup[o[i]] == 1) {
      cout << second[o[i] - 1];
    }
  }
  cout << endl;
  return 0;
}
