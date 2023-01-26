#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int bc = 450;
int n, m, bl;
int x[maxn], y[maxn];
int d[maxn];
int d2[bc][bc];
int ans[maxn], be[maxn];
void block_update(int p, int id, int v) {
  int t = x[id] + y[id];
  int l = (p + x[id]) % t, r = (p - 1) % t;
  if (l <= r) {
    for (int i = l; i <= r; ++i) d2[t][i] += v;
  } else {
    for (int i = 0; i <= r; ++i) d2[t][i] += v;
    for (int i = l; i < t; ++i) d2[t][i] += v;
  }
}
int block_query(int p) {
  int sum = 0;
  for (int i = 2; i <= bl; ++i) sum += d2[i][p % i];
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  bl = min((int)sqrt(m) + 1, bc);
  for (int i = (1); i <= (int)(n); ++i) cin >> x[i] >> y[i];
  for (int i = (1); i <= (int)(m); ++i) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      if (x[k] + y[k] >= bl) {
        for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
          ++d[j];
          if (j + y[k] <= m) --d[j + y[k]];
        }
      } else
        block_update(i, k, 1);
      be[k] = i;
    } else {
      if (x[k] + y[k] >= bl) {
        for (int j = be[k] + x[k]; j <= m; j += x[k] + y[k]) {
          if (j <= i && j + y[k] > i) {
            --d[i];
            if (j + y[k] <= m) ++d[j + y[k]];
          } else if (j > i) {
            --d[j];
            if (j + y[k] <= m) ++d[j + y[k]];
          }
        }
      } else
        block_update(be[k], k, -1);
    }
    ans[i] = block_query(i);
  }
  for (int i = (1); i <= (int)(m); ++i) {
    d[i] += d[i - 1];
    printf("%d\n", d[i] + ans[i]);
  }
  return 0;
}
