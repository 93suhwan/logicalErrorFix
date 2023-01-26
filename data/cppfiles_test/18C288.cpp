#include <bits/stdc++.h>
using namespace std;
int T, s, n, k, tc, ans, cnt, st[10005], en[10005], v[10005];
pair<int, int> e[10];
int main() {
  int i, j, w;
  cin >> T;
  for (tc = 1; tc <= T; tc++) {
    scanf("%d %d", &n, &k);
    for (i = 0; i < k; i++) {
      scanf("%d %d", &st[i], &en[i]);
      if (st[i] > en[i]) swap(st[i], en[i]);
      v[st[i]] = tc;
      v[en[i]] = tc;
    }
    cnt = 0;
    for (i = 1; i <= n * 2; i++) {
      if (v[i] != tc) {
        cnt++;
        if (cnt <= n - k)
          st[k + cnt - 1] = i;
        else
          en[k + cnt - (n - k) - 1] = i;
      }
    }
    ans = 0;
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        e[0].first = st[i];
        e[0].second = 0;
        e[1].first = en[i];
        e[1].second = 0;
        e[2].first = st[j];
        e[2].second = 1;
        e[3].first = en[j];
        e[3].second = 1;
        sort(e, e + 4);
        if (e[0].second == e[2].second) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
