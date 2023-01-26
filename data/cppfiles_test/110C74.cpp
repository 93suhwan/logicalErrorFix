#include <bits/stdc++.h>
using namespace std;
int n;
int head[200010], next_edge[200010], to[200010];
int sumedge;
void add_edge(int s, int t) {
  next_edge[sumedge] = head[s];
  head[s] = sumedge;
  to[sumedge] = t;
  sumedge++;
}
int visited[200010];
int instack[200010];
bool dfs(int x) {
  if (instack[x]) return false;
  if (visited[x]) return true;
  instack[x] = true;
  visited[x] = true;
  for (int e = head[x]; e != -1; e = next_edge[e]) {
    if (!dfs(to[e])) return false;
  }
  instack[x] = false;
  return true;
}
bool check_valid() {
  memset(visited, 0, sizeof(visited));
  memset(instack, 0, sizeof(instack));
  for (int i = 0; i < n; i++) {
    if (!dfs(i)) return false;
  }
  return true;
}
int maxLength[200010];
int getMaxLength(int x) {
  if (maxLength[x] != -1) return maxLength[x];
  maxLength[x] = 0;
  for (int i = head[x]; ~i; i = next_edge[i])
    maxLength[x] = max(maxLength[x], getMaxLength(to[i]) + (int)(to[i] > x));
  return maxLength[x];
}
void solve() {
  memset(head, -1, sizeof(head));
  sumedge = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k, t;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &t);
      add_edge(i, t - 1);
    }
  }
  if (check_valid()) {
    int ans = 0;
    memset(maxLength, -1, sizeof(maxLength));
    for (int i = 0; i < n; i++) ans = max(ans, getMaxLength(i));
    cout << ans + 1 << endl;
  } else
    cout << -1 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
