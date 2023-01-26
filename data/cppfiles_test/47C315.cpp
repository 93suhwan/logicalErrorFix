#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  for (long long _i = 0; _i < t; _i++) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> pos, neg;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 0) {
        pos.push_back(a[i]);
      } else {
        neg.push_back(-a[i]);
      }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long sm_pos = 0, sm_neg = 0;
    for (long long i = (long long)pos.size() - 1; i >= 0; i -= k) {
      sm_pos += 2 * pos[i];
    }
    for (long long i = (long long)neg.size() - 1; i >= 0; i -= k) {
      sm_pos += 2 * neg[i];
    }
    long long sm = sm_pos + sm_neg;
    if (pos.empty()) {
      sm -= neg.back();
    } else if (neg.empty()) {
      sm -= pos.back();
    } else {
      sm -= max(pos.back(), neg.back());
    }
    cout << sm << endl;
  }
}
