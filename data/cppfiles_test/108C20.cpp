#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, id;
} a[100010];
int n, T, ans[100010], s[100010];
bool cmp(node x, node y) { return x.a > y.a; }
bool cmp2(node x, node y) { return x.b > y.b; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].a);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].b), a[i].id = i, ans[i] = 0;
    sort(a + 1, a + n + 1, cmp);
    s[n + 1] = 0;
    for (int i = n; i >= 1; i--) s[i] = max(s[i + 1], a[i].b);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] > a[mx].b) ans[a[i].id] = 1;
      if (ans[a[i].id] && (a[i].b < a[mx].b || !mx)) mx = i;
    }
    sort(a + 1, a + n + 1, cmp2);
    mx = 0;
    s[n + 1] = 0;
    for (int i = n; i >= 1; i--) s[i] = max(s[i + 1], a[i].a);
    for (int i = 1; i <= n; i++) {
      if (s[i] > a[mx].a) ans[a[i].id] = 1;
      if (ans[a[i].id] && (a[i].a < a[mx].a || !mx)) mx = i;
    }
    for (int i = 1; i <= n; i++)
      if (ans[i])
        printf("1");
      else
        printf("0");
    puts("");
  }
  return 0;
}
