#include <bits/stdc++.h>
using namespace std;
int const N = 300100;
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
priority_queue<Edge> q[N];
priority_queue<Edge> qa;
priority_queue<Edge3> qs;
map<pair<int, int>, int> neid;
int nid[N], mid[N];
int eid, vid, aid;
bool del[N], del1[N], del3[N];
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
  vector<Edge> vu;
  int sz = 0;
  while (!qa.empty()) {
    Edge e = qa.top();
    qa.pop();
    if (del1[e.id])
      continue;
    else {
      vu.push_back(e);
      ++sz;
      if (sz >= 8) break;
    }
  }
  for (int i = 0; i < (sz); ++i) qa.push(vu[i]);
  vector<Edge> ve;
  for (int k = 0; k < (sz); ++k) {
    int u = vu[k].u;
    vector<Edge> vv;
    int vz = 0;
    while (!q[u].empty()) {
      Edge e = q[u].top();
      q[u].pop();
      if (del[e.id]) continue;
      vv.push_back(e);
      ++vz;
      if (vz >= 3) break;
    }
    for (int i = 0; i < (vz); ++i) ve.push_back(vv[i]);
    for (int i = 0; i < (vz); ++i) q[u].push(vv[i]);
  }
  sz = ve.size();
  long long ret = 0x3FFFFFFFFFFFFFFFLL;
  for (int i = 0; i < (sz); ++i)
    for (int j = i + 1; j < sz; ++j) {
      if (ve[i].u == ve[j].u || ve[i].u == ve[j].v || ve[i].v == ve[j].u ||
          ve[i].v == ve[j].v)
        continue;
      ret = min(ret, ve[i].w + ve[j].w);
    }
  return ret;
}
long long cal() {
  long long s1 = mqs();
  long long s2 = mqq();
  return min(s1, s2);
}
void rqs(int u, bool hh) {
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
    q[u].push(e);
  }
  if (hh) {
    del1[mid[u]] = 1;
    if (!q[u].empty()) {
      mid[u] = ++aid;
      Edge e = q[u].top();
      qa.push(Edge(u, u ^ e.u ^ e.v, e.w, mid[u]));
    }
  }
}
void ins(int u, int v, int w) {
  if (u > v) swap(u, v);
  Edge ne = Edge(u, v, w, ++eid);
  pair<int, int> pr = make_pair(u, v);
  del[neid[pr]] = 1;
  neid[pr] = eid;
  q[u].push(ne);
  q[v].push(ne);
  del3[nid[u]] = del3[nid[v]] = 1;
  rqs(u, 1);
  rqs(v, 0);
}
void dele(int u, int v) {
  if (u > v) swap(u, v);
  pair<int, int> pr = make_pair(u, v);
  del[neid[pr]] = 1;
  del3[nid[u]] = del3[nid[v]] = 1;
  rqs(u, 1);
  rqs(v, 0);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  eid = vid = aid = 0;
  for (int i = 0; i < (m); ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    ins(u, v, w);
  }
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
