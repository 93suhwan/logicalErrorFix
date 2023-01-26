#include <bits/stdc++.h>
const long long INF = 1e18;
const long long mINF = (-1) * INF;
const long long N = 1e5 + 5;
using namespace std;
long long power(long long a, long long b) {
  long long result = 1;
  while (b) {
    if (b % 2) result = (result * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return result;
}
void solve() {
  long long n, i, ans, m = 0;
  cin >> n;
  vector<long long> v(n);
  map<long long, long long> mp;
  for (auto &x : v) {
    cin >> x;
    mp[x]++;
  }
  ans = 0;
  if (n == 1) {
    cout << v[0] * v[0] << endl;
    return;
  }
  for (i = 1; i < n; i++) {
    ans = max(ans, v[i] * v[i - 1]);
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
