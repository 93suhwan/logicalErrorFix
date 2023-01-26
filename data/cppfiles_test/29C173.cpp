#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vector<ll>>;
using pi = pair<int, int>;
ll inf = 999999999;
ll mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll zeros = 0, ones = 0;
    int x;
    for (ll i = 0; i < n; i++) {
      cin >> x;
      if (x == 0) zeros++;
      if (x == 1) ones++;
    }
    ll ans = pow(2, zeros) * ones;
    cout << ans << "\n";
  }
  return 0;
}
