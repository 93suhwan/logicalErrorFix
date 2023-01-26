#include <bits/stdc++.h>
inline long long saisyc_min(long long a, long long b) { return a < b ? a : b; }
const int N = 10000;
int n;
long long a[N];
long long cnt;
unsigned long long ans;
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", a + i);
  for (int i = 0; i < n; ++ ++i) {
    cnt = a[i];
    for (int j = i + 1; j < n;) {
      if (cnt <= 0) break;
      if (cnt > a[i]) {
        if (a[j] > cnt - a[i]) ans += saisyc_min(a[j] - (cnt - a[i]), a[i]);
      } else
        ans += saisyc_min(cnt, a[j]);
      cnt -= a[j++], cnt += a[j++];
    }
  }
  printf("%llu", ans);
  return 0;
}
