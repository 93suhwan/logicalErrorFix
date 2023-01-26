#include <bits/stdc++.h>
using namespace std;
vector<int> edge[300005];
bool visit[300005];
int dfs(int n) {
  int ck = 1;
  visit[n] = 1;
  for (auto it : edge[n]) {
    if (visit[it] == 0) ck += dfs(it);
  }
  return ck;
}
void solve() {
  int n;
  int m;
  scanf("%d%d", &n, &m);
  int a[n + 2], b[n + 1];
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    int a1;
    scanf("%d", &a1);
    b[i] = a1;
    int x = n - (a1 - i);
    if (x >= n) x -= n;
    a[x]++;
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x = n - a[i];
    if (x <= 2 * m) {
      v.push_back(i);
    }
  }
  vector<int> ans;
  for (auto it : v) {
    int k = it;
    int ok = 0;
    int per[n + 2];
    for (int i = 0; i < n; i++) {
      int x = (i - k + n) % n + 1;
      per[x] = i + 1;
    }
    for (int i = 1; i <= n; i++) {
      int x = b[i];
      edge[x].push_back(b[per[x]]);
    }
    for (int i = 1; i <= n; i++) {
      ok += dfs(i) - 1;
    }
    for (int i = 1; i <= n; i++) {
      edge[i].clear();
      visit[i] = 0;
    }
    if (ok <= m) ans.push_back(k);
  }
  cout << ans.size();
  for (auto it : ans) {
    cout << " " << it;
  }
  cout << "\n";
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
