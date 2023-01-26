#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, d, ans;
struct node {
  int a, b;
} a[N];
bool cmp(node x, node y) {
  if (max(x.a, x.b) != max(y.a, y.b)) return max(x.a, x.b) < max(y.a, y.b);
  if (x.a != y.a) return x.a < y.a;
  return x.b < y.b;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++)
    if (a[i].a >= d) ans++, d = max(d, a[i].b);
  cout << ans;
}
