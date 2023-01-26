#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], c[200005], len, n;
int ask(int x) {
  int ans = 0;
  for (; x; x -= (x & -x)) {
    ans += c[x];
  }
  return ans;
}
void add(int x) {
  for (; x <= n; x += x & (-x)) {
    c[x] += 1;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
      c[i] = 0;
    }
    sort(b + 1, b + n + 1);
    len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += min(ask(a[i] - 1), ask(n) - ask(a[i]));
      add(a[i]);
    }
    printf("%d\n", ans);
  }
}
