#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, k;
string s, t;
vector<int> nodes;
vector<pair<int, int>> g(N), p(N);
void solveInitial(int u) {
  if (~g[u].first) solveInitial(g[u].first);
  nodes.push_back(u);
  if (~g[u].second) solveInitial(g[u].second);
}
bool solve(int u, int c, bool canDup) {
  bool dupPar = 0, ret = 0;
  if (~g[u].first) ret = solve(g[u].first, c + 1, canDup);
  t += s[u];
  if (ret)
    dupPar = 1, c = 0, t += s[u];
  else {
    if (c <= k && p[u].first > p[u].second && canDup)
      dupPar = 1, k -= c, c = 0, t += s[u];
  }
  if (!dupPar) canDup = 0;
  ret = 0;
  if (~g[u].second) ret = solve(g[u].second, c + 1, canDup);
  return dupPar;
}
void testCase() {
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++)
    cin >> g[i].first >> g[i].second, g[i].first--, g[i].second--;
  solveInitial(0);
  vector<int> v(26, 1e9);
  for (int i = nodes.size() - 1; i >= 0; i--) {
    char c = s[nodes[i]];
    int l = 1e9, r = 1e9;
    for (int j = c - 'a' + 1; j < 26; j++) r = min(r, v[j]);
    for (int j = c - 'a' - 1; j >= 0; j--) l = min(l, v[j]);
    p[nodes[i]] = {l, r};
    v[c - 'a'] = i;
  }
  solve(0, 1, 1);
  cout << t;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) testCase();
  return 0;
}
