#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct fenwick {
  long long c[N];
  void add(int i, int v) {
    for (; i < N; i += i & -i) {
      c[i] += v;
    }
  }
  long long qry(int i) {
    long long re = 0;
    for (; i > 0; i -= i & -i) {
      re += c[i];
    }
    return re;
  }
} fw[2];
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans += sum;
    ans += 1ll * (i - 1) * a[i];
    for (int j = a[i]; j < N; j += a[i]) {
      int cnt = fw[0].qry(min(N - 1, j + a[i] - 1)) - fw[0].qry(j - 1);
      ans -= 1ll * cnt * j;
    }
    fw[0].add(a[i], 1);
    ans -= fw[1].qry(a[i]);
    for (int j = a[i]; j < N; j += a[i]) {
      fw[1].add(j, j);
      fw[1].add(j + a[i], -j);
    }
    sum += a[i];
    printf("%lld ", ans);
  }
  return 0;
}
