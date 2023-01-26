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
int ans[maxn], b[maxn];
vector<int> ve[maxn];
void update(int L, int R, int period, int v) {
  if (L <= R) {
    for (int i = L; i <= R; i++) ti[period][i] += v;
  } else {
    for (int i = 0; i <= R; i++) ti[period][i] += v;
    for (int i = L; i < period; i++) ti[period][i] += v;
  }
}
int main(void) {
  scanf("%d%d", &n, &m);
  lim = (int)sqrt(m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &train[i].first, &train[i].second);
  }
  for (int i = 1; i <= m; i++) {
    int op, k;
    scanf("%d%d", &op, &k);
    if (op == 1) {
      ve[k].push_back(i);
    } else {
      ve[k].push_back(-i);
    }
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
    }
    for (int j = 2; j <= lim; j++) {
      ans[i] += ti[j][i % j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (train[i].first + train[i].second <= lim) continue;
    for (int j = 0; j < (int)(ve[i]).size(); j += 2) {
      int R = (j == (int)(ve[i]).size() - 1) ? m : (-ve[i][j + 1]) - 1;
      for (int k = ve[i][j] + train[i].first; k <= R;
           k += train[i].first + train[i].second) {
        b[k]++;
        b[min(k + train[i].second - 1, R) + 1]--;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    b[i] += b[i - 1];
    ans[i] += b[i];
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
