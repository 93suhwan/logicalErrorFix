#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 3e5 + 10;
int n, m;
int a[N];
long long tr1[M], tr2[M];
void add(long long tr[], int u, int first) {
  for (int i = u; i < M; i += i & -i) tr[i] += first;
}
long long get_sum(long long tr[], int u) {
  long long res = 0;
  for (int i = u; i; i -= i & -i) res += tr[i];
  return res;
}
long long get_range(long long tr[], int r, int l) {
  return get_sum(tr, r) - get_sum(tr, l - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long ans = 0, suma = 0;
  for (int i = 1; i <= n; i++) {
    ans += suma;
    for (int first = a[i]; first < M; first += a[i])
      ans -= get_range(tr1, M - 1, first) * a[i];
    ans += 1ll * (i - 1) * a[i];
    ans -= get_sum(tr2, a[i]);
    for (int first = a[i]; first < M; first += a[i]) add(tr2, first, a[i]);
    add(tr1, a[i], 1);
    suma += a[i];
    printf("%lld ", ans);
  }
  return 0;
}
