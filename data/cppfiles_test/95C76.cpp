#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", \
                     "no-stack-protector")
using namespace std;
int n, m;
vector<vector<int> > a, mnpre, mxpre, mnsuf, mxsuf;
vector<int> ord;
char ans[1000010];
bool cmp(int x, int y) { return (a[x][0] < a[y][0]); }
void solve() {
  int i, j;
  scanf("%d%d", &n, &m);
  ord.clear();
  a.resize(n);
  mnpre.resize(m);
  mxpre.resize(m);
  mnsuf.resize(m);
  mxsuf.resize(m);
  for (i = 0; i < m; i++) {
    mnpre[i].resize(n);
    mxpre[i].resize(n);
    mnsuf[i].resize(n);
    mxsuf[i].resize(n);
  }
  for (i = 0; i < n; i++) {
    ord.push_back(i);
    a[i].resize(m);
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  sort(ord.begin(), ord.end(), cmp);
  for (i = 0; i < m; i++) {
    mnpre[i][0] = a[ord[0]][i];
    mxpre[i][0] = a[ord[0]][i];
    for (j = 1; j < n; j++) {
      mnpre[i][j] = min(mnpre[i][j - 1], a[ord[j]][i]);
      mxpre[i][j] = max(mxpre[i][j - 1], a[ord[j]][i]);
    }
    mnsuf[i][n - 1] = a[ord[n - 1]][i];
    mxsuf[i][n - 1] = a[ord[n - 1]][i];
    for (j = n - 2; j >= 0; j--) {
      mnsuf[i][j] = min(mnsuf[i][j + 1], a[ord[j]][i]);
      mxsuf[i][j] = max(mxsuf[i][j + 1], a[ord[j]][i]);
    }
  }
  for (i = 1; i < m; i++) {
    for (j = 0; j < n; j++) {
      mxpre[i][j] = max(mxpre[i][j], mxpre[i - 1][j]);
      mnsuf[i][j] = min(mnsuf[i][j], mnsuf[i - 1][j]);
    }
  }
  for (i = m - 2; i >= 0; i--) {
    for (j = 0; j < n; j++) {
      mnpre[i][j] = min(mnpre[i][j], mnpre[i + 1][j]);
      mxsuf[i][j] = max(mxsuf[i][j], mxsuf[i + 1][j]);
    }
  }
  for (i = 0; i + 1 < n; i++) {
    int brk = -1;
    for (j = 0; j < m; j++) {
      if (mxpre[j][i] >= mnsuf[j][i + 1]) {
        brk = j - 1;
        break;
      }
    }
    if (brk == -1) {
      continue;
    }
    if (mxsuf[brk + 1][i + 1] >= mnpre[brk + 1][i]) {
      continue;
    }
    for (j = 0; j < n; j++) {
      if (j <= i) {
        ans[ord[j]] = 'B';
      } else {
        ans[ord[j]] = 'R';
      }
    }
    puts("YES");
    for (j = 0; j < n; j++) {
      putchar(ans[j]);
    }
    putchar(' ');
    printf("%d\n", brk + 1);
    return;
  }
  puts("NO");
  return;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}
