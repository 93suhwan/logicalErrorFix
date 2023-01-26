#include <bits/stdc++.h>
using namespace std;
const int N = 12;
const int M = 10010;
int T, n, m, x[N], w[M], ans[M];
char s[N][M];
pair<int, int> a[M];
int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
      w[i] = 0;
      for (int j = 0; j < n; j++) {
        w[i] |= ((s[j][i] == '1') ? (1 << j) : 0);
      }
    }
    long long res = -1;
    for (int i = 0; i < (1 << n); i++) {
      int neg = 0;
      int pos = 0;
      long long sum = 0;
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) {
          neg |= (1 << j);
          sum += x[j];
        } else {
          pos |= (1 << j);
          sum -= x[j];
        }
      }
      for (int j = 0; j < m; j++) {
        int mneg = (neg & w[j]);
        int mpos = (pos & w[j]);
        int cnt = __builtin_popcount(mpos) - __builtin_popcount(mneg);
        a[j] = {cnt, j + 1};
      }
      sort(a, a + m);
      for (int j = 0; j < m; j++) {
        sum += a[j].first * (j + 1);
      }
      if (sum > res) {
        res = sum;
        for (int j = 0; j < m; j++) {
          ans[a[j].second - 1] = j + 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
  return 0;
}
