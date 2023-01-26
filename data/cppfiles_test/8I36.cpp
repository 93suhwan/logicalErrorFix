#include <bits/stdc++.h>
using namespace std;

class HLD {
public:
  void init(int n) {
    in.resize(n);
    out.resize(n);
    p.resize(n);
    rin.resize(n);
    sz.resize(n);
    nxt.resize(n);
    h.resize(n);
    edges.resize(n);
  }
  void addEdge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  void setRoot(int r) {
    t = 0;
    p[r] = r;
    h[r] = 0;
    prep(r, r);
    nxt[r] = r;
    hld(r);
  }
  int getParent (int on) { return p[on]; }
  int getNodeIn (int on) { return in[on]; }
  int getRevNodeIn (int t) { return rin[t]; }
  int getLCA(int u, int v) {
    while(!inSubtree(nxt[u], v)) u = p[nxt[u]];
    while(!inSubtree(nxt[v], u)) v = p[nxt[v]];
    return in[u] < in[v] ? u : v;
  }
  // is v in the subtree of u?
  bool inSubtree(int u, int v) { 
    return in[u] <= in[v] && in[v] < out[u];
  }
  // returns ranges [l, r) that the path has
  vector<pair<int, int>> getPath(int u, int anc) {
    vector<std::pair<int, int>> ans;
    //assert(inSubtree(anc, u)); 
    while(nxt[u] != nxt[anc]) {
      ans.emplace_back(in[nxt[u]], in[u] + 1);
      u = p[nxt[u]];
    }
    // this includes the ancestor! care
    ans.emplace_back(in[anc], in[u] + 1);
    return ans;
  }
private:
  vector<int> in, out, p, rin, sz, nxt, h;
  vector<vector<int>> edges;
  int t;
  void prep(int on, int par) {
    sz[on] = 1;
    p[on] = par;
    for(int i = 0; i < (int) edges[on].size(); i++) {
      int &u = edges[on][i];
      if(u == par) {
        swap(u, edges[on].back());
        edges[on].pop_back();
        i--;
      } else {
        h[u] = 1 + h[on];
        prep(u, on);
        sz[on] += sz[u];
        if(sz[u] > sz[edges[on][0]]) {
          swap(edges[on][0], u);
        }
      }
    }
  }
  void hld(int on) {
    in[on] = t++;
    rin[in[on]] = on;
    for(auto u : edges[on]) {
      nxt[u] = (u == edges[on][0] ? nxt[on] : u);
      hld(u);
    }
    out[on] = t;
  }
};

const int mx = 112345;

struct query {
  int oper, u, v;
  query (int oper, int u, int v): oper(oper), u(u), v(v) {};
};

long long bit[mx];
long long qry (int idx) {
  long long ans = 0;
  idx++;
  while (idx > 0) {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}
 
long long qry (int l, int r) {
  long long ans = 0;
  l++, r++;
  while (l > 0 || r > 0) {
    ans += bit[r] - bit[l];
    r -= r & -r;
    l -= l & -l;
  }
  return ans;
}
 
void upd (int idx, long long val) {
  idx++;
  while (idx < mx) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}


int v[mx];
main () {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  HLD hld;
  hld.init(n);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    hld.addEdge(a, b);
  }
  hld.setRoot(0);
  for (int i = 0; i < n; i++) {
    upd(hld.getNodeIn(i), v[i]);
  }
  
  vector<query> queries;
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      b--, c = abs(c);
    }
    if (a == 2) b--, c--;
    queries.push_back(query(a, b, c));
  }
  

  for (int i = 0; i < q; i++) {
    if (queries[i].oper == 1) {
      int u = queries[i].u;
      int nodeIn = hld.getNodeIn(u);
      upd(nodeIn, queries[i].v-v[u]);
      v[u] = queries[i].v;
    }
    if (queries[i].oper == 2) {
      int lca = hld.getLCA(queries[i].u, queries[i].v);
      auto a = hld.getPath(queries[i].u, lca);
      auto b = hld.getPath(queries[i].v, lca);
      long long ans = 0;
      
      int lcaIn = hld.getNodeIn(lca);
      for (auto u: a) {
        ans += qry(max(u.first-1, 0), u.second-1);
      }

      for (auto u: b) {
        ans += qry(max(u.first-1, 0), u.second-1);
      }
      cout << 2*(ans-v[lca])-v[queries[i].u]-v[queries[i].v] << endl;
    }
  }
  
}
