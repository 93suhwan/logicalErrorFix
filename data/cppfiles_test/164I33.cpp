#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, k;
string s;
vector<int> nodes, d(N);
vector<pair<int, int>> g(N), p(N);
string solveInitial(int u, int l) {
  d[u] = l;
  string t;
  if (~g[u].first) t += solveInitial(g[u].first, l + 1);
  t += s[u];
  nodes.push_back(u);
  if (~g[u].second) t += solveInitial(g[u].second, l + 1);
  return t;
}
pair<string, bool> solve(int u, int l, char c) {
  string t;
  bool dupPar = 0;
  pair<string, bool> ret = {"", 0};
  if (~g[u].first) ret = solve(g[u].first, l, c);
  t += ret.first;
  t += s[u];
  if (ret.second)
    t += s[u], dupPar = 1, l = u, c = 'a';
  else {
    if (c <= s[u] && ~p[u].second &&
        p[u].second < (~p[u].first ? p[u].first : INT_MAX) &&
        d[u] + 1 - (~l ? d[l] + 1 : 0) <= k) {
      k -= d[u] + 1 - (~l ? d[l] + 1 : 0);
      t += s[u], dupPar = 1, l = u, c = 'a';
    }
  }
  ret = {"", 0};
  if (!dupPar) c = max(c, s[u]);
  if (~g[u].second) ret = solve(g[u].second, l, c);
  if (!dupPar && ret.second) t += s[u], dupPar = 1;
  t += ret.first;
  return {t, dupPar};
}
void testCase() {
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++)
    cin >> g[i].first >> g[i].second, g[i].first--, g[i].second--;
  string t = solveInitial(0, 0);
  vector<int> v(26, -1);
  for (int i = t.size() - 1; i >= 0; i--) {
    int x = INT_MAX, y = INT_MAX;
    for (int j = t[i] - 'a' + 1; j < 26; j++) {
      if (~v[j]) y = min(y, v[j]);
    }
    for (int j = t[i] - 'a' - 1; j >= 0; j--) {
      if (~v[j]) x = min(x, v[j]);
    }
    x = (x == INT_MAX ? -1 : x);
    y = (y == INT_MAX ? -1 : y);
    if (!~v[t[i] - 'a']) v[t[i] - 'a'] = INT_MAX;
    v[t[i] - 'a'] = min(v[t[i] - 'a'], i);
    p[nodes[i]] = {x, y};
  }
  cout << solve(0, -1, 'a').first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) testCase();
  return 0;
}
