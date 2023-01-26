#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll s, n, k;
    cin >> s >> n >> k;
    bool ok = 0;
    if (s - n < k && s >= k) ok = 1;
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
