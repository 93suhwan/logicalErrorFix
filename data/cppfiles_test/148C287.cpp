#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll w, h;
    cin >> w >> h;
    ll k;
    ll ans = 0;
    cin >> k;
    vector<ll> v;
    for (int i = 0; i < k; i++) {
      ll x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    ans = max(ans, h * (v[k - 1] - v[0]));
    cin >> k;
    v.clear();
    for (int i = 0; i < k; i++) {
      ll x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    ans = max(ans, h * (v[k - 1] - v[0]));
    cin >> k;
    v.clear();
    for (int i = 0; i < k; i++) {
      ll x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    ans = max(ans, w * (v[k - 1] - v[0]));
    cin >> k;
    v.clear();
    for (int i = 0; i < k; i++) {
      ll x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    ans = max(ans, w * (v[k - 1] - v[0]));
    cout << ans << "\n";
  }
}
