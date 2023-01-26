#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  priority_queue<pair<long long, long long> > pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0) pq.push({a[i], i + 1});
  }
  vector<pair<long long, long long> > ans;
  while (pq.size() >= 2) {
    auto tp1 = pq.top();
    pq.pop();
    auto tp2 = pq.top();
    pq.pop();
    tp1.first--, tp2.first--;
    ans.push_back({tp1.second, tp2.second});
    if (tp1.first > 0) pq.push(tp1);
    if (tp2.first > 0) pq.push(tp2);
  }
  cout << ans.size() << endl;
  for (auto x : ans) cout << x.first << " " << x.second << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
