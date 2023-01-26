#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[200005], r[200005];
char m[200005];
string s;
string res;
void dfs1(int u) {
  m[u] = s[u];
  if (l[u]) {
    dfs1(l[u]);
    m[u] = max(m[u], m[l[u]]);
  }
  if (r[u]) {
    dfs1(r[u]);
    m[u] = max(m[u], m[r[u]]);
  }
}
void dfs(int u, int h) {
  int k0 = k;
  if (l[u]) {
    dfs(l[u], h - 1);
  }
  bool smaller = false;
  if (r[u] && (s[u] < s[r[u]] || (s[u] == s[r[u]] && s[u] < m[r[u]]))) {
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
  dfs(1, k);
  cout << res << endl;
  return 0;
}
