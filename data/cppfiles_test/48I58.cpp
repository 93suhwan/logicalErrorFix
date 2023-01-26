#include <bits/stdc++.h>
using namespace std;
int t, n, a[500010];
int c[500010];
void update(int x) {
  for (; x <= n; x += x & -x) c[x]++;
}
int query(int x) {
  int ans = 0;
  for (; x >= 1; x -= x & -x) ans += c[x];
  return ans;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[i] = 0;
    for (int i = n; i >= 1; i--) ans += query(a[i] - 1), update(a[i]);
    if (ans % 2 == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
