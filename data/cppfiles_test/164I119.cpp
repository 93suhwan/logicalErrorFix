#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, k;
string s;
vector<int> nodes;
vector<pair<int, int>> g(N), p(N);
string solveInitial(int u) {
  string t;
  if (~g[u].first) t += solveInitial(g[u].first);
  t += s[u];
  nodes.push_back(u);
  if (~g[u].second) t += solveInitial(g[u].second);
  return t;
}
pair<string, bool> solve(int u, int c, int canDup) {
  string t;
  bool dupPar = 0;
  pair<string, bool> ret = {"", 0};
  if (~g[u].first) ret = solve(g[u].first, c + 1, canDup);
  t += ret.first, t += s[u];
  if (ret.second)
    dupPar = 1;
  else {
    if (c <= k && p[u].first > p[u].second) dupPar = 1;
  }
  if (dupPar && canDup)
    t += s[u], k -= c, c = 0;
  else
    canDup = 0;
  ret = {"", 0};
  if (~g[u].second) ret = solve(g[u].second, c + 1, canDup);
  t += ret.first;
  return {t, dupPar};
}
void testCase() {
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++)
    cin >> g[i].first >> g[i].second, g[i].first--, g[i].second--;
  string t = solveInitial(0);
  vector<int> v(26, -1);
  for (int i = t.size() - 1; i >= 0; i--) {
    int l = 1e9, r = 1e9;
    for (int j = t[i] - 'a' + 1; j < 26; j++) {
      if (~v[j]) r = min(r, v[j]);
    }
    for (int j = t[i] - 'a' - 1; j >= 0; j--) {
      if (~v[j]) l = min(l, v[j]);
    }
    p[nodes[i]] = {l, r};
    v[t[i] - 'a'] = i;
  }
  cout << solve(0, 1, 1).first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) testCase();
  return 0;
}
