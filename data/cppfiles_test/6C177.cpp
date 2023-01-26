#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vvi = vector<vector<long long> >;
struct Timer {
  clock_t start;
  Timer() { start = clock(); };
  ~Timer() {
    clock_t finish = clock();
    cout << fixed << setprecision(15) << (ld)(finish - start) / CLOCKS_PER_SEC
         << endl;
  };
};
void solve(istream& cin, ostream& cout) {
  long long n, m;
  cin >> n >> m;
  vvi gr(n);
  vector<set<long long> > danger(n);
  for (long long i = 0; i < m; ++i) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  long long cnt = 0;
  vector<bool> killed(n, false);
  for (long long i = 0; i < n; ++i)
    for (long long u : gr[i])
      if (u < i) {
        danger[u].insert(i);
        if (!killed[u]) {
          cnt++;
          killed[u] = true;
        }
      }
  long long q;
  cin >> q;
  while (q--) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u < v) swap(u, v);
      danger[v].insert(u);
      if (!killed[v]) {
        killed[v] = true;
        cnt++;
      }
    } else if (type == 2) {
      long long u, v;
      cin >> u >> v;
      u--;
      v--;
      if (u < v) swap(u, v);
      danger[v].erase(u);
      if (danger[v].empty()) {
        cnt--;
        killed[v] = false;
      }
    } else {
      cout << n - cnt << '\n';
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  while (t--) {
    solve(cin, cout);
  }
  return 0;
}
