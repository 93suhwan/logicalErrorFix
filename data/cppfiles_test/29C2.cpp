#include <bits/stdc++.h>
using namespace std;
long long a[200005];
struct BIT {
  long long tree[300005 << 1], Max = 6e5;
  void add(int x, long long d) {
    for (; x <= Max; x += x & -x) tree[x] += d;
  }
  long long ask(int x) {
    long long sum = 0;
    for (; x; x -= x & -x) sum += tree[x];
    return sum;
  }
  long long query(int l, int r) { return ask(r) - ask(l - 1); }
} T1, T2;
int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    for (int j = a[i]; j <= 300005; j += a[i]) {
      ans += 1ll * j * T1.query(j, j + a[i] - 1);
      T2.add(j, a[i]);
    }
    ans += T2.ask(a[i]);
    T1.add(a[i], 1);
    printf("%lld ", 1ll * sum * i - ans);
  }
  return 0;
}
