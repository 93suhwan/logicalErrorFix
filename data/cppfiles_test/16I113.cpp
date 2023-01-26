#include <bits/stdc++.h>
using namespace std;
int GCD(int A, int B) { return (B == 0) ? A : GCD(B, A % B); }
int LCM(int A, int B) { return A * B / GCD(A, B); }
const int mod = 1e9 + 7;
int power(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (res * 1ll * a) % mod;
    n = n >> 1;
    a = (a * 1ll * a) % mod;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  priority_queue<pair<int, int>> q;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    if (v[i] != 0) q.push({v[i], i});
  }
  vector<pair<int, int>> res;
  while (q.size() > 1) {
    auto a = q.top();
    q.pop();
    auto b = q.top();
    q.pop();
    int mini = min(b.first, a.first);
    int t = mini;
    while (t--) {
      res.push_back({a.second, b.second});
    }
    int x = a.first - mini;
    int y = b.first - mini;
    if (x > 0)
      q.push({x, a.second});
    else if (y > 0)
      q.push({y, b.second});
  }
  cout << res.size() << "\n";
  for (auto v : res) cout << v.first << " " << v.second << "\n";
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
