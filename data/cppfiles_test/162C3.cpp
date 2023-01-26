#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> vec;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t, n, tmp, tot = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    vec.clear();
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      vec.push_back(tmp);
      tot += tmp;
    }
    ll s = 1, e = tot / n;
    while (s < e) {
      bool isPossible = true;
      ll mid = (s + e) / 2 + 1;
      vector<ll> tmpVec;
      tmpVec.reserve(n);
      for (ll it : vec) tmpVec.push_back(it);
      for (int i = n - 1; i >= 0; i--) {
        if (tmpVec[i] < mid) {
          isPossible = false;
          break;
        } else {
          if (i >= 2) {
            ll k = min((tmpVec[i] - mid) / 3, vec[i] / 3);
            tmpVec[i] -= 3 * k;
            tmpVec[i - 1] += k;
            tmpVec[i - 2] += 2 * k;
          }
        }
      }
      if (isPossible) {
        s = mid;
      } else {
        e = mid - 1;
      }
    }
    cout << e << "\n";
  }
}
