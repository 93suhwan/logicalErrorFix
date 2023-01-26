#include <bits/stdc++.h>
int T, n;
int pos[50];
char str[50];
struct node {
  int id, d;
} a[50];
bool cmp(node a, node b) { return a.id < b.id; }
void sol() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) a[i].id = str[i] - 'a', a[i].d = i;
  std::sort(a + 1, a + n + 1, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (a[i].d != i);
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) sol();
  return 0;
}
