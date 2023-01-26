#include <bits/stdc++.h>
using namespace std;
int n, m, len[21], ans, f[21][800011], w[21], ss[1100001], val[21];
char ch[21][400011];
bool fl[21][800011];
int main() {
  val[0] = 1;
  for (int i = 1; i <= 20; i++) val[i] = val[i - 1] + val[i - 1];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch[i] + 1);
    len[i] = strlen(ch[i] + 1);
    for (int j = 1; j <= len[i]; j++) {
      if (ch[i][j] == '(')
        w[i]++;
      else
        w[i]--;
      int s = 400000 - w[i] - 1;
      while (s >= 0) {
        if (fl[i][s]) break;
        fl[i][s] = 1;
        s--;
      }
      if (!fl[i][400000 - w[i]]) f[i][400000 - w[i]]++;
    }
  }
  for (int i = 1; i < val[n]; i++) ss[i] = -1000000000;
  for (int i = 0; i < val[n]; i++) {
    ans = max(ans, ss[i]);
    int s = 400000;
    for (int j = 1; j <= n; j++)
      if (val[j - 1] & i) s = s + w[j];
    for (int j = 1; j <= n; j++) {
      if (val[j - 1] & i) continue;
      if (!fl[j][s]) {
        ss[i | val[j - 1]] = max(ss[i | val[j - 1]], ss[i] + f[j][s]);
      } else {
        ans = max(ans, ss[i] + f[j][s]);
      }
    }
  }
  printf("%d\n", ans);
}
