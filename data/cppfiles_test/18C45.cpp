#include <bits/stdc++.h>
using namespace std;
const int N = 2.1e6, mod = 998244353;
int a[N], n, d;
int f[N];
bool vis[N];
int work() {
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (a[i] == 0)
      f[i] = 0, q.push(i);
    else
      f[i] = 1e9;
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    int to = (i + d) % n;
    if (a[to] == 1) a[to] = 0, f[to] = f[i] + 1, q.push(to);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, f[i]);
  if (ans < 1e9)
    printf("%d\n", ans);
  else
    puts("-1");
  return 0;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) work();
  return 0;
}
