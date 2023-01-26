#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 500;
int ltot[3][3][maxn], f[maxn];
int n, m, ans;
string ch;
int main() {
  memset(ltot, 0, sizeof(ltot));
  scanf("%d%d", &n, &m);
  cin >> ch;
  ch = ' ' + ch;
  for (int i = 1; i <= n; ++i) ltot[i % 3][ch[i] - 'a'][i]++;
  for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 3; ++k)
      for (int i = 1; i <= n; ++i) ltot[j][k][i] += ltot[j][k][i - 1];
  for (int i = 1; i <= n; ++i) f[i] = ch[i] - 'a';
  for (int tt = 1, q1, q2; tt <= m; ++tt) {
    ans = maxn * 100;
    scanf("%d%d", &q1, &q2);
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        for (int k = 0; k < 3; ++k)
          if (i != j && j != k && i != k) {
            int t1 = (q2 - q1 + 1) / 3;
            if ((q2 - q1 + 1) % 3 > 0) ++t1;
            int t2 = (q2 - q1 + 1) / 3;
            if ((q2 - q1 + 1) % 3 > 1) ++t2;
            int t3 = (q2 - q1 + 1) / 3;
            int sum = 0;
            sum += t3 -
                   (ltot[(q1 + 2) % 3][k][q2] - ltot[(q1 + 2) % 3][k][q1 - 1]);
            sum += t2 -
                   (ltot[(q1 + 1) % 3][j][q2] - ltot[(q1 + 1) % 3][j][q1 - 1]);
            sum += t1 - (ltot[q1 % 3][i][q2] - ltot[q1 % 3][i][q1 - 1]);
            ans = min(sum, ans);
          }
    printf("%d\n", ans);
  }
  return 0;
}
