#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 100;
long long n, m, q, ans[N];
unordered_map<long long, pair<long long, long long> > mp[N];
struct node {
  long long u, v, w;
};
bool operator==(node a, node b) {
  return a.u == b.u && a.v == b.v && a.w == b.w;
}
bool operator<(node a, node b) {
  if (a.w != b.w) return a.w < b.w;
  return a.u < b.u || (a.u == b.u && a.v < b.v);
}
multiset<node> s[N];
multiset<long long> all;
inline bool check(node a, node b) {
  return (a.u == b.u || a.u == b.v || a.v == b.u || a.v == b.v);
}
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct edge {
  node sh[8];
  long long w, ans;
  inline void add(node x) {
    for (long long i = 1; i <= w; i++)
      if (!check(sh[i], x)) ans = min(ans, sh[i].w + x.w);
    sh[++w] = x;
    sort(sh + 1, sh + 1 + w);
    if (w >= 7) w--;
  }
} T;
namespace seg {
vector<node> p[N * 4];
inline void change(long long x, long long l, long long r, long long ll,
                   long long rr, node v) {
  if (ll <= l && rr >= r) {
    p[x].push_back(v);
    return;
  }
  long long mid = (l + r) >> 1;
  if (ll <= mid) change(x + x, l, mid, ll, rr, v);
  if (rr > mid) change(x + x + 1, mid + 1, r, ll, rr, v);
}
inline void solve(long long x, long long l, long long r, edge now) {
  for (auto it : p[x]) now.add(it);
  if (l == r) {
    ans[l] = min(ans[l], now.ans);
    return;
  }
  long long mid = (l + r) >> 1;
  solve(x + x, l, mid, now);
  solve(x + x + 1, mid + 1, r, now);
}
}  // namespace seg
inline long long sum(multiset<node> &s) {
  if ((long long)s.size() < 3) return 0x3f3f3f3f3f3f3f3f;
  auto it = s.begin();
  long long ans = 0;
  ans += (*it).w;
  it++;
  ans += (*it).w;
  it++;
  ans += (*it).w;
  return ans;
}
inline void add_edge(long long u, long long v, long long w, long long t) {
  if (u > v) swap(u, v);
  mp[u][v] = make_pair(w, t);
  node x = (node){u, v, w};
  all.erase(all.lower_bound(sum(s[u])));
  all.erase(all.lower_bound(sum(s[v])));
  s[u].insert(x);
  s[v].insert(x);
  all.insert(sum(s[u]));
  all.insert(sum(s[v]));
}
inline void del_edge(long long u, long long v, long long t) {
  if (u > v) swap(u, v);
  long long w = mp[u][v].first;
  node x = (node){u, v, w};
  all.erase(all.lower_bound(sum(s[u])));
  all.erase(all.lower_bound(sum(s[v])));
  s[u].erase(s[u].lower_bound(x));
  s[v].erase(s[v].lower_bound(x));
  all.insert(sum(s[u]));
  all.insert(sum(s[v]));
  seg::change(1, 0, q, mp[u][v].second, t - 1, x);
  mp[u][v] = make_pair(-1, -1);
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) all.insert(sum(s[i]));
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read(), w = read();
    add_edge(u, v, w, 0);
  }
  ans[0] = *all.begin();
  q = read();
  for (long long i = 1; i <= q; i++) {
    long long op = read();
    if (op == 1) {
      long long u = read(), v = read(), w = read();
      add_edge(u, v, w, i);
    } else {
      long long u = read(), v = read();
      del_edge(u, v, i);
    }
    ans[i] = *all.begin();
  }
  for (long long i = 1; i <= n; i++) {
    for (auto it : mp[i])
      if (it.second.first != -1) {
        long long u = i, v = it.first, w = it.second.first;
        seg::change(1, 0, q, it.second.second, q, (node){u, v, w});
      }
  }
  T.ans = 0x3f3f3f3f3f3f3f3f;
  T.w = 0;
  seg::solve(1, 0, q, T);
  for (long long i = 0; i <= q; i++) printf("%lld\n", ans[i]);
}
