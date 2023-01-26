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
  vector<int> v(n);
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] > 0) {
      q.push({v[i], i + 1});
    }
  }
  vector<pair<int, int>> res;
  while (q.size() > 1) {
    auto a = q.top();
    q.pop();
    auto b = q.top();
    q.pop();
    res.push_back({a.second, b.second});
    if (a.first - 1) q.push({a.first - 1, a.second});
    if (b.first - 1) q.push({b.first - 1, b.second});
  }
  cout << res.size() << "\n";
  for (auto e : res) cout << e.first << " " << e.second << "\n";
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
