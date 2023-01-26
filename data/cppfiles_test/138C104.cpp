#include <bits/stdc++.h>
using namespace std;
const int N = 400 * 1000 + 13;
int n, m, k;
int a[N], b[N];
int q[N];
int p[N];
multiset<int> wst[N], bst[N];
long long sum;
int getp(int a) { return a == p[a] ? a : p[a] = getp(p[a]); }
void unite(int a, int b) {
  a = getp(a), b = getp(b);
  if (wst[a].size() + bst[a].size() < wst[b].size() + bst[b].size()) swap(a, b);
  for (auto it : wst[b]) wst[a].insert(it);
  for (auto it : bst[b]) bst[a].insert(it);
  wst[b].clear();
  bst[b].clear();
  while (!bst[a].empty() && !wst[a].empty() &&
         *bst[a].begin() < *wst[a].rbegin()) {
    sum -= *bst[a].begin();
    sum += *wst[a].rbegin();
    bst[a].insert(*wst[a].rbegin());
    wst[a].insert(*bst[a].begin());
    bst[a].erase(bst[a].begin());
    wst[a].erase(--wst[a].end());
  }
  p[b] = a;
}
long long ans[N];
struct event {
  int x, t, i;
};
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < int(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < int(m); i++) scanf("%d", &b[i]);
  for (int i = 0; i < int(k); i++) scanf("%d", &q[i]);
  vector<pair<int, int>> tot;
  for (int i = 0; i < int(n); i++) tot.push_back({a[i], 1});
  for (int i = 0; i < int(m); i++) tot.push_back({b[i], 0});
  sort(tot.begin(), tot.end());
  sum = accumulate(a, a + n, 0ll);
  for (int i = 0; i < int(n + m); i++) {
    p[i] = i;
    wst[i].clear();
    bst[i].clear();
    if (tot[i].second)
      bst[i].insert(tot[i].first);
    else
      wst[i].insert(tot[i].first);
  }
  vector<event> ev;
  for (int i = 0; i < int(n + m - 1); i++)
    ev.push_back({tot[i + 1].first - tot[i].first, 0, i});
  for (int i = 0; i < int(k); i++) ev.push_back({q[i], 1, i});
  sort(ev.begin(), ev.end(), [](const event &a, const event &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.t < b.t;
  });
  for (auto it : ev) {
    if (it.t == 0)
      unite(it.i, it.i + 1);
    else
      ans[it.i] = sum;
  }
  for (int i = 0; i < int(k); i++) printf("%lld\n", ans[i]);
}
