#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
const long long MOD = 1e9 + 7;
const double EPS = 1e-8;
vector<int> mp[MAX_N];
int indegree[MAX_N], ans[MAX_N];
int topo(int n) {
  int cnt = 0, res = 1;
  for (int i = 1; i <= n; i++) ans[i] = 1;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
      cnt++;
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto y : mp[x]) {
      if (indegree[y] == 0) return false;
      indegree[y]--;
      ans[y] = max(ans[y], ans[x] + (x > y));
      res = max(ans[y], res);
      if (indegree[y] == 0) {
        q.push(y);
        cnt++;
      }
    }
  }
  if (cnt < n) return -1;
  return res;
}
int main() {
  int T, n, m, x;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) mp[i].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &indegree[i]);
      for (int j = 1; j <= indegree[i]; j++) {
        scanf("%d", &x);
        mp[x].push_back(i);
      }
    }
    printf("%d\n", topo(n));
  }
  return 0;
}
