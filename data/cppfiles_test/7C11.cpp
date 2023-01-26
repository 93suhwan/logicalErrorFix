#include <bits/stdc++.h>
using namespace std;
void read(int& x) { scanf("%d", &x); }
void read(long long& x) { scanf("%lld", &x); }
void read(double& x) { scanf("%lf", &x); }
long long gcd(long long x, long long y) {
  while (y) {
    long long t = x % y;
    x = y;
    y = t;
  }
  return x;
}
char a[600], b[600];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s%s", &a[1], &b[1]);
  vector<int> pi(m + 1, 0);
  pi[0] = -1;
  {
    int k = -1;
    for (int i = 1; i <= m; i++) {
      while (k >= 0 && b[k + 1] != b[i]) k = pi[k];
      pi[i] = ++k;
    }
  }
  vector<map<pair<int, int>, int>> d(n + 1);
  d[0][{0, 0}] = 0;
  for (int t = 0; t < n; t++) {
    for (auto& [key, v] : d[t]) {
      int c0 = key.first;
      int k0 = key.second;
      for (int dv = 0; dv <= 1; dv++) {
        int c = c0;
        int k = k0;
        int nxti = a[t + 1] - '0';
        if (dv) nxti = !nxti;
        char nxt = '0' + nxti;
        while (k >= 0 && b[k + 1] != nxt) k = pi[k];
        k++;
        if (k == m) {
          c++;
          k = pi[k];
        }
        auto nk = make_pair(c, k);
        auto it = d[t + 1].find(nk);
        if (it != d[t + 1].end())
          it->second = min(it->second, v + dv);
        else
          d[t + 1][nk] = v + dv;
      }
    }
    d[t].clear();
  }
  vector<int> ans(n - m + 2, -1);
  for (auto& [key, v] : d[n]) {
    if (ans[key.first] < 0 || ans[key.first] > v) ans[key.first] = v;
  }
  for (auto x : ans) printf("%d ", x);
  printf("\n");
}
int main() {
  { solve(); }
  return 0;
}
