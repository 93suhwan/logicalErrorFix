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
  while (true) {
    auto adm1 = m1.Admits(sol), adm2 = m2.Admits(sol);
    auto ex1 = Exchange(m1, sol), ex2 = Exchange(m2, sol);
    vector<int> parent(n, -2);
    vector<pair<int, int>> dist(n, make_pair(INF, INF));
    for (int i = 0; i < n; ++i) {
      if (abs(w[i]) == INF) continue;
      if (!sol[i] && adm1[i]) parent[i] = -1, dist[i] = {0, w[i]};
    }
    int ch = 1;
    while (ch--) {
      for (int node = 0; node < n; ++node) {
        for (int vec = 0; vec < n; ++vec) {
          if (abs(w[node]) == X || abs(w[vec]) == X) continue;
          if (parent[node] != -2 && sol[node] != sol[vec]) {
            assert(dist[node].first != INF);
            if (sol[node]) {
              if (ex1[node][vec]) {
                auto now = dist[node];
                now.first += 1;
                now.second += w[vec];
                if (now < dist[vec])
                  dist[vec] = now, parent[vec] = node, ch = 1;
              }
            } else {
              if (ex2[vec][node]) {
                auto now = dist[node];
                now.first += 1;
                now.second -= w[vec];
                if (now < dist[vec])
                  dist[vec] = now, parent[vec] = node, ch = 1;
              }
            }
          }
        }
      }
    }
    pair<int, int> best = {INF, INF};
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
  vector<int> a, b, w, si;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x;
      cin >> x;
      if (i < k && j < k) si.push_back(a.size());
      a.push_back(i);
      b.push_back(j);
      w.push_back(x);
    }
  }
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
