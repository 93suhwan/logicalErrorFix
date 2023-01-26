#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e3 + 5;
int t;
ll s, n, k;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> s >> n >> k;
    ll l = max(1ll, n - s + k);
    ll r = min(k, n);
    if (r < l)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
