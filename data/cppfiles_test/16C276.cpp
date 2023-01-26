#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
int t, n;
vector<int> a;
void solve(priority_queue<pair<long long, int>> &pq) {
  vector<pair<int, int>> ans;
  while (pq.size() > 1) {
    pair<long long, int> p = pq.top();
    pq.pop();
    pair<long long, int> q = pq.top();
    pq.pop();
    p.first--;
    q.first--;
    ans.push_back({p.second, q.second});
    if (p.first > 0) pq.push({p.first, p.second});
    if (q.first > 0) pq.push({q.first, q.second});
  }
  cout << ans.size() << "\n";
  for (pair<int, int> &p : ans) {
    cout << p.first << " " << p.second << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) continue;
      pq.push({a[i], i + 1});
    }
    solve(pq);
    cout << "\n";
  }
  return 0;
}
