#include <bits/stdc++.h>
using namespace std;
long long slsl = 0, q[200005], f[200005];
vector<long long> s[200005];
pair<long long, long long> p[200005];
void dfs(long long sg, long long x, long long cs) {
  p[++slsl] = {cs, x}, f[x] = sg;
  for (long long i = 0; i <= s[x].size() - 1; i++) {
    if (s[x][i] != sg) {
      dfs(x, s[x][i], cs + 1);
    }
  }
}
int main() {
  long long n, k, i, j, a, b, c, d, zc, zczc, dq, sc, zd;
  scanf("%lld%lld", &n, &k);
  for (i = 1; i <= n - 1; i++) {
    scanf("%lld%lld", &a, &b);
    s[a].push_back(b), s[b].push_back(a);
  }
  dfs(-1, 1, 1);
  sort(p + 1, p + 1 + n, greater<pair<long long, long long> >());
  for (i = 1; i <= n; i++) {
    zc = 0, dq = p[i].second;
    while (dq != -1 and q[dq] != 1) {
      q[dq] = 1;
      zc++;
      dq = f[dq];
    }
    p[i].first = zc;
  }
  sort(p + 1, p + 1 + n, greater<pair<long long, long long> >());
  for (i = 1, zc = 0; i <= n; i++) {
    if (p[i].first > 0)
      zc++;
    else
      break;
  }
  for (i = 1, sc = -1e18, zczc = 0; i <= k; i++) {
    zczc += p[i].first;
    dq = n - zczc;
    zd = max(n / 2 * (n - n / 2), (n / 2 + 1) * (n - n / 2 - 1));
    if (dq <= n / 2) zd = min(zd, dq * (n - dq));
    sc = max(sc, i * (n - i) - zd);
  }
  printf("%lld\n", sc);
  return 0;
}
