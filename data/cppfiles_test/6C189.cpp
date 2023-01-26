#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
set<int> g[N];
int n, m;
int in[N];
void solve() {
  cin >> n >> m;
  int res = n;
  map<int, int> st, num;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    if (num[u] == 0) res--;
    num[u]++;
  }
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 3) {
      cout << res << endl;
    } else if (op == 1) {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      if (num[u] == 0) res--;
      num[u]++;
    } else {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      num[u]--;
      if (num[u] == 0) res++;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  T = 1;
  while (T--) solve();
  return 0;
}
