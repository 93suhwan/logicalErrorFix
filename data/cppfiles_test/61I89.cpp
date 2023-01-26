#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int T, n, m;
long long a[MAXN];
map<int, int> cnt[MAXN];
int cnt1[MAXN], cnt2[MAXN];
long long C3(long long a) { return a * (a - 1) * (a - 2) / 6; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cnt[i].clear(), cnt1[i] = cnt2[i] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      ans += cnt2[b] * (i - 1 - cnt2[b]) + cnt1[a] * (i - 1 - cnt1[a]);
      ans -= cnt[a][b] * (i - 1 - cnt[a][b]) +
             (cnt1[a] - cnt[a][b]) * (cnt2[b] - cnt[a][b]);
      cnt[a][b]++;
      cnt1[a]++;
      cnt2[b]++;
    }
    for (int i = 1; i <= n; i++) ans += C3(cnt1[i]) + C3(cnt2[i]);
    for (int i = 1; i <= n; i++)
      for (auto j : cnt[i]) ans += C3(j.second);
    printf("%lld\n", C3(n) - ans);
  }
  return 0;
}
