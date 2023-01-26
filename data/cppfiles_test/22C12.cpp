#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAGIC = 450;
int n, m;
int a[200000 + 1], x[200000 + 1], y[200000 + 1], rest[200000 + 1],
    cf[200000 + 1], cf2[200000 + 1];
int tmp[MAGIC][MAGIC], pt[MAGIC], is[200000 + 1], tim[200000 + 1], addi;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int _ = 1; _ <= m; ++_) {
    int op;
    int t;
    scanf("%d%d", &op, &t);
    for (int i = 1; i <= MAGIC - 1; ++i) {
      pt[i]++;
      pt[i] %= i;
    }
    if (op == 1) {
      tim[t] = _;
      int len = x[t] + y[t];
      if (x[t] + y[t] < MAGIC) {
        is[t] = pt[len];
        for (int j = 0; j < len; ++j) {
          tmp[len][(pt[len] + j) % len] += (j < x[t] ? 0 : 1);
        }
      } else {
        for (int i = _; i <= m; i += len) {
          if (i + x[t] <= m) cf[i + x[t]]++;
          if (i + len <= m) cf[i + len]--;
        }
      }
    }
    if (op == 2) {
      int len = x[t] + y[t];
      if (x[t] + y[t] < MAGIC) {
        for (int j = 0; j < len; ++j) {
          tmp[len][(is[t] + j) % len] -= (j < x[t] ? 0 : 1);
        }
      } else {
        for (int i = tim[t]; i <= m; i += len) {
          if (i + len <= _) continue;
          if (i + x[t] <= m) cf2[max(_, i + x[t])]++;
          if (i + len <= m) cf2[i + len]--;
        }
      }
    }
    cf2[_] += cf2[_ - 1];
    cf[_] += cf[_ - 1];
    addi = 0;
    for (int i = 1; i <= MAGIC - 1; ++i) {
      addi += tmp[i][pt[i]];
    }
    printf("%d\n", rest[_] + cf[_] - cf2[_] + addi);
  }
  return 0;
}
