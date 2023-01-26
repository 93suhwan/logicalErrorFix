#include <bits/stdc++.h>
int const maxn = 100003;
int const V = 1 << 9, inf = 0x3f3f3f3f;
int n = 0;
int a[maxn];
bool f[V];
int minPos[V];
inline int min(int a, int b) { return a < b ? a : b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < V; ++i) minPos[i] = inf;
  minPos[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < V; ++j) f[j] = (minPos[j ^ a[i]] < a[i]);
    for (int j = 0; j < V; ++j)
      if (f[j]) minPos[j] = min(minPos[j], a[i]);
  }
  int k = 0;
  for (int i = 0; i < V; ++i)
    if (minPos[i] != inf) ++k;
  printf("%d\n", k);
  for (int i = 0; i < V; ++i)
    if (minPos[i] != inf) printf("%d ", i);
  return 0;
}
