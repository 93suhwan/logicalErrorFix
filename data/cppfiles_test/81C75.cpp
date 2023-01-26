#include <bits/stdc++.h>
using namespace std;
struct node {
  int s, a;
} a[500000 + 5];
bool cmp(node A, node B) {
  if (max(A.s, A.a) != max(B.s, B.a)) return max(A.s, A.a) < max(B.s, B.a);
  return A.s < B.s;
}
int main() {
  int n, d, i, j;
  scanf("%d%d", &n, &d);
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].s, &a[i].a);
  sort(a + 1, a + n + 1, cmp);
  int ans = 0;
  for (i = 1; i <= n; i++)
    if (d <= a[i].s) d = max(d, a[i].a), ans++;
  ;
  printf("%d\n", ans);
}
