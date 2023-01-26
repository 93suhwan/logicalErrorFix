#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long Inf = 1e18;
int T, n, cnt[2];
long long ans;
int a[maxn];
int main() {
  scanf("%d", &T);
  while (T--) {
    cnt[0] = cnt[1] = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      a[i] &= 1;
      cnt[a[i]]++;
    }
    if (abs(cnt[0] - cnt[1]) > 1) {
      puts("-1");
      continue;
    }
    ans = Inf;
    for (int f = 0; f < 2; f++)
      if (cnt[f] >= cnt[f ^ 1]) {
        long long cans = 0;
        int j = f;
        for (int i = 0; i < n; i++)
          if (a[i] == 0) {
            cans += abs(i - j);
            j += 2;
          }
        ans = min(ans, cans);
      }
    printf("%lld\n", ans);
  }
  return 0;
}
