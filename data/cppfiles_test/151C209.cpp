#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long N = 1e5 * 5 + 10;
long long id[N];
vector<long long> pos[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  for (long long i = 0; i < N; i++) id[i] = i;
  long long sz = 0;
  while (q--) {
    long long typ;
    cin >> typ;
    if (typ == 1) {
      long long x;
      cin >> x;
      pos[id[x]].push_back(sz);
      sz++;
    } else {
      long long x, y;
      cin >> x >> y;
      if (x == y) continue;
      if (pos[id[x]].size() > pos[id[y]].size()) swap(id[x], id[y]);
      for (auto to : pos[id[x]]) pos[id[y]].push_back(to);
      pos[id[x]].clear();
    }
  }
  long long a[sz + 1];
  for (long long i = 0; i < N; i++) {
    if (pos[id[i]].size()) {
      for (auto to : pos[id[i]]) a[to] = i;
    }
  }
  for (long long i = 0; i < sz; i++) cout << a[i] << ' ';
  return 0;
}
