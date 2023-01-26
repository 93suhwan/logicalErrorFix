#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first < b.first;
  }
};
const long long N = 2e5 + 7;
set<long long> st[N];
signed main() {
  long long n, m, q;
  cin >> n >> m;
  vector<long long> num;
  set<long long> record;
  priority_queue<long long> pq;
  num.assign(n + 1, 0);
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    num[a]++;
  }
  long long zero = 0;
  for (long long i = 1; i <= n; i++) zero += (num[i] == 0);
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long k;
    cin >> k;
    long long u, v;
    if (k == 1) {
      cin >> u >> v;
      num[u]++;
      if (num[u] == 1) zero--;
    } else if (k == 2) {
      cin >> u >> v;
      if (u > v) swap(u, v);
      num[u]--;
      if (num[u] == 0) zero++;
    } else {
      cout << zero << "\n";
    }
  }
}
