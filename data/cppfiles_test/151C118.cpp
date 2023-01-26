#include <bits/stdc++.h>
using namespace std;
class DSU {
 public:
  const long long N = 500100;
  long long n = 0;
  vector<long long> par, val_to_index, vals;
  void init() {
    vals.assign(N, -1);
    val_to_index.assign(N, -1);
    par.assign(N, -1);
  }
  void append(long long x) {
    if (val_to_index[x] == -1) {
      par[n] = -1;
      val_to_index[x] = n;
      vals[n] = x;
    } else {
      par[n] = -1;
      vals[n] = x;
      long long ind = val_to_index[x];
      Union(ind, n);
    }
    n++;
  }
  void update(long long x, long long y) {
    if (val_to_index[x] == -1) return;
    long long ind = val_to_index[x];
    long long par_ind = getParent(ind);
    vals[par_ind] = y;
    val_to_index[x] = -1;
    if (val_to_index[y] != -1) {
      Union(par_ind, val_to_index[y]);
    } else {
      val_to_index[y] = par_ind;
    }
  }
  long long getParent(long long a) {
    if (par[a] < 0) {
      return a;
    }
    return par[a] = getParent(par[a]);
  }
  void Union(long long a, long long b) {
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
      if (par[a] < par[b]) {
        swap(a, b);
      }
      val_to_index[vals[a]] = b;
      par[b] += par[a];
      par[a] = b;
    }
  }
};
void solve() {
  long long q;
  cin >> q;
  DSU ds;
  ds.init();
  for (long long i = 0; i < q; i++) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long x;
      cin >> x;
      ds.append(x);
    } else {
      long long x, y;
      cin >> x >> y;
      ds.update(x, y);
    }
  }
  for (long long i = 0; i < ds.n; i++) {
    long long par_node = ds.getParent(i);
    cout << ds.vals[par_node] << ' ';
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
