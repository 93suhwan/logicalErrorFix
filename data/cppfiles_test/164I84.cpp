#include <bits/stdc++.h>
using namespace std;
int n, k;
char c[200010];
int l[200010];
int r[200010];
char d[200010];
int ind[200010];
int nxt[200010];
bool needa[200010];
const int LOG = 20;
int bu[LOG][200010];
bool chosen[200010];
int minbad[200010];
int pos[200010];
int x = 1;
void dfs(int u) {
  if (!u) return;
  dfs(l[u]);
  pos[u] = x;
  d[x] = c[u];
  ind[x] = u;
  ++x;
  dfs(r[u]);
}
void dfs2(int u) {
  if (!u) return;
  if (l[u]) {
    bu[0][l[u]] = u;
    minbad[l[u]] = minbad[u];
    if (!needa[pos[u]]) {
      minbad[l[u]] = min(minbad[l[u]], pos[u]);
    }
    dfs2(l[u]);
  }
  if (r[u]) {
    bu[0][r[u]] = u;
    minbad[r[u]] = minbad[u];
    if (!needa[pos[u]]) {
      minbad[r[u]] = min(minbad[r[u]], pos[u]);
    }
    dfs2(r[u]);
  }
}
vector<int> wanna;
int notcol(int u) {
  int ans = 1;
  for (int i = LOG - 1; i >= 0; --i) {
    if (bu[i][u] && !chosen[bu[i][u]]) {
      ans += 1 << i;
      u = bu[i][u];
    }
  }
  return ans;
}
void print(int u) {
  if (!u) return;
  print(l[u]);
  cout << (chosen[u] ? string(2, c[u]) : string(1, c[u]));
  print(r[u]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }
  minbad[1] = 1e9;
  dfs(1);
  for (int i = n; i >= 1; --i) {
    if (d[i] != d[i + 1])
      nxt[i] = i + 1;
    else
      nxt[i] = nxt[i + 1];
    needa[i] = d[nxt[i]] > d[i];
    if (needa[i]) wanna.push_back(ind[i]);
  }
  dfs2(1);
  reverse(wanna.begin(), wanna.end());
  for (int i = 1; i < LOG; ++i) {
    for (int j = 1; j <= n; ++j) {
      bu[i][j] = bu[i - 1][bu[i - 1][j]];
    }
  }
  for (auto i : wanna) {
    int position = pos[i];
    int pre = minbad[i];
    if (pre < position) continue;
    int needk = notcol(i);
    if (needk > k) continue;
    k -= needk;
    int j = i;
    while (true) {
      chosen[j] = true;
      if (j == 1) break;
      if (chosen[bu[0][j]]) break;
      j = bu[0][j];
    }
  }
  print(1);
  return 0;
}
