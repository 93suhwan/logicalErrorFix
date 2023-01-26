#include <bits/stdc++.h>
using namespace std;
const int N = 500000, INF = 0x3f3f3f3f;
int *aa[N], *aa_[N], *bb[N], *cc[N], *dd[N], ii[N];
char ans[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      aa[i] = (int *)malloc(m * sizeof *aa[i]);
      aa_[i] = (int *)malloc(m * sizeof *aa_[i]);
      bb[i] = (int *)malloc(m * sizeof *bb[i]);
      cc[i] = (int *)malloc(m * sizeof *cc[i]);
      dd[i] = (int *)malloc(m * sizeof *dd[i]);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> aa[i][j];
    for (int h = 0; h < n; h++) ii[h] = h;
    sort(ii, ii + n, [](int i, int j) { return aa[i][0] < aa[j][0]; });
    for (int h = 0; h < n; h++)
      for (int j = 0; j < m; j++) aa_[h][j] = aa[ii[h]][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        aa[i][j] = bb[i][j] = cc[i][j] = dd[i][j] = aa_[i][j];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        aa[i][j] =
            max(aa[i][j], max(i ? aa[i - 1][j] : 0, j ? aa[i][j - 1] : 0));
    for (int i = n - 1; i >= 0; i--)
      for (int j = 0; j < m; j++)
        bb[i][j] = min(bb[i][j], min(i + 1 < n ? bb[i + 1][j] : INF,
                                     j ? bb[i][j - 1] : INF));
    for (int i = n - 1; i >= 0; i--)
      for (int j = m - 1; j >= 0; j--)
        cc[i][j] = max(cc[i][j], max(i + 1 < n ? cc[i + 1][j] : 0,
                                     j + 1 < m ? cc[i][j + 1] : 0));
    for (int i = 0; i < n; i++)
      for (int j = m - 1; j >= 0; j--)
        dd[i][j] = min(dd[i][j], min(i ? dd[i - 1][j] : INF,
                                     j + 1 < m ? dd[i][j + 1] : INF));
    for (int i = 0; i + 1 < n; i++)
      for (int j = 0; j + 1 < m; j++)
        if (aa[i][j] < bb[i + 1][j] && cc[i + 1][j + 1] < dd[i][j + 1]) {
          cout << "YES\n";
          fill(ans, ans + n, 'R');
          for (int h = 0; h <= i; h++) ans[ii[h]] = 'B';
          ans[n] = '\0';
          cout << ans << ' ' << j + 1 << '\n';
          goto out;
        }
    cout << "NO\n";
  out:;
  }
  return 0;
}
