#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], t[maxn];
void add(int x, int v) {
  while (x < maxn) {
    t[x] += v;
    x += x & -x;
  }
}
int sum(int x) {
  int ans = 0;
  while (x) {
    ans += t[x];
    x -= x & -x;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[++tot] = a[i];
    }
    sort(b + 1, b + 1 + tot);
    tot = unique(b + 1, b + 1 + tot) - (b + 1);
    for (int i = 1; i <= n; ++i) {
      a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
    }
    int num = 0;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      int sm = sum(a[i] - 1), sm2 = i - 1 - sum(a[i]);
      ans += min(sm, sm2);
      add(a[i], 1);
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) add(a[i], -1);
  }
}
