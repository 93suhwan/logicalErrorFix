#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2 * 1e5 + 10;
vector<long long> a[maxn];
long long i, j, k, mm[maxn], t, n, aa, m;
long long dfs(long long i) {
  if (a[i].empty()) return 1;
  if (mm[i] != 0) return mm[i];
  mm[i] = -1;
  long long count = -1;
  for (long long j = 0; j < a[i].size(); j++) {
    long long k = dfs(a[i][j]);
    if (k == -1) return -1;
    if (a[i][j] < i)
      count = max(count, k);
    else
      count = max(count, k + 1);
  }
  mm[i] = count;
  return count;
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    memset(mm, 0, sizeof(mm));
    for (i = 1; i <= n; i++) {
      a[i].clear();
      scanf("%lld", &aa);
      j = aa;
      while (j--) {
        scanf("%lld", &m);
        a[i].push_back(m);
      }
    }
    long long flag = 0, val = -1;
    for (i = 1; i <= n; i++) {
      k = dfs(i);
      if (k == -1) {
        flag = 1;
        break;
      }
      val = max(val, k);
    }
    if (flag)
      printf("-1\n");
    else
      printf("%lld\n", val);
  }
}
