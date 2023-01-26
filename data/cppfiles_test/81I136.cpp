#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  char o, f = 1;
  while (o = getchar(), o < 48)
    if (o == 45) f = -f;
  do x = (x << 3) + (x << 1) + (o ^ 48);
  while (o = getchar(), o > 47);
  return x * f;
}
const int maxn = 3e5 + 5;
const long long mod = 998244353;
int _, n, q, a[maxn], pre[maxn], l, r;
char s[maxn];
vector<int> v[1000005], v2[1000005];
int main() {
  for (scanf("%d", &_); _; _--) {
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
    }
    int now = 0, now2 = 0;
    for (int i = n; i >= 1; i--) {
      v[maxn + now - (i % 2 ? 1 : -1) * a[i]].push_back(i);
      now -= (i % 2 ? 1 : -1) * a[i] * 2;
      v2[maxn + now2 - (i % 2 ? -1 : 1) * a[i]].push_back(i);
      now2 -= (i % 2 ? -1 : 1) * a[i] * 2;
    }
    for (int i = 1; i <= n; i++) {
      pre[i] = pre[i - 1] + a[i] * (i % 2 ? 1 : -1);
    }
    while (q--) {
      scanf("%d%d", &l, &r);
      int sum = pre[r] - pre[l - 1];
      if (sum == 0) {
        puts("0");
        continue;
      }
      if (l % 2 == 0) {
        sum = -sum;
        int les = pre[n] - pre[r];
        les = -les;
        int pos = lower_bound(v2[maxn - (sum + 2 * les)].begin(),
                              v2[maxn - (sum + 2 * les)].end(), l) -
                  v2[maxn - (sum + 2 * les)].begin();
        if (pos < v2[maxn - (sum + 2 * les)].size() &&
            v2[maxn - (sum + 2 * les)][pos] <= r) {
          puts("1");
        } else
          puts("2");
      } else {
        int les = pre[n] - pre[r];
        int pos = lower_bound(v[maxn - (sum + 2 * les)].begin(),
                              v[maxn - (sum + 2 * les)].end(), l) -
                  v[maxn - (sum + 2 * les)].begin();
        if (pos < v[maxn - (sum + 2 * les)].size() &&
            v[maxn - (sum + 2 * les)][pos] <= r) {
          puts("1");
        } else
          puts("2");
      }
    }
    now = now2 = 0;
    for (int i = n; i >= 1; i--) {
      v[maxn + now - (i % 2 ? 1 : -1) * a[i]].clear();
      now -= (i % 2 ? 1 : -1) * a[i] * 2;
      v2[maxn + now2 - (i % 2 ? -1 : 1) * a[i]].clear();
      now2 -= (i % 2 ? -1 : 1) * a[i] * 2;
    }
  }
  return 0;
}
