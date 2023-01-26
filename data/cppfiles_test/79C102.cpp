#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, cnt, p;
int fs[MAXN];
int a[MAXN], b[MAXN];
int dep[MAXN];
queue<int> q;
stack<int> sk;
set<int> flag;
bool bfs() {
  q.push(n);
  while (!q.empty()) {
    int u = q.front(), x = u + b[u];
    q.pop();
    if (x - a[x] <= 0) return fs[0] = u, 1;
    while (1) {
      int v = *flag.lower_bound(x - a[x]);
      if (v >= u) break;
      flag.erase(v);
      fs[v] = u, q.push(v);
    }
  }
  return 0;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) fs[i] = i, flag.insert(i);
  if (bfs()) {
    while (fs[p] != p) {
      sk.push(p);
      p = fs[p];
      cnt++;
    }
    printf("%d\n", cnt);
    while (!sk.empty()) {
      printf("%d ", sk.top());
      sk.pop();
    }
  } else
    puts("-1");
  return 0;
}
