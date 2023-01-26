#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return (y == 0 ? x : gcd(y, x % y)); }
long long lcm(long long x, long long y) { return (x / gcd(x, y)) * y; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  map<int, int> mp2;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    mp[u]++;
    if (mp[u] == 1) {
      ans++;
    }
  }
  int q;
  cin >> q;
  int temp = ans;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (x == 3) {
      cout << n - temp << '\n';
      temp = ans;
      mp2 = mp;
    } else if (x == 2) {
      int u, v;
      cin >> u >> v;
      if (u > v) {
        swap(u, v);
      }
      if (mp2[u] == 1) {
        temp--;
      }
      mp2[u]--;
    } else {
      int u, v;
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
