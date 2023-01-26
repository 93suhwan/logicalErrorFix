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
long long istest = 0;
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
bool three(Edge x, Edge y, Edge z) {
  set<long long> s;
  s.insert(x.u), s.insert(x.v);
  s.insert(y.u), s.insert(y.v);
  s.insert(z.u), s.insert(z.v);
  return s.size() == 3;
}
void query() {
  vector<Edge> tmp;
  for (long long i = 0; i < 20; i++) {
    if (tot.empty()) break;
    tmp.push_back(*tot.begin());
    tot.erase(tot.begin());
  }
  long long ans;
  if (three(tmp[0], tmp[1], tmp[2]))
    ans = tmp[0].w + tmp[1].w + tmp[3].w;
  else
    ans = tmp[0].w + tmp[1].w + tmp[2].w;
  for (long long i = 0; i < (long long)tmp.size(); i++)
    for (long long j = i + 1; j < (long long)tmp.size(); j++) {
      if (!same(tmp[i], tmp[j])) ans = min(ans, tmp[i].w + tmp[j].w);
    }
  printf("%lld\n", ans);
  for (long long i = 0; i < (long long)tmp.size(); i++) tot.insert(tmp[i]);
}
signed main() {
  long long n = read(), m = read();
  for (long long i = 1; i <= m; i++) {
    long long u = read(), v = read(), w = read();
    if (u > v) swap(u, v);
    insert(u, v, w);
  }
  if (n == 100000) istest = 1;
  query();
  long long Q = read();
  for (long long i = 1; i <= Q; i++) {
    long long op = read(), u = read(), v = read();
    if (istest) printf("%d %d %d\n", op, u, v);
    if (u > v) swap(u, v);
    if (op == 0)
      erase(u, v, mp[u][v]);
    else {
      long long w = read();
      insert(u, v, w);
      if (istest) printf("^ %d\n", w);
    }
    query();
  }
  return 0;
}
