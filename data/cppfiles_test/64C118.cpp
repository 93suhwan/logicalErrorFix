#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int n, m1, m2;
int fa1[N], fa2[N];
inline int find1(int u) { return fa1[u] == u ? u : fa1[u] = find1(fa1[u]); }
inline int find2(int u) { return fa2[u] == u ? u : fa2[u] = find2(fa2[u]); }
void merge1(int u, int v) {
  int x = find1(u), y = find1(v);
  if (x != y) fa1[x] = y;
}
void merge2(int u, int v) {
  int x = find2(u), y = find2(v);
  if (x != y) fa2[x] = y;
}
bool vis[N];
int main() {
  n = read();
  m1 = read();
  m2 = read();
  for (int i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
  int u, v;
  for (int i = 1; i <= m1; i++) {
    u = read();
    v = read();
    merge1(u, v);
  }
  for (int i = 1; i <= m2; i++) {
    u = read();
    v = read();
    merge2(u, v);
  }
  vector<int> ans1, ans2;
  for (int i = 1; i <= 1; i++)
    for (int j = 2; j <= n; j++) {
      int x1 = find1(i), y1 = find1(j);
      int x2 = find2(i), y2 = find2(j);
      if (x1 != y1 && x2 != y2) {
        ans1.push_back(i);
        ans2.push_back(j);
        fa1[x1] = y1;
        fa2[x2] = y2;
        vis[j] = 1;
      }
    }
  for (int i = 1; i <= 1; i++)
    for (int j = 2; j <= n; j++) {
      if (vis[j]) continue;
      int x1 = find1(i), y1 = find1(j);
      if (x1 != y1) {
        ans1.push_back(j);
        fa1[x1] = y1;
      }
      int x2 = find2(i), y2 = find2(j);
      if (x2 != y2) {
        ans2.push_back(j);
        fa2[x2] = y2;
      }
    }
  int sz = min(ans1.size(), ans2.size());
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) printf("%d %d\n", ans1[i], ans2[i]);
  return 0;
}
