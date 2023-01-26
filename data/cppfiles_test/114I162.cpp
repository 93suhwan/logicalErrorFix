#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double eps = 1e-6;
int n, m;
int ed[20];
vector<int> v[20], ans, res;
map<vector<int>, int> mp;
long long all;
void dfs(int u, long long sum) {
  if (u == n + 1) {
    if (mp.count(ans)) return;
    if (sum > all) res = ans, all = sum;
    return;
  }
  for (int i = ed[u]; i <= v[u].size(); i++) {
    ans.push_back(i);
    dfs(u + 1, sum + v[u][i - 1]);
    ans.pop_back();
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int x;
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    mp[v] = 1;
  }
  if (m == 0) {
    for (int i = 1; i <= n; i++) cout << v[i].size() << ' ';
    return 0;
  }
  long long now = 1;
  for (int i = 1; i <= n; i++) ed[i] = v[i].size();
  while (now <= m) {
    long long fun = 1;
    for (int i = 1; i <= n; i++) {
      if (ed[i] != 1) ed[i]--;
      fun *= (int)v[i].size() - ed[i] + 1;
    }
    now = fun;
  }
  dfs(1, 0);
  for (auto x : res) cout << x << ' ';
  puts("");
  return 0;
}
