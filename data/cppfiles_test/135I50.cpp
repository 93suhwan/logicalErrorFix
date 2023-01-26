#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7;
const long long int MOD = 1e9 + 7;
long long int div_floor(const long long int &a, const long long int &b) {
  return a / b - (((a ^ b) < 0) and a % b);
}
long long int div_ceil(const long long int &a, const long long int &b) {
  return a / b + (((a ^ b) >= 0) and a % b);
}
long long int binpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a);
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long int binpow(long long int a, long long int b, long long int p) {
  long long int res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}
void solve() {
  int n, k;
  cin >> n >> k;
  multiset<int> m;
  for (long long int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m.insert(x);
  }
  long long int ans = 0;
  for (long long int i = 0; i < n - 2 * k; i++) {
    auto it = m.begin();
    ans += *it;
    m.erase(it);
  }
  while (k) {
    auto it = m.begin();
    auto p = m.lower_bound(*it + 1);
    if (p != m.end()) {
      m.erase(p);
      m.erase(it);
    } else {
      m.erase(it);
      auto it = m.begin();
      m.erase(it);
      ans++;
    }
    k--;
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
