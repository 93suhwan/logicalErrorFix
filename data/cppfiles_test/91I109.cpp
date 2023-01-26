#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%d%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
map<long long, long long> mp[100005];
struct Edge {
  long long u, v, w;
  bool operator<(const Edge &x) const {
    if (w != x.w)
      return w < x.w;
    else if (u != x.u)
      return u < x.u;
    else
      return v < x.v;
  }
};
map<Edge, long long> qwq;
set<Edge> eg[100005];
set<Edge> tot;
void del(long long u) {
  long long cnt = 0;
  for (auto i : eg[u]) {
    cnt++;
    if (cnt == 4) break;
    qwq[i]--;
    if (qwq[i] == 0) tot.erase(i);
  }
}
void ins(long long u) {
  long long cnt = 0;
  for (auto i : eg[u]) {
    cnt++;
    if (cnt == 4) break;
    if (qwq[i] == 0) tot.insert(i);
    qwq[i]++;
  }
}
void insert(long long u, long long v, long long w) {
  del(u), del(v);
  mp[u][v] = w;
  eg[u].insert((Edge){u, v, w});
  eg[v].insert((Edge){u, v, w});
  ins(u), ins(v);
}
void erase(long long u, long long v, long long w) {
  del(u), del(v);
  mp[u][v] = 0;
  eg[u].erase((Edge){u, v, w});
  eg[v].erase((Edge){u, v, w});
  ins(u), ins(v);
}
bool same(Edge x, Edge y) {
  return x.u == y.u || x.v == y.u || x.u == y.v || x.v == y.v;
}
void query() {
  vector<Edge> tmp;
  for (long long i = 0; i < 4; i++) {
    tmp.push_back(*tot.begin());
    tot.erase(tot.begin());
  }
  long long ans = tmp[0].w + tmp[1].w + tmp[2].w;
  for (long long i = 0; i < 4; i++)
    for (long long j = i + 1; j < 4; j++) {
      if (!same(tmp[i], tmp[j])) ans = min(ans, tmp[i].w + tmp[j].w);
    }
  printf("%lld\n", ans);
  for (long long i = 0; i < 4; i++) tot.insert(tmp[i]);
}
signed main() {
  long long n = read(), m = read();
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read(), w = read();
    if (u > v) swap(u, v);
    insert(u, v, w);
  }
  query();
  long long Q = read();
  while (Q--) {
    long long op = read(), u = read(), v = read();
    if (u > v) swap(u, v);
    if (op == 0)
      erase(u, v, mp[u][v]);
    else
      insert(u, v, read());
    query();
  }
  return 0;
}
