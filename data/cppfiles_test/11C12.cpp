#include <bits/stdc++.h>
using namespace std;
const int Max_N = 2e5, Inf = 1e9;
int n, P[Max_N * 2 + 5];
struct kk {
  int val, pos;
} a[Max_N + 5];
bool mycmp(kk x, kk y) {
  return x.val == y.val ? x.pos > y.pos : x.val < y.val;
}
int Ask(int x) {
  int ans = -Inf;
  for (x += n; x <= 2 * n; x += x & -x) ans = max(ans, P[x]);
  return ans;
}
void Add(int x, int val) {
  for (x += n; x; x -= x & -x) P[x] = max(P[x], val);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].val), a[i].pos = i;
  sort(a + 1, a + n + 1, mycmp);
  for (int i = 0; i <= 2 * n; i++) P[i] = -Inf;
  Add(0, 0);
  for (int i = 1; i <= n; i++) {
    int now = Ask(a[i].val - a[i].pos) + 1;
    Add(a[i].val - a[i].pos, now);
  }
  printf("%d\n", Ask(-n + 1));
  return 0;
}
