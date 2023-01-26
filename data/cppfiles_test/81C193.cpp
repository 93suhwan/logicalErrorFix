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
const int maxn = 6e5 + 5;
const long long mod = 998244353;
int _, n, q, a[maxn], pre[maxn], l, r;
char s[maxn];
vector<int> v[2000005], v2[2000005];
int vis[2000005], tmp[2000005], tot;
int vis2[2000005], tmp2[2000005], tot2;
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
      if (vis[maxn + now - (i % 2 ? 1 : -1) * a[i]] == 0) {
        vis[maxn + now - (i % 2 ? 1 : -1) * a[i]] = 1;
        tmp[++tot] = maxn + now - (i % 2 ? 1 : -1) * a[i];
      }
      now -= (i % 2 ? 1 : -1) * a[i] * 2;
      v2[maxn + now2 - (i % 2 ? -1 : 1) * a[i]].push_back(i);
      if (vis2[maxn + now2 - (i % 2 ? -1 : 1) * a[i]] == 0) {
        vis2[maxn + now2 - (i % 2 ? -1 : 1) * a[i]] = 1;
        tmp2[++tot2] = maxn + now2 - (i % 2 ? -1 : 1) * a[i];
      }
      now2 -= (i % 2 ? -1 : 1) * a[i] * 2;
    }
    for (int i = 1; i <= tot; i++) {
      reverse(v[tmp[i]].begin(), v[tmp[i]].end());
    }
    for (int i = 1; i <= tot2; i++) {
      reverse(v2[tmp2[i]].begin(), v2[tmp2[i]].end());
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
    for (int i = 1; i <= tot; i++) {
      v[tmp[i]].clear();
      vis[tmp[i]] = 0;
    }
    for (int i = 1; i <= tot2; i++) {
      v2[tmp2[i]].clear();
      vis2[tmp2[i]] = 0;
    }
    tot = tot2 = 0;
  }
  return 0;
}
