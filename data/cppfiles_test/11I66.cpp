#include <bits/stdc++.h>
using namespace std;
const int Max_N = 2e5;
int n, a[Max_N + 5], P[Max_N * 2 + 5];
int Ask(int x) {
  int ans = 0;
  for (x += n; x; x -= x & -x) ans = max(ans, P[x]);
  return ans;
}
void Add(int x, int val) {
  for (x += n; x <= 2 * n; x += x & -x) P[x] = max(P[x], val);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int now = Ask(a[i] - i) + 1;
    Add(a[i] - i, now);
  }
  printf("%d\n", Ask(n));
  return 0;
}
