#include <bits/stdc++.h>
using namespace std;
int a[310][310];
int cnt[90010], ch[310][310];
void sol() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> ix;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt[i * m + j] = 0;
      ch[i][j] = false;
      scanf("%d", &a[i][j]);
      ix.push_back(a[i][j]);
    }
  }
  cnt[n * m] = 0;
  sort(ix.begin(), ix.end());
  int re = 0;
  for (int i = 0; i < m * n; i++) {
    int r = upper_bound(ix.begin(), ix.end(), a[i / m][i % m]) - ix.begin() - 1;
    int l = lower_bound(ix.begin(), ix.end(), a[i / m][i % m]) - ix.begin();
    int p = r - cnt[r];
    if (r / m != l / m) {
      p = (l / m + 1) * m - 1 - cnt[r];
      if (p < l) {
        p = r / m * m - 1 - (cnt[r] - (((l / m + 1) * m - 1) - l + 1));
        if (p < (l / m + 1) * m) p = r - (cnt[r] - r / m * m + l);
      }
    }
    for (int j = 0; j < p % m; j++)
      if (ch[p / m][j]) re++;
    ch[p / m][p % m] = 1;
    cnt[r]++;
  }
  printf("%d\n", re);
}
int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) sol();
  return 0;
}
