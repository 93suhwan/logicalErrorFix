#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int lp[N + 1];
vector<int> pr;
const int MAXN = 2e5 + 7;
int ar[MAXN];
vector<int> primeFactors(int x) {
  vector<int> rt;
  while (x > 1) {
    rt.push_back(lp[x]);
    while (x % rt.back() == 0) x /= rt.back();
  }
  return rt;
}
struct DSU {
  vector<int> bap;
  vector<int> sz;
  DSU(int n) : bap(n, 0), sz(n, 1) {
    for (int i = 0; i < n; i++) bap[i] = i;
  }
  int parent(int u) {
    if (u == bap[u]) return u;
    return bap[u] = parent(bap[u]);
  }
  bool addEdge(int u, int v) {
    u = parent(u);
    v = parent(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    bap[v] = u;
    sz[u] += sz[v];
    return true;
  }
} dsu(N);
set<int> canBeWith[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N;
         ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    vector<int> pf = primeFactors(ar[i]);
    for (int j = 1; j < pf.size(); j++) {
      dsu.addEdge(pf[0], pf[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<int> pfx = primeFactors(ar[i]);
    vector<int> pfy = primeFactors(ar[i] + 1);
    pfx.insert(pfx.end(), pfy.begin(), pfy.end());
    for (int &x : pfx) x = dsu.parent(x);
    sort(pfx.begin(), pfx.end());
    pfx.erase(unique(pfx.begin(), pfx.end()), pfx.end());
    for (int j = 0; j < pfx.size(); j++) {
      for (int k = j + 1; k < pfx.size(); k++) {
        canBeWith[pfx[j]].insert(pfx[k]);
      }
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    vector<int> spf = primeFactors(ar[s]);
    vector<int> tpf = primeFactors(ar[t]);
    set<int> sts;
    for (int x : spf) sts.insert(dsu.parent(x));
    set<int> tts;
    for (int x : tpf) tts.insert(dsu.parent(x));
    bool same = false;
    for (int x : sts) {
      for (int y : tts) {
        if (x == y) {
          same = true;
          break;
        }
      }
      if (same) break;
    }
    if (same) {
      cout << 0 << "\n";
    } else {
      for (int x : sts) {
        for (int y : tts) {
          int _x = x, _y = y;
          if (x > y) swap(_x, _y);
          if (canBeWith[_x].count(_y)) {
            same = true;
            break;
          }
        }
        if (same) break;
      }
      if (same)
        cout << 1 << "\n";
      else
        cout << 2 << "\n";
    }
  }
  return 0;
}
