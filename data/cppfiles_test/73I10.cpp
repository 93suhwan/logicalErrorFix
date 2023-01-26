#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
struct SplayTree {
  struct Node {
    int ch[2] = {0, 0}, p = 0;
    bool flip = 0;
    int lazy = -1;
    int myvalue = -2;
    int pathvalue = -2;
  };
  vector<Node> T;
  SplayTree(int n) : T(n + 1) {}
  void push(int x) {
    if (!x) return;
    int l = T[x].ch[0], r = T[x].ch[1];
    if (T[x].flip) {
      T[l].flip ^= 1, T[r].flip ^= 1;
      swap(T[x].ch[0], T[x].ch[1]);
      T[x].flip = 0;
    }
    if (T[x].lazy != -1) {
      int val = T[x].lazy;
      T[x].myvalue = T[x].pathvalue = val;
      T[l].lazy = val;
      T[r].lazy = val;
      T[x].lazy = -1;
    }
  }
  void pull(int x) {
    int l = T[x].ch[0], r = T[x].ch[1];
    push(l);
    push(r);
    T[x].pathvalue = max({T[x].myvalue, T[l].pathvalue, T[r].pathvalue});
  }
  void set(int x, int d, int y) {
    T[x].ch[d] = y;
    T[y].p = x;
    pull(x);
  }
  void splay(int x) {
    auto dir = [&](int x) {
      int p = T[x].p;
      if (!p) return -1;
      return T[p].ch[0] == x ? 0 : T[p].ch[1] == x ? 1 : -1;
    };
    auto rotate = [&](int x) {
      int y = T[x].p, z = T[y].p, dx = dir(x), dy = dir(y);
      set(y, dx, T[x].ch[!dx]);
      set(x, !dx, y);
      if (~dy) set(z, dy, x);
      T[x].p = z;
    };
    for (push(x); ~dir(x);) {
      int y = T[x].p, z = T[y].p;
      push(z);
      push(y);
      push(x);
      int dx = dir(x), dy = dir(y);
      if (~dy) rotate(dx != dy ? x : y);
      rotate(x);
    }
  }
};
struct LinkCut : SplayTree {
  LinkCut(int n) : SplayTree(n) {}
  int access(int x) {
    int u = x, v = 0;
    for (; u; v = u, u = T[u].p) {
      splay(u);
      int &ov = T[u].ch[1];
      ov = v;
      pull(u);
    }
    return splay(x), v;
  }
  void reroot(int x) {
    access(x);
    T[x].flip ^= 1;
    push(x);
  }
  void link(int u, int v, int id) {
    assert(LCA(u, id) == 0);
    assert(LCA(v, id) == 0);
    Link(u, id);
    Link(v, id);
  }
  void Link(int u, int v) {
    u++;
    v++;
    reroot(u);
    access(v);
    T[u].p = v;
    pull(v);
  }
  void Cut(int u, int v) {
    u++;
    v++;
    reroot(u);
    access(v);
    T[v].ch[0] = T[u].p = 0;
    pull(v);
  }
  void cut(int u, int v, int id) {
    Cut(u, id);
    Cut(v, id);
  }
  int LCA(int u, int v) {
    u++;
    v++;
    if (u == v) return u;
    access(u);
    int ret = access(v);
    return T[u].p ? ret : 0;
  }
  int path(int u, int v) {
    u++;
    v++;
    reroot(u);
    access(v);
    return T[v].pathvalue;
  }
  int getValue(int i) { return path(i, i); }
  void setpath(int u, int v, int i) {
    u++;
    v++;
    reroot(u);
    access(v);
    T[v].lazy = i;
    push(v);
  }
  void uncycle(int u, int v, int i, int ei, int nu, int nv) {
    setpath(nu, nv, -2);
    cut(u, v, i);
    link(nu, nv, ei);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (auto &[u, v] : edges) {
    cin >> u >> v;
    --u, --v;
  }
  LinkCut tree(n + m);
  auto tryInsert = [&](int i) -> bool {
    auto [u, v] = edges[i];
    if (tree.LCA(u, v) == 0) {
      tree.link(u, v, n + i);
      return true;
    }
    int ei = tree.path(u, v);
    if (ei >= 0) {
      return false;
    }
    tree.setpath(u, v, i);
    return true;
  };
  auto erase = [&](int i) {
    auto [u, v] = edges[i];
    assert(tree.LCA(u, v) != 0);
    int ei = tree.getValue(n + i);
    if (ei < 0) {
      tree.cut(u, v, n + i);
      return;
    }
    auto [uu, vv] = edges[ei];
    238;
    ;
    238;
    ;
    tree.uncycle(u, v, n + i, n + ei, uu, vv);
  };
  ll ans = 0;
  int j = 0;
  for (int i = 0; i < m; ++i) {
    assert(j >= i);
    while (j < m && tryInsert(j)) {
      j++;
    }
    ans += j - i;
    erase(i);
  }
  cout << ans << '\n';
  return 0;
}
