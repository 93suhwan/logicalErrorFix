#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int n, q, k, nxt[MAXN], stk[MAXN], tp, lg[MAXN], b[MAXN];
long long f[MAXN];
pair<int, int> st[20][MAXN];
pair<int, int> query(int l, int r) {
  int s = lg[r - l + 1];
  return min(st[s][l], st[s][r - (1 << s) + 1]);
}
void pre() {
  for (int i = 1; (1 << i) <= n; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
  for (int i = k + 1; i <= n; i++) b[i] = query(i - k, i).first;
  stk[0] = n + 1;
  for (int l = k + 1; l + k <= n && l <= 2 * k; l++) {
    int r = l + (n - l) / k * k;
    tp = 0;
    for (int i = r; i >= l; i -= k) {
      while (tp && b[stk[tp]] > b[i]) tp--;
      nxt[i] = stk[tp];
      stk[++tp] = i;
      f[i] = f[nxt[i]] + (long long)b[i] * (nxt[i] / k - i / k);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &q, &k);
  for (int i = 2; i <= n; i++) lg[i] = (lg[i >> 1] + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &st[0][i].first);
    st[0][i].second = i;
  }
  pre();
  int l, r;
  long long ans;
  while (q--) {
    scanf("%d%d", &l, &r);
    r = l + (r - l) / k * k;
    ans = st[0][l].first;
    if (l + k <= r) {
      int p = query(l, r).second;
      if (p == l) p += k;
      p += (r - p) % k;
      ans += f[l + k] - f[p] + (long long)b[p] * (r / k - p / k + 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
