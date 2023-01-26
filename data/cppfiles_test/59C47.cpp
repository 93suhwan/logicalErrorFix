#include <bits/stdc++.h>
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
using namespace std;
long long ksm(long long a, long long b) {
  if (!b) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 998244353;
  if (b & 1) ns = ns * a % 998244353;
  return ns;
}
int n, m, a[4005], b[4005], u[4005], v[4005], dis[4005], lst[4005];
long long power;
int cur;
bool vis[4005];
vector<pair<int, int> > e[4005];
vector<int> E[4005];
long long refresh() {
  for (int i = 1; i <= n; i++) {
    E[i].clear();
    for (auto x : e[i]) E[i].push_back(x.second);
  }
  long long del = 1 << 30;
  queue<int> q;
  for (auto x : E[1])
    if (dis[x] <= power)
      q.push(x);
    else
      del = min(del, dis[x] - power);
  E[1].clear();
  while (!q.empty()) {
    int id = q.front();
    q.pop();
    if (!vis[v[id]]) {
      vis[v[id]] = 1;
      power += b[v[id]];
      del = -1;
      return del;
    }
    bool rid = false;
    for (auto x : E[v[id]]) {
      if (x == (id ^ 1)) {
        rid = true;
        continue;
      }
      if (dis[x] <= power)
        q.push(x);
      else
        del = min(del, dis[x] - power);
    }
    E[v[id]].clear();
    if (rid) E[v[id]].push_back(id ^ 1);
  }
  return del;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) e[i].clear(), vis[i] = 0;
  for (int i = 2; i <= n; i++) scanf("%d", &a[i]), a[i] += 1;
  for (int i = 2; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u[2 * i], &v[2 * i]);
    u[2 * i + 1] = v[2 * i];
    v[2 * i + 1] = u[2 * i];
    e[u[2 * i]].push_back(make_pair(v[2 * i], 2 * i));
    e[u[2 * i + 1]].push_back(make_pair(v[2 * i + 1], 2 * i + 1));
  }
  for (int i = 0; i < 2 * m; i++) dis[i] = a[v[i]];
  for (int r = 0; r < 2 * m; r++) {
    memcpy(lst, dis, sizeof lst);
    for (int i = 1; i <= n; i++) {
      pair<int, int> m1(1 << 30, -1), m2(1 << 30, -1);
      for (auto x : e[i]) {
        if (lst[x.second] < m2.first) m2 = {lst[x.second], x.second};
        if (m2 < m1) swap(m2, m1);
      }
      for (auto x : e[i]) {
        int id = x.second ^ 1;
        if (m1.second == x.second)
          dis[id] = max(a[v[id]], m2.first - b[i]);
        else
          dis[id] = max(a[v[id]], m1.first - b[i]);
      }
    }
  }
  cur = 0;
  power = 0;
  while (true) {
    int del = refresh();
    if (del == (1 << 30)) break;
    if (del > 0) {
      cur += del;
      power += del;
    }
  }
  printf("%d\n", cur);
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}
