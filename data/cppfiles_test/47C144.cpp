#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long dist = 0;
    vector<int> cordp;
    vector<int> cordm;
    cordp.reserve(n);
    cordm.reserve(n);
    int mi = 1e9 + 1;
    int ma = -1e9 - 1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > 0) {
        cordp.push_back(x);
      } else if (x < 0) {
        cordm.push_back(-x);
      }
      mi = min(mi, x);
      ma = max(mi, x);
    }
    sort(cordp.begin(), cordp.end());
    sort(cordm.begin(), cordm.end());
    if (cordm.size() + cordp.size() == 0) {
      cout << 0 << endl;
    } else {
      int len = cordp.size();
      int st = len % k;
      ll ans = 0;
      if (st == 0) {
        st = k;
      }
      for (int i = st - 1; i < len; i += k) {
        if (i == len - 1) {
          ans += cordp[i];
        } else {
          ans = ans + cordp[i] * 2;
        }
      }
      int len2 = cordm.size();
      int st2 = len2 % k;
      ll ans2 = 0;
      if (st2 == 0) {
        st2 = k;
      }
      for (int i = st2 - 1; i < len2; i += k) {
        if (i == len2 - 1) {
          ans2 += cordm[i];
        } else {
          ans2 = ans2 + cordm[i] * 2;
        }
      }
      ll ans3 = 1e18;
      if (len == 0) {
        ans3 = ans2;
      } else if (len2 == 0) {
        ans3 = ans;
      } else {
        ans3 = min(ans + ans2 + cordp[len - 1], ans + ans2 + cordm[len2 - 1]);
      }
      cout << ans3 << endl;
    }
  }
  return 0;
}
