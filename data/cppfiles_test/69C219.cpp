#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string v = to_string(n);
    int ans = INT_MAX;
    for (ll i = 0; i <= 62; i++) {
      string s = to_string((ll)1 << i);
      int common = 0;
      int k = 0;
      int j = 0;
      while (j < s.size() and k < v.size()) {
        while (s[j] != v[k]) {
          k++;
          if (k == v.size()) {
            break;
          }
        }
        if (s[j] == v[k]) {
          j++;
          k++;
          common++;
        }
      }
      int val = s.size() + v.size() - 2 * common;
      ans = min(ans, val);
    }
    cout << ans << "\n";
  }
}
