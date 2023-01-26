#include <bits/stdc++.h>
long long i, j;
using namespace std;
void solve() {
  long long sum = 0, ans = 1, k, n, m, ct = 0;
  string s = "";
  map<long long, long long> mp;
  set<long long> st;
  vector<pair<long long, long long>> v, v2;
  priority_queue<pair<long long, long long>> pq;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i], pq.push({a[i], i + 1});
  while (pq.size() > 1) {
    auto a1 = pq.top();
    pq.pop();
    auto b = pq.top();
    pq.pop();
    if (a1.first == 0 or b.first == 0) break;
    v.push_back({a1.second, b.second});
    a1.first--;
    b.first--;
    if (a1.first > 0) pq.push({a1.first, a1.second});
    if (b.first > 0) pq.push({b.first, b.second});
  }
  cout << v.size() << "\n";
  for (auto x : v) cout << x.first << " " << x.second << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
