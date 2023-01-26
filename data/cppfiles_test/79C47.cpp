#include <bits/stdc++.h>
using namespace std;
int vis[300010], inf, pre[300010], a[300010], b[300010], n, d[300010];
vector<int> ans;
queue<int> q;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  q.push(n);
  vis[n] = 1;
  int tmp = n;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x - a[x] >= tmp) continue;
    for (int i = x - a[x]; i <= x; i++) {
      int t = i + b[i];
      if (!vis[t]) {
        vis[t] = 1;
        q.push(t);
        pre[t] = x;
        d[t] = i;
      }
    }
    tmp = min(tmp, x - a[x]);
  }
  if (!vis[0]) {
    cout << "-1";
    return 0;
  }
  tmp = 0;
  while (pre[tmp]) {
    ans.push_back(d[tmp]);
    tmp = pre[tmp];
  }
  tmp = ans.size();
  printf("%d\n", tmp);
  for (int i = tmp - 1; i >= 0; i--) printf("%d ", ans[i]);
  return 0;
}
