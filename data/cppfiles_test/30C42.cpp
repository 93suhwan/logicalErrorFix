#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c & 15), c = getchar();
}
const int m = 1000001;
int n, a[150005], q, fa[150005 + 1000005], cnt, prime[150005 + 1000005], ans,
    id[1000005], p[1000005];
bool vis[150005 + 1000005];
set<int> s[150005 + 1000005];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
signed main() {
  for (int i = 2; i <= m; i++) {
    if (!vis[i]) prime[++cnt] = i, p[i] = cnt;
    for (int j = 1; j <= cnt && i * prime[j] <= m; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  read(n), read(q);
  for (int i = 1; i <= n; i++) read(a[i]), id[a[i]] = cnt + i;
  for (int i = 1; i <= cnt + n; i++) fa[i] = i;
  for (int i = 1; i <= cnt; i++)
    for (int j = prime[i]; j <= m; j += prime[i])
      if (id[j]) fa[find(id[j])] = find(i);
  for (int i = 1; i <= n; i++) {
    vector<int> k;
    int n = a[i] + 1, m = a[i] + 1;
    for (int j = 1; prime[j] * prime[j] <= n && m > 1; j++) {
      if (m % prime[j] == 0) {
        k.push_back(find(j));
        while (m % prime[j] == 0) m /= prime[j];
      }
    }
    if (m > 1) k.push_back(find(p[m]));
    k.push_back(find(cnt + i));
    for (int x = 0; x < (int)k.size(); x++)
      for (int y = x + 1; y < (int)k.size(); y++)
        s[k[x]].insert(k[y]), s[k[y]].insert(k[x]);
  }
  while (q--) {
    int x, y;
    read(x), read(y);
    if (find(cnt + x) == find(cnt + y))
      ans = 0;
    else if (s[find(cnt + x)].count(find(cnt + y)) ||
             s[find(cnt + y)].count(find(cnt + x)))
      ans = 1;
    else
      ans = 2;
    printf("%d\n", ans);
  }
  return 0;
}
