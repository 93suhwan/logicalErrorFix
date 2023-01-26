#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 35;
int x[M];
int a[M][N];
struct ans {
  int A, B;
} cnt[N];
bool cmp(ans C, ans D) {
  if (C.A == D.A)
    return C.B < D.B;
  else
    return C.A < D.A;
}
int res[N];
void run() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < m; i++) cnt[i].A = 0, cnt[i].B = i + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '1')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  int nm = (1 << n);
  long long ans = -1e18;
  for (int i = 0; i < nm; i++) {
    long long tot = 0;
    for (int j = 0; j < m; j++) cnt[j].A = 0, cnt[j].B = j + 1;
    for (int j = 0; j < n; j++) {
      if (i >> j & 1)
        tot += x[j];
      else
        tot -= x[j];
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if ((i >> j & 1) && a[j][k])
          cnt[k].A--;
        else if (!(i >> j & 1) && a[j][k])
          cnt[k].A++;
      }
    }
    sort(cnt, cnt + m, cmp);
    for (int j = 0; j < m; j++) tot += cnt[j].A * (j + 1);
    if (tot > ans) {
      ans = tot;
      for (int j = 0; j < m; j++) {
        res[cnt[j].B] = j + 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d ", res[i]);
  }
  puts("");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    run();
  }
  return 0;
}
