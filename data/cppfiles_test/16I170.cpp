#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t, n, i, j, c, k, m, x, y, f, ans;
  cin >> t;
  while (t--) {
    cin >> n;
    priority_queue<pair<long long, long long> > pq;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      pq.push({a[i], i});
    }
    pair<long long, long long> p, q;
    vector<pair<long long, long long> > result;
    while (pq.size() > 1) {
      p = pq.top();
      pq.pop();
      q = pq.top();
      if (p.first * q.first == 0) break;
      pq.pop();
      p.first--;
      q.first--;
      result.push_back({p.first, q.second});
      if (p.first) pq.push(p);
      if (q.first) pq.push(q);
    }
    cout << result.size() << "\n";
    for (auto k : result) cout << k.first << " " << k.second << "\n";
  }
  return 0;
}
