#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[200005], r[200005], good[200005];
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
bool dfs(int u, int h, bool goodSub) {
  if (!u) return false;
  bool used = false;
  if (dfs(l[u], h + 1, goodSub)) {
    used = true;
  }
  if ((good[u] && h <= k) && !used) {
    k -= h;
    used = true;
  }
  if (used) {
    res += s[u];
    res += s[u];
  } else {
    res += s[u];
  }
  if (used && goodSub) {
    dfs(r[u], 1, goodSub);
  } else {
    dfs(r[u], k + 1, false);
  }
  return used;
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
    if (i != n - 1) {
      if (t[i] == t[i + 1])
        nxt[v[i]] = nxt[v[i + 1]];
      else
        nxt[v[i]] = t[i + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] < nxt[i]) {
      good[i] = 1;
    }
  }
  dfs(1, 1, true);
  cout << res << endl;
  return 0;
}
