#include <bits/stdc++.h>
using namespace std;
const int Max_N = 2e5;
int n, a[Max_N + 5], P[Max_N + 5];
int Ask(int x) {
  int ans = 0;
  for (++x; x; x -= x & -x) ans = max(ans, P[x]);
  return ans;
}
void Add(int x, int val) {
  for (++x; x <= n; x += x & -x) P[x] = max(P[x], val);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) a[i] -= i;
  for (int i = 1; i <= n; i++)
    if (a[i] <= 0) {
      int now = Ask(-a[i] - 1) + 1;
      Add(-a[i], now);
    }
  printf("%d\n", Ask(n - 1));
  return 0;
}
