#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int, int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    vSi G(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      if (u > v) swap(u, v);
      G[u].insert(v);
    }
    vi ans;
    bool done = false;
    int N = min(48, n);
    for (int a = 0; a < N and not done; ++a) {
      for (int b = a + 1; b < N and not done; ++b) {
        for (int c = b + 1; c < N and not done; ++c) {
          for (int d = c + 1; d < N and not done; ++d) {
            for (int e = d + 1; e < N and not done; ++e) {
              vi vert = {a, b, c, d, e};
              bool clique = true;
              bool indep = true;
              for (int i = 0; i < 5 and (clique or indep); ++i) {
                for (int j = i + 1; j < 5 and (clique or indep); ++j) {
                  if (G[vert[i]].count(vert[j]))
                    indep = false;
                  else
                    clique = false;
                }
              }
              if (clique or indep) {
                ans = vert;
                done = true;
              }
            }
          }
        }
      }
    }
    if (not done)
      cout << -1 << '\n';
    else {
      for (int i = 0; i < 5; ++i) {
        if (i) cout << ' ';
        cout << ans[i] + 1;
      }
      cout << '\n';
    }
  }
}
