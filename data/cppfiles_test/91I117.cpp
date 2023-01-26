#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 100;
long long n, m, q;
unordered_map<long long, long long> mp[N];
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
set<node> e;
multiset<long long> all;
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
inline bool check(node a, node b) {
  return (a.u == b.u || a.u == b.v || a.v == b.u || a.v == b.v);
}
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
inline void upd_add(multiset<node> &s, node x) {
  if ((long long)s.size() < 3) {
    e.insert(x);
    return;
  }
  auto it = s.begin();
  it++;
  it++;
  if (*it < x) return;
  auto tmp = e.lower_bound(*it);
  if (*tmp == *it) e.erase(tmp);
  e.insert(x);
}
inline void upd_del(multiset<node> &s, node x) {
  if ((long long)s.size() <= 3) {
    auto it = e.lower_bound(x);
    if (*it == x) e.erase(it);
    return;
  }
  auto it = s.begin();
  bool bl = 1;
  if (*it == x) bl = 0;
  it++;
  if (*it == x) bl = 0;
  it++;
  if (*it == x) bl = 0;
  it++;
  if (!bl) {
    auto it = e.lower_bound(x);
    if (*it == x) e.erase(it);
    e.insert(*it);
  }
}
inline void add_edge(long long u, long long v, long long w) {
  if (u > v) swap(u, v);
  mp[u][v] = mp[v][u] = w;
  node x = (node){u, v, w};
  upd_add(s[u], x);
  upd_add(s[v], x);
  all.erase(all.lower_bound(sum(s[u])));
  all.erase(all.lower_bound(sum(s[v])));
  s[u].insert(x);
  s[v].insert(x);
  all.insert(sum(s[u]));
  all.insert(sum(s[v]));
}
inline void del_edge(long long u, long long v) {
  long long w = mp[u][v];
  if (u > v) swap(u, v);
  node x = (node){u, v, w};
  upd_del(s[u], x);
  upd_del(s[v], x);
  all.erase(all.lower_bound(sum(s[u])));
  all.erase(all.lower_bound(sum(s[v])));
  s[u].erase(s[u].lower_bound(x));
  s[v].erase(s[v].lower_bound(x));
  all.insert(sum(s[u]));
  all.insert(sum(s[v]));
}
inline long long solve(multiset<node> &a, multiset<node> &b) {
  if (a.empty() || b.empty()) return 0x3f3f3f3f3f3f3f3f;
  node x = *a.begin(), y = *b.begin();
  if (!check(x, y)) return x.w + y.w;
  long long ans = 0x3f3f3f3f3f3f3f3f;
  auto it = a.begin();
  it++;
  if (it != a.end() && !check(*it, y)) ans = min(ans, (*it).w + y.w);
  it = b.begin();
  it++;
  if (it != b.end() && !check(*it, x)) ans = min(ans, x.w + (*it).w);
  return ans;
}
inline long long getans() {
  node x = (*e.begin());
  auto it = e.begin();
  it++;
  vector<node> f;
  for (; it != e.end(); it++)
    if (!check(*it, x)) break;
  long long ans = (*all.begin());
  if (it != e.end()) ans = min(ans, (*it).w + x.w);
  s[x.u].erase(s[x.u].lower_bound(x));
  s[x.v].erase(s[x.v].lower_bound(x));
  ans = min(ans, solve(s[x.u], s[x.v]));
  s[x.u].insert(x);
  s[x.v].insert(x);
  return ans;
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) all.insert(sum(s[i]));
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read(), w = read();
    add_edge(u, v, w);
  }
  printf("%lld\n", getans());
  q = read();
  while (q--) {
    long long op = read();
    if (op == 1) {
      long long u = read(), v = read(), w = read();
      add_edge(u, v, w);
    } else {
      long long u = read(), v = read();
      del_edge(u, v);
    }
    printf("%lld\n", getans());
  }
}
