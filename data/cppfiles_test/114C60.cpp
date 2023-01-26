#include <bits/stdc++.h>
using namespace std;
const int maxn = 15, maxm = 100005;
int n, m;
long long sum, res;
long long tot[maxm];
vector<int> ans, v[maxn], w[maxm];
set<vector<int> > s;
int main() {
  scanf("%d", &n), ans.resize(n);
  for (int i = 1, k, x; i <= n; i++) {
    scanf("%d", &k), v[i].resize(k);
    for (int j = 0; j < k; j++) scanf("%d", &v[i][j]);
    sum += v[i][k - 1], ans[i - 1] = k;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    vector<int> p;
    p.clear(), p.resize(n);
    for (int j = 0; j < n; j++)
      scanf("%d", &p[j]), tot[i] += v[j + 1][p[j] - 1];
    s.insert(p), w[i] = p;
  }
  if (s.find(ans) != s.end())
    for (int i = 1; i <= m; i++) {
      vector<int> p = w[i];
      for (int j = 1; j <= n; j++)
        if (p[j - 1] != 1) {
          p[j - 1]--;
          if (s.find(p) == s.end()) {
            long long now =
                tot[i] - v[j][p[j - 1] + 1 - 1] + v[j][p[j - 1] - 1];
            if (now > res) ans = p, res = now;
          }
          p[j - 1]++;
        }
    }
  for (int i = 0; i < n; i++) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
