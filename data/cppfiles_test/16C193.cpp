#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
void op() {}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  int i = 0;
  while (i < n) {
    int a;
    cin >> a;
    if (a > 0) pq.push({a, i});
    ++i;
  }
  vector<pair<int, int>> vec;
  while (pq.size() > 1) {
    pair<int, int> a = pq.top();
    pq.pop();
    pair<int, int> b = pq.top();
    pq.pop();
    vec.push_back({a.second, b.second});
    a.first = a.first - 1;
    b.first = b.first - 1;
    if (a.first > 0) pq.push(a);
    if (b.first > 0) pq.push(b);
  }
  cout << vec.size() << '\n';
  for (auto itr : vec) cout << itr.first + 1 << " " << itr.second + 1 << '\n';
}
int main() {
  op();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
