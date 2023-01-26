#include <bits/stdc++.h>
using ll = long long;
using namespace std;
bool isp(ll x) {
  for (ll i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return x > 1;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> x(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      sum += x[i];
    }
    if (isp(sum)) {
      int idx = 0;
      cout << n - 1 << "\n";
      for (int i = 0; i < n; i++) {
        if (x[i] & 1) idx = i;
      }
      for (int i = 0; i < n; i++) {
        if (idx != i) cout << i + 1 << " ";
      }
      cout << "\n";
      continue;
    }
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
