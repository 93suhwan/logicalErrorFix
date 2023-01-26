#include <bits/stdc++.h>
using namespace std;
int T, n, m;
vector<int> a[500010], mn1[500010], mn2[500010], mx1[500010], mx2[500010];
int ord[500010], mx[500010], mn[500010];
bool ans[500010];
bool cmp(int x, int y) { return a[x][0] < a[y][0]; }
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      a[i].clear();
      mn1[i].clear();
      mn2[i].clear();
      mx1[i].clear();
      mx2[i].clear();
      for (int j = 1; j <= m; j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
    }
    for (int i = 1; i <= n; i++) ord[i] = i;
    sort(ord + 1, ord + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      mn1[i].push_back(a[i][0]);
      mx1[i].push_back(a[i][0]);
      for (int j = 1; j < m; j++) {
        mn1[i].push_back(min(mn1[i][j - 1], a[i][j]));
        mx1[i].push_back(max(mx1[i][j - 1], a[i][j]));
      }
      mn2[i].push_back(a[i].back());
      mx2[i].push_back(a[i].back());
      for (int j = m - 2; j >= 0; j--) {
        mn2[i].push_back(min(mn2[i].back(), a[i][j]));
        mx2[i].push_back(max(mx2[i].back(), a[i][j]));
      }
      reverse(mn2[i].begin(), mn2[i].end());
      reverse(mx2[i].begin(), mx2[i].end());
    }
    bool ok = false;
    for (int j = 0; j < m - 1 && !ok; j++) {
      mn[n + 1] = 1e7;
      for (int i = n; i >= 1; i--) mn[i] = min(mn[i + 1], mn1[ord[i]][j]);
      mx[n + 1] = 0;
      for (int i = n; i >= 1; i--) mx[i] = max(mx[i + 1], mx2[ord[i]][j + 1]);
      int cmx = 0, cmn = 1e7;
      for (int i = 1; i < n; i++) {
        int r = ord[i];
        cmx = max(cmx, mx1[r][j]);
        cmn = min(cmn, mn2[r][j + 1]);
        if (cmx < mn[i + 1] && cmn > mx[i + 1]) {
          cout << "YES" << endl;
          for (int k = 1; k <= i; k++) ans[ord[k]] = false;
          for (int k = i + 1; k <= n; k++) ans[ord[k]] = true;
          for (int i = 1; i <= n; i++)
            if (ans[i])
              cout << 'R';
            else
              cout << 'B';
          cout << ' ' << j + 1 << endl;
          ok = true;
          break;
        }
      }
    }
    if (!ok) cout << "NO" << endl;
  }
  return 0;
}
