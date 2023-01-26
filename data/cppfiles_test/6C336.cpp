#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y == 0 ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return (x / gcd(x, y)) * y; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  vector<long long> mp(n + 2);
  vector<long long> mp2(n + 2);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    mp[u]++;
    if (mp[u] == 1) {
      ans++;
    }
  }
  mp2 = mp;
  long long q;
  cin >> q;
  long long temp = ans;
  for (long long i = 0; i < q; i++) {
    long long x;
    cin >> x;
    if (x == 3) {
      cout << n - temp << '\n';
    } else if (x == 2) {
      long long u, v;
      cin >> u >> v;
      if (u > v) {
        swap(u, v);
      }
      if (mp2[u] == 1) {
        temp--;
      }
      mp2[u]--;
    } else {
      long long u, v;
      cin >> u >> v;
      if (u > v) {
        swap(u, v);
      }
      if (mp2[u] == 0) {
        temp++;
      }
      mp2[u]++;
    }
  }
}
