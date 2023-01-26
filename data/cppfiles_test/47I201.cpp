#include <bits/stdc++.h>
using ll = long long;
using namespace std;
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    deque<int> pos, neg, pos1, neg1;
    for (int i = n - 1; i >= 0; i--) {
      cin >> a[i];
      if (a[i] > 0) pos.push_back(a[i]);
      if (a[i] < 0) neg.push_back(-a[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    pos1 = pos, neg1 = neg;
    ll ans = 0, ans1 = 0;
    while (neg.size()) {
      int idx = min(int(neg.size()), k);
      ll x = neg[idx - 1];
      ans += x;
      for (int i = 0; i < idx; i++) {
        neg.pop_front();
      }
      ans += x;
    }
    neg = pos;
    while (neg.size()) {
      int idx = min(int(neg.size()), k);
      ll x = neg[idx - 1];
      ans += x;
      for (int i = 0; i < idx; i++) {
        neg.pop_front();
      }
      if (neg.size()) ans += x;
    }
    ans1 = ans;
    ans = 0;
    neg = pos1;
    while (neg.size()) {
      int idx = min(int(neg.size()), k);
      ll x = neg[idx - 1];
      ans += x;
      for (int i = 0; i < idx; i++) {
        neg.pop_front();
      }
      ans += x;
    }
    neg = neg1;
    while (neg.size()) {
      int idx = min(int(neg.size()), k);
      ll x = neg[idx - 1];
      ans += x;
      for (int i = 0; i < idx; i++) {
        neg.pop_front();
      }
      if (neg.size()) ans += x;
    }
    ans = min(ans1, ans);
    cout << ans << "\n";
  }
}
