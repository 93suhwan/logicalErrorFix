#include <bits/stdc++.h>
using namespace std;
int a[1005];
int k[10005];
char s[11][10005];
vector<int> v[200005], vv, save;
int outs[20005];
int main() {
  long long ans = 0;
  int t;
  cin >> t;
  while (t--) {
    ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j <= 100; j++) v[j].clear();
      vv.clear();
      long long c = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j))
          c += a[j];
        else
          c -= a[j];
      }
      for (int j = 0; j < m; j++) k[j] = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          for (int q = 0; q < m; q++)
            if (s[j][q] == '1') k[q]--;
        } else {
          for (int q = 0; q < m; q++)
            if (s[j][q] == '1') k[q]++;
        }
      }
      for (int j = 0; j < m; j++) {
        v[k[j] + 20].push_back(j);
      }
      for (int j = 0; j <= 100; j++)
        for (auto &k : v[j]) vv.push_back(k);
      for (int j = 0; j < m; j++) {
        c += k[vv[j]] * (j + 1);
      }
      if (c > ans) {
        ans = c;
        save = vv;
      }
    }
    int cnt = 0;
    for (auto k : save) {
      outs[k] = ++cnt;
    }
    for (int i = 0; i < m; i++) printf("%d%c", outs[i], " \n"[i == m - 1]);
  }
  return 0;
}
