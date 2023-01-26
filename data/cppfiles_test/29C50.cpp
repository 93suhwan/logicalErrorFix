#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int n;
long long ans = 0;
long long T1[N + 5];
long long T2[N + 5];
long long T3[N + 5];
void upd(long long *T, int x, int v) {
  while (x <= N) {
    T[x] += v, x += x & (-x);
  }
}
long long qry(long long *T, int x) {
  long long ret = 0;
  while (x > 0) ret += T[x], x -= x & (-x);
  return ret;
}
long long query(long long *T, int l, int r) {
  r = min(r, N);
  return qry(T, r) - qry(T, l - 1);
}
void update(int num, int th) {
  for (int i = 0; i * num <= N; ++i) {
    ans += query(T1, i * num, (i + 1) * num - 1) -
           query(T2, i * num, (i + 1) * num - 1) * i * num;
  }
  ans += 1ll * num * (th - 1) - query(T3, 1, num);
  upd(T1, num, num);
  upd(T2, num, 1);
  for (int i = num; i <= N; i += num) {
    upd(T3, i, num);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int num;
    scanf("%d", &num);
    update(num, i);
    printf("%lld ", ans);
  }
  return 0;
}
