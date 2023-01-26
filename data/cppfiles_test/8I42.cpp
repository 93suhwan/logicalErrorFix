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
  while (idx > 0) {
    ans += bit[idx];
    idx -= idx & -idx;
  }
  return ans;
}
 
long long qry (int l, int r) {
  long long ans = 0;
  while (l > 0 || r > 0) {
    ans += bit[r] - bit[l];
    r -= r & -r;
    l -= l & -l;
  }
  return ans;
}
 
void upd (int idx, long long val) {
  while (idx < mx) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}


vector<long long> nodeValue[mx];
int version[mx], parVersion[mx];
main () {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    nodeValue[i].push_back(abs(v));
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
  for (int i = 1; i < n; i++) {
    int p = hld.getParent(i);
    upd(hld.getNodeIn(i), nodeValue[p][0]+nodeValue[i][0]);
  }
  
  
  vector<query> queries;
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      b--, c = abs(c);
      nodeValue[b].push_back(c);
    }
    if (a == 2) b--, c--;
    queries.push_back(query(a, b, c));
  }
  
  
  for (int i = 0; i < q; i++) {
    if (queries[i].oper == 1) {
      int v = queries[i].u;
      int nodeIn = hld.getNodeIn(v);
      int oldVersion = version[v];
      version[v]++;
      int curVersion = version[v];
      if (v > 0) {
        upd(nodeIn, nodeValue[v][curVersion]-nodeValue[v][oldVersion]);
      }
      int childNodeIn = nodeIn+1;
      if (childNodeIn < n) {
        int childNode = hld.getRevNodeIn(childNodeIn);
        if (hld.getParent(childNode) == v) {
          int oldParVersion = parVersion[childNode];
          upd(childNodeIn, nodeValue[v][curVersion]-nodeValue[v][oldParVersion]);
          parVersion[childNode] = curVersion;
        }
      }
    }
    if (queries[i].oper == 2) {
      int lca = hld.getLCA(queries[i].u, queries[i].v);
      auto a = hld.getPath(queries[i].u, lca);
      auto b = hld.getPath(queries[i].v, lca);
      long long ans = 0;
      
      int lcaIn = hld.getNodeIn(lca);
      for (auto u: a) {
        int frontNode = hld.getRevNodeIn(u.first);
        int upperNode = hld.getParent(frontNode);
        int upperNodeIn = hld.getNodeIn(upperNode);
        long long curUpperNodeValue = nodeValue[upperNode][version[upperNode]];
        long long registredUpperNodeValue = nodeValue[upperNode][parVersion[upperNode]];
        parVersion[upperNode] = version[upperNode];
        if (u.first > 0) upd(u.first, curUpperNodeValue-registredUpperNodeValue);
        ans += qry(max(u.first-1, 0), u.second-1);
      }

      for (auto u: b) {
        int frontNode = hld.getRevNodeIn(u.first);
        int upperNode = hld.getParent(frontNode);
        int upperNodeIn = hld.getNodeIn(upperNode);
        long long curUpperNodeValue = nodeValue[upperNode][version[upperNode]];
        long long registredUpperNodeValue = nodeValue[upperNode][parVersion[upperNode]];
        parVersion[upperNode] = version[upperNode];
        if (u.first > 0) upd(u.first, curUpperNodeValue-registredUpperNodeValue);
        ans += qry(max(u.first-1, 0), u.second-1);
      }
      cout << ans-2*qry(max(lcaIn-1, 0), lcaIn) << endl;
    }
  }
  
}
