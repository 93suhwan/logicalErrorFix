#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int p[300009];
int cor[300009];
int idxshift[300009];
bool vis[300009];
bool solve(int shift) {
  for (int i = 1; i <= n; i++) {
    cor[i] = (i - shift) % n;
    if (cor[i] <= 0) cor[i] += n;
  }
  memset(vis, 0, sizeof(bool) * (n + 5));
  vector<int> from, to;
  for (int i = 1; i <= n; i++) {
    if (cor[i] != p[i]) {
      from.push_back(p[i]);
      to.push_back(cor[i]);
    }
  }
  map<int, int> mm;
  int si = from.size();
  for (int i = 0; i < si; i++) {
    mm[from[i]] = i;
  }
  for (int i = 0; i < si; i++) {
    from[i] = mm[from[i]];
    to[i] = mm[to[i]];
  }
  bool vis[si + 5];
  memset(vis, 0, sizeof(vis));
  int mcnt = si;
  for (int i = 0; i < si; i++) {
    if (vis[i] == false) {
      mcnt--;
      int par = i;
      int cur = to[i];
      while (cur != par) {
        vis[cur] = true;
        cur = to[cur];
      }
      vis[i] = true;
    }
  }
  if (mcnt <= m)
    return true;
  else
    return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    vector<int> ans1;
    vector<int> ans2;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &p[i]);
      idxshift[(i - p[i] + n) % n]++;
    }
    for (int i = 0; i < n; i++) {
      if (idxshift[i] >= n - 2 * m) {
        ans1.push_back(i);
      }
    }
    for (int i = 0; i < ans1.size(); i++) {
      if (solve(ans1[i])) {
        ans2.push_back(ans1[i]);
      }
    }
    printf("%d ", ans2.size());
    for (int i = 0; i < ans2.size(); i++) printf("%d ", ans2[i]);
    printf("\n");
    memset(idxshift, 0, sizeof(int) * (n + 5));
  }
}
