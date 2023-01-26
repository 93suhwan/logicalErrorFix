#include <bits/stdc++.h>
using namespace std;
const long long N = 32;
long long timer, cc1, cc;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  boost();
  long long i, t, q, l, r, ans, mid, c = 0, j, z, tc, n, k;
  long long h, m, u, mm, w, x, y, l1, r1, d = 0, mask, v, mx;
  long double f, f1;
  cin >> t;
  vector<pair<long long, long long> > g;
  while (t--) {
    cin >> n;
    long long a[n];
    g.clear();
    priority_queue<pair<long long, long long> > pq;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 0) {
        pq.push(make_pair(a[i], i + 1));
      }
    }
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      if (!pq.empty()) {
        auto p1 = pq.top();
        pq.pop();
        l = p.first;
        l--;
        r = p1.first;
        r--;
        g.push_back(make_pair(p.second, p1.second));
        if (l > 0) pq.push(make_pair(l, p.second));
        if (r > 0) pq.push(make_pair(r, p1.second));
      } else
        break;
    }
    cout << ((long long)g.size()) << '\n';
    for (auto x : g) {
      cout << x.first << " " << x.second << '\n';
    }
  }
  return 0;
}
