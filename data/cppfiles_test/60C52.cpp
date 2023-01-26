#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) { return (a % mod + b % mod) % mod; }
long long mult(long long a, long long b) { return (a % mod * b % mod) % mod; }
long long sub(long long a, long long b) {
  return (a % mod - b % mod + mod) % mod;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long &x : a) cin >> x;
  long long sum = accumulate((a).begin(), (a).end(), 0ll);
  if ((2 * sum) % n != 0) {
    cout << 0 << "\n";
    return;
  }
  long long req = 2 * sum / n;
  map<long long, long long> mp;
  long long ans = 0;
  for (long long num : a) {
    ans += mp[req - num];
    mp[num]++;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
}
