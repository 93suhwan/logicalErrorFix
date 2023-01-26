#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int X = 1e6;
struct DSU {
  vector<int> link;
  DSU(int n) : link(n, -1) {}
  int Find(int x) {
    if (link[x] == -1) return x;
    return link[x] = Find(link[x]);
  }
  bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
      link[a] = b;
      return true;
    }
    return false;
  }
};
struct Tree {
  int n;
  vector<int> a, b;
  Tree(int n, vector<int> a, vector<int> b) : n(n), a(a), b(b) {}
  vector<bool> Admits(vector<bool> sol) {
    DSU D(n);
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (sol[i]) D.Union(a[i], b[i]);
    }
    vector<bool> ret(sol.size(), false);
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (!sol[i] && D.Find(a[i]) != D.Find(b[i])) ret[i] = true;
    }
    return ret;
  }
};
struct Color {
  vector<int> v, a, b;
  Color(vector<int> v, vector<int> a, vector<int> b) : v(v), a(a), b(b) {}
  vector<bool> Admits(vector<bool> sol) {
    vector<int> w = v;
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (sol[i]) w[a[i]] -= 1, w[b[i]] -= 1;
    }
    vector<bool> ret(sol.size(), false);
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (sol[i]) continue;
      ret[i] = (w[a[i]] > 0 && w[b[i]] > 0);
    }
    return ret;
  }
};
template <typename M1>
vector<vector<bool>> Exchange(M1& M, vector<bool> sol) {
  vector<vector<bool>> ret(sol.size());
  for (int i = 0; i < (int)sol.size(); ++i) {
    if (!sol[i]) continue;
    sol[i] = 0;
    ret[i] = M.Admits(sol);
    sol[i] = 1;
  }
  return ret;
}
template <class M1, class M2>
int MatroidIntersection(vector<int> w, M1 m1, M2 m2) {
  int n = w.size();
  vector<bool> sol(n, false);
  for (int i = 0; i < n; ++i)
    if (w[i] == -X) sol[i] = true;
  vector<int> q;
  while (true) {
    auto adm1 = m1.Admits(sol), adm2 = m2.Admits(sol);
    auto ex1 = Exchange(m1, sol), ex2 = Exchange(m2, sol);
    q.clear();
    vector<int> inq(n, false);
    vector<int> parent(n, -2);
    vector<int> dist(n, INF);
    auto push = [&](int i, int p, int d) {
      if (d >= dist[i]) return;
      dist[i] = d;
      parent[i] = p;
      if (!inq[i]) q.push_back(i), inq[i] = 1;
    };
    for (int i = 0; i < n; ++i) {
      if (abs(w[i]) == X) continue;
      if (!sol[i] && adm1[i]) {
        push(i, -1, w[i]);
      }
    }
    int ch = 1, iter = 0;
    for (int i = 0; i < (int)q.size(); ++i) {
      int node = q[i];
      inq[node] = 0;
      for (int vec = 0; vec < n; ++vec) {
        if (abs(w[vec]) == X) continue;
        if (sol[node] != sol[vec]) {
          assert(dist[node] != INF);
          if (sol[node]) {
            if (ex1[node][vec]) push(vec, node, dist[node] + w[vec]);
          } else {
            if (ex2[vec][node]) push(vec, node, dist[node] - w[vec]);
          }
        }
      }
    }
    int best = INF;
    int choose = -1;
    for (int node = 0; node < n; ++node) {
      if (abs(w[node]) == X) continue;
      if (!sol[node] && adm2[node] && parent[node] != -2) {
        auto now = dist[node];
        if (now < best) {
          best = now;
          choose = node;
        }
      }
    }
    if (choose == -1) break;
    for (int node = choose; node != -1; node = parent[node]) {
      sol[node] = !sol[node];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (sol[i]) {
      ans += w[i];
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v(n, n);
  for (int i = 0; i < k; ++i) cin >> v[i];
  vector<int> a, b, w;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x;
      cin >> x;
      a.push_back(i);
      b.push_back(j);
      w.push_back(x);
    }
  }
  int m = a.size();
  vector<int> o(m);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](int a, int b) { return w[a] < w[b]; });
  vector<int> na, nb, nw, si;
  DSU D(n);
  for (auto i : o) {
    if (a[i] < k && b[i] < k) si.push_back(na.size());
    if (a[i] < k || b[i] < k || D.Union(a[i], b[i])) {
      na.push_back(a[i]);
      nb.push_back(b[i]);
      nw.push_back(w[i]);
    }
  }
  a = na;
  b = nb;
  w = nw;
  int sol = INF;
  for (int msk = 0; msk < (1 << si.size()); ++msk) {
    DSU D(n);
    vector<int> now_w = w;
    vector<int> ww = v;
    int delta = 0;
    bool bad = false;
    for (int i = 0; i < (int)si.size(); ++i) {
      if (msk & (1 << i)) {
        if (!D.Union(a[si[i]], b[si[i]])) bad = true;
        if (--ww[a[si[i]]] < 0 || --ww[b[si[i]]] < 0) bad = true;
        delta += w[si[i]] + X;
        now_w[si[i]] = -X;
      } else
        now_w[si[i]] = X;
    }
    if (bad) continue;
    Tree T(n, a, b);
    Color C(v, a, b);
    auto now = MatroidIntersection(now_w, T, C);
    sol = min(sol, now + delta);
  }
  cout << sol << endl;
  return 0;
}
