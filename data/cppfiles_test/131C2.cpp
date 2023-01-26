#include <bits/stdc++.h>
const int N = 1e6 + 5, M = 5e3, P = 998244353, INF = 0x7fffffff;
using namespace std;
template <typename T>
void read(T &first) {
  int f = 1;
  first = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    first = (first << 3) + (first << 1) + c - '0';
    c = getchar();
  }
  first *= f;
}
void write(register int first) {
  if (first < 0) {
    first = ~first + 1;
    putchar('-');
  }
  if (first > 9) write(first / 10);
  putchar(first % 10 + '0');
}
int n, tot, a[N], m[N << 2];
pair<int, int> dep[N << 2];
pair<int, pair<int, int> > ans[N << 2];
vector<long long> disc, e[N << 2];
bool bk[N << 2], vis[N << 2];
int get(long long first) {
  return lower_bound(disc.begin(), disc.end(), first) - disc.begin() + 1;
}
void dfs(int u) {
  vis[u] = 1;
  pair<int, int> f = make_pair(0, 0), s = make_pair(0, 0);
  if (bk[u]) dep[u] = make_pair(0, u);
  for (int v : e[u]) {
    if (vis[v]) continue;
    dfs(v), dep[v].first++;
    dep[u] = max(dep[u], dep[v]);
    ans[u] = max(ans[u], ans[v]);
    if (dep[v] > f)
      s = f, f = dep[v];
    else if (dep[v] > s)
      s = dep[v];
  }
  if (bk[u])
    ans[u] = max(ans[u], make_pair(dep[u].first, make_pair(u, dep[u].second)));
  if (s.first > 0)
    ans[u] = max(ans[u],
                 make_pair(f.first + s.first, make_pair(f.second, s.second)));
}
int main() {
  read(n);
  disc.push_back(0);
  for (register int(i) = (1); (i) <= (n); i++) {
    read(a[i]);
    long long first = a[i];
    while (first) {
      disc.push_back(first);
      long long s = 1ll << (31 - __builtin_clz(first));
      if (s < first) s <<= 1;
      first = s - first;
    }
  }
  sort(disc.begin(), disc.end());
  disc.erase(unique(disc.begin(), disc.end()), disc.end());
  for (register int(i) = (1); (i) <= (n); i++) {
    long long first = a[i];
    bk[get(first)] = 1, m[get(first)] = i;
    while (first) {
      long long s = 1ll << (31 - __builtin_clz(first));
      if (s < first) s <<= 1;
      e[get(s - first)].push_back(get(first));
      first = s - first;
    }
  }
  dfs(1);
  printf("%d %d %d\n", m[ans[1].second.second], m[ans[1].second.first],
         ans[1].first);
  return 0;
}
