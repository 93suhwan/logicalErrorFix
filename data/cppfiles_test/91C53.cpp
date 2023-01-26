#include <bits/stdc++.h>
using namespace std;
inline void upd(long long &a, long long b) { a = (a + b) % 998244353; }
int T, n, a[200017];
long long ans, F[2][200017];
vector<int> v[2];
inline void clear(int f) {
  for (unsigned int i = 0; i < v[f].size(); i += 1) F[f][v[f][i]] = 0;
  v[f].clear();
}
int main() {
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1) scanf("%d", &a[i]);
    for (int i = n; i >= 1; i -= 1) {
      int f = i & 1, lst = a[i];
      v[f].push_back(a[i]);
      F[f][a[i]] = 1;
      for (unsigned int j = 0; j < v[f ^ 1].size(); j += 1) {
        int cnt = F[f ^ 1][v[f ^ 1][j]];
        int split = (a[i] + v[f ^ 1][j] - 1) / v[f ^ 1][j];
        int st = a[i] / split;
        upd(ans, 1ll * (split - 1) * cnt * i);
        upd(F[f][st], cnt);
        F[f ^ 1][v[f ^ 1][j]] = 0;
        if (lst != st) v[f].push_back(st), lst = st;
      }
      clear(f ^ 1);
    }
    clear(0);
    clear(1);
    printf("%lld\n", ans % 998244353);
  }
  return 0;
}
