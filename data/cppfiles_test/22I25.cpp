#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, lim;
pair<int, int> train[maxn], pre[maxn];
int ti[505][505];
int b[maxn], s[maxn];
void update(int L, int R, int period, int v) {
  if (L <= R) {
    for (int i = L; i <= R; i++) ti[period][i] += v;
  } else {
    for (int i = 0; i <= R; i++) ti[period][i] += v;
    for (int i = L; i < period; i++) ti[period][i] -= v;
  }
}
int main(void) {
  scanf("%d%d", &n, &m);
  lim = (int)sqrt(m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &train[i].first, &train[i].second);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int op, k;
    scanf("%d%d", &op, &k);
    int period = train[k].first + train[k].second;
    if (period <= lim) {
      if (op == 1) {
        int R = (i - 1) % period;
        int L = (i + train[k].first) % period;
        update(L, R, period, 1);
        pre[k].first = L;
        pre[k].second = R;
      } else {
        int L = pre[k].first, R = pre[k].second;
        update(L, R, period, -1);
      }
    } else {
      if (op == 1) {
        for (int j = i + train[k].first; j <= m; j += period) {
          b[j]++;
          if (j + train[k].second <= m) b[j + train[k].second]--;
        }
        s[k] = i;
      } else {
        for (int j = s[k] + train[k].first; j <= m; j += period) {
          b[j]--;
          if (j + train[k].second <= m) b[j + train[k].second]++;
          if (j < i && j + train[k].second >= i) --ans;
        }
      }
    }
    ans += b[i];
    int sum = 0;
    for (int j = 2; j <= lim; j++) {
      sum += ti[j][i % j];
    }
    printf("%d\n", ans + sum);
  }
  return 0;
}
