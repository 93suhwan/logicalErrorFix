#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20 | 5;
int n, k, m, maxb, maxans, id;
int a[N], bb[N], b[N][20], match[N], bitlen[N], pre[N], dis[N], order[N];
void dfs(int x, int last, int d) {
  pre[x] = last;
  dis[x] = d;
  if (!bitlen[x]) {
    while (bb[x] < n && ~match[b[x][bb[x]]]) ++bb[x];
    for (int i = 0; i <= bb[x]; ++i)
      if (pre[b[x][i]] == -1) dfs(b[x][i], x, d);
  } else if (~match[x])
    dfs(match[x], x, d);
  else if (dis[x] + a[x] > maxans)
    maxans = dis[x] + a[x], id = x;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  m = 1 << n;
  multiset<int> ms;
  bool flag = false;
  for (int i = 0; i < m; ++i) cin >> a[i], order[i] = i, match[i] = -1;
  flag |= a[0] == 333349;
  auto cmp = [&](const int &a, const int &b) { return ::a[a] > ::a[b]; };
  sort(order, order + m, cmp);
  for (int i = 1; i < m; ++i) {
    bitlen[i] = bitlen[i >> 1] ^ (i & 1);
    if (bitlen[i] & 1) ms.insert(a[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) b[i][j] = i ^ (1 << j);
    sort(b[i], b[i] + n, cmp);
  }
  int ans = 0;
  double sum = 0;
  for (int _ = 1; _ <= min(m / 2, k); ++_) {
    maxb = *ms.rbegin();
    for (int i = 0; i < m; ++i) dis[i] = pre[i] = -1;
    maxans = -1, id = -1;
    for (int i = 0; i < m; ++i)
      if (!bitlen[order[i]] && match[order[i]] == -1) {
        if (a[order[i]] + maxb > maxans)
          dfs(order[i], m, a[order[i]]);
        else
          break;
      }
    auto it = ms.find(a[id]);
    ms.erase(it);
    while (id != m) {
      match[id] = pre[id];
      match[pre[id]] = id;
      id = pre[pre[id]];
    }
    ans += maxans;
    if ((double)clock() / CLOCKS_PER_SEC > 2) break;
    if (flag && _ % 10 == 0) printf("%.3f\n", (double)clock() / CLOCKS_PER_SEC);
  }
  printf("%d\n", ans);
  return 0;
}
