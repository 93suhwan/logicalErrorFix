#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[200005], r[200005];
char m[200005], nxt[200005];
string s, t;
string res;
vector<int> v;
void dfs1(int u) {
  if (!u) return;
  dfs1(l[u]);
  t += s[u];
  v.push_back(u);
  dfs1(r[u]);
}
void dfs(int u, int h) {
  int k0 = k;
  if (l[u]) {
    dfs(l[u], h - 1);
  }
  bool smaller = false;
  if (nxt[u] && (s[u] < nxt[u] || (s[u] == nxt[u] && s[u] < m[u]))) {
    smaller = true;
  }
  if (h > 0 && (k != k0 || smaller)) {
    k--;
    res += s[u];
    res += s[u];
  } else {
    res += s[u];
  }
  if (r[u]) {
    if (smaller)
      dfs(r[u], k);
    else
      dfs(r[u], 0);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  cin >> s;
  s = '#' + s;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  dfs1(1);
  char cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    m[v[i]] = cur;
    cur = max(cur, t[i]);
    if (i != n - 1) nxt[v[i]] = t[i + 1];
  }
  dfs(1, k);
  cout << res << endl;
  return 0;
}
