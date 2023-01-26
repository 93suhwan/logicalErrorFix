#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<vector<int> > a, preMax, sufMax, preMin, sufMin;
  int n, m;
  scanf("%d %d", &n, &m);
  a.resize(n, vector<int>(m));
  preMax.resize(n, vector<int>(m));
  sufMax.resize(n, vector<int>(m));
  preMin.resize(n, vector<int>(m));
  sufMin.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    preMax[i][0] = preMin[i][0] = a[i][0];
    sufMax[i][m - 1] = sufMin[i][m - 1] = a[i][m - 1];
  }
  for (int j = 1; j < m; j++) {
    for (int i = 0; i < n; i++) {
      preMax[i][j] = max(preMax[i][j - 1], a[i][j]);
      preMin[i][j] = min(preMin[i][j - 1], a[i][j]);
    }
  }
  for (int j = m - 2; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      sufMax[i][j] = max(sufMax[i][j + 1], a[i][j]);
      sufMin[i][j] = min(sufMin[i][j + 1], a[i][j]);
    }
  }
  for (int i = 1; i < m; i++) {
    vector<vector<int> > v(n);
    vector<int> pMax(n), pMin(n), sMax(n), sMin(n);
    vector<int> tmp;
    for (int j = 0; j < n; j++) {
      tmp.push_back(preMin[j][i - 1]);
      tmp.push_back(preMax[j][i - 1]);
      tmp.push_back(sufMin[j][i]);
      tmp.push_back(sufMax[j][i]);
      tmp.push_back(j);
      v[j] = tmp;
      tmp.clear();
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    pMin[0] = v[0][0];
    pMax[0] = v[0][3];
    sMin[n - 1] = v[n - 1][2];
    sMax[n - 1] = v[n - 1][1];
    for (int j = 1; j < n; j++) {
      pMin[j] = min(pMin[j - 1], v[j][0]);
      pMax[j] = max(pMax[j - 1], v[j][3]);
    }
    for (int j = n - 2; j >= 0; j--) {
      sMin[j] = min(sMin[j + 1], v[j][2]);
      sMax[j] = max(sMax[j + 1], v[j][1]);
    }
    for (int j = 0; j < n - 1; j++) {
      if (pMin[j] > sMax[j + 1] && pMax[j] < sMin[j + 1]) {
        printf("YES\n");
        char c[1000005];
        c[n] = 0;
        fill(c, c + n, 'B');
        for (int k = 0; k <= j; k++) c[v[k][4]] = 'R';
        printf("%s %d\n", c, i);
        return;
      }
    }
  }
  printf("NO\n");
  a.clear();
  preMax.clear();
  sufMax.clear();
  preMin.clear();
  sufMin.clear();
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
