#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, inf = 1e9;
int T, n, m;
vector<int> a[N], mxl[N], mnl[N], mxr[N], mnr[N];
inline bool cmp1(vector<int> x, vector<int> y) { return x[1] < y[1]; }
inline void clr(vector<int> &v) {
  v.clear();
  v.resize(m + 10);
}
inline int tr(int x) { return x ? x : inf; }
char col[N];
void prt(int x, int y) {
  for (int i = 1; i <= x; i++) col[a[i][m + 2]] = 'B';
  for (int i = x + 1; i <= n; i++) col[a[i][m + 2]] = 'R';
  printf("YES\n");
  for (int i = 1; i <= n; i++) putchar(col[i]);
  printf(" %d\n", y);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++) {
      clr(a[i]);
      clr(mxl[i]);
      clr(mnl[i]);
      clr(mxr[i]);
      clr(mnr[i]);
    }
    for (int i = 1; i <= n; i++) {
      a[i][m + 2] = i;
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        mxl[i][j] = max(a[i][j], max(mxl[i - 1][j], mxl[i][j - 1]));
    for (int i = n; i >= 1; i--)
      for (int j = m; j >= 1; j--)
        mxr[i][j] = max(a[i][j], max(mxr[i + 1][j], mxr[i][j + 1]));
    for (int i = n; i >= 1; i--)
      for (int j = 1; j <= m; j++)
        mnl[i][j] = min(a[i][j], min(tr(mnl[i][j - 1]), tr(mnl[i + 1][j])));
    for (int i = 1; i <= n; i++)
      for (int j = m; j >= 1; j--)
        mnr[i][j] = min(a[i][j], min(tr(mnr[i - 1][j]), tr(mnr[i][j + 1])));
    bool flag = 1;
    for (int i = 1; i < n && flag; i++) {
      for (int j = 1; j < m && flag; j++) {
        if (mxl[i][j] < mnl[i + 1][j] && mxr[i + 1][j + 1] < mnr[i][j + 1]) {
          prt(i, j);
          flag = 0;
        }
      }
    }
    if (flag) printf("NO\n");
  }
}
