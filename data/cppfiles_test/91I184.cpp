#include <bits/stdc++.h>
using namespace std;
int const N = 200100;
struct Edge {
  int u, v, id;
  long long w;
  Edge(int u = 0, int v = 0, long long w = 0, int id = 0)
      : u(u), v(v), w(w), id(id) {}
  friend bool operator<(Edge a, Edge b) { return a.w > b.w; }
};
struct Edge3 {
  int id;
  long long ws;
  Edge3(int id = 0, long long ws = 0) : id(id), ws(ws) {}
  friend bool operator<(Edge3 a, Edge3 b) { return a.ws > b.ws; }
};
priority_queue<Edge> q[N], qa;
priority_queue<Edge3> qs;
map<pair<int, int>, int> neid;
int nid[N];
int eid, vid;
bool del[N], del3[N], ign[N], add[N];
long long mqs() {
  while (!qs.empty()) {
    Edge3 e = qs.top();
    if (del3[e.id])
      qs.pop();
    else {
      return e.ws;
    }
  }
  return 0x3FFFFFFFFFFFFFFFLL;
}
long long mqq() {
  vector<Edge> ve;
  int sz = 0;
  while (!qa.empty()) {
    Edge e = qa.top();
    if (del[e.id] || ign[e.id])
      qa.pop();
    else {
      ve.push_back(e);
      ++sz;
      qa.pop();
      if (sz >= 6) break;
    }
  }
  long long ret = 0x3FFFFFFFFFFFFFFFLL;
  for (int i = 0; i < (sz); ++i)
    for (int j = i + 1; j < sz; ++j) {
      if (ve[i].u == ve[j].u || ve[i].u == ve[j].v || ve[i].v == ve[j].u ||
          ve[i].v == ve[j].v)
        continue;
      ret = min(ret, ve[i].w + ve[j].w);
    }
  for (int i = 0; i < (sz); ++i) qa.push(ve[i]);
  return ret;
}
long long cal() {
  long long s1 = mqs();
  long long s2 = mqq();
  return min(s1, s2);
}
void sig(int u) {
  int sz = 0;
  vector<Edge> ve;
  while (!q[u].empty()) {
    Edge e = q[u].top();
    q[u].pop();
    if (del[e.id]) continue;
    ign[e.id] = 1;
    ve.push_back(e);
    ++sz;
    if (sz >= 3) break;
  }
  for (int i = 0; i < (sz); ++i) {
    Edge e = ve[i];
    q[u].push(e);
  }
}
void rqs(int u) {
  int sz = 0;
  vector<Edge> ve;
  while (!q[u].empty()) {
    Edge e = q[u].top();
    q[u].pop();
    if (del[e.id]) continue;
    ve.push_back(e);
    ++sz;
    if (sz >= 3) break;
  }
  if (sz == 3) {
    nid[u] = ++vid;
    qs.push(Edge3(nid[u], ve[0].w + ve[1].w + ve[2].w));
  }
  for (int i = 0; i < (sz); ++i) {
    Edge e = ve[i];
    ign[e.id] = 0;
    q[u].push(e);
    if (!add[e.id]) {
      add[e.id] = 1;
      qa.push(e);
    }
  }
}
void ins(int u, int v, int w) {
  if (u > v) swap(u, v);
  Edge ne = Edge(u, v, w, ++eid);
  sig(u);
  sig(v);
  pair<int, int> pr = make_pair(u, v);
  del[neid[pr]] = 1;
  neid[pr] = eid;
  q[u].push(ne);
  q[v].push(ne);
  del3[nid[u]] = del3[nid[v]] = 1;
  rqs(u);
  rqs(v);
}
void dele(int u, int v) {
  if (u > v) swap(u, v);
  pair<int, int> pr = make_pair(u, v);
  del[neid[pr]] = 1;
  del3[nid[u]] = del3[nid[v]] = 1;
  rqs(u);
  rqs(v);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  eid = 0;
  for (int i = 0; i < (m); ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    if (u > v) swap(u, v);
    neid[make_pair(u, v)] = ++eid;
    q[u].push(Edge(u, v, w, eid));
    q[v].push(Edge(u, v, w, eid));
  }
  vid = 0;
  for (int i = 1; i <= (n); ++i) rqs(i);
  printf("%lld\n", cal());
  int qu;
  scanf("%d", &qu);
  while (qu--) {
    int t, u, v, w;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &u, &v, &w);
      ins(u, v, w);
    } else {
      scanf("%d%d", &u, &v);
      dele(u, v);
    }
    printf("%lld\n", cal());
  }
  return 0;
}
