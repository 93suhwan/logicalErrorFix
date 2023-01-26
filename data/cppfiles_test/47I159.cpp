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
    } else if (cordm.size() == 0) {
      int len = cordp.size();
      vector<ll> sum(k);
      for (int i = 0; i < len; i += k) {
        for (int j = 0; j < k; j++) {
          if (i + j >= len - 1) {
            sum[j] = sum[j] + cordp[len - 1];
          } else if (i + j + k >= len && i + j != len - 1) {
            sum[j] = sum[j] + cordp[i + j] * 2 + cordp[len - 1];
          } else {
            sum[j] = sum[j] + cordp[i + j] * 2;
          }
        }
      }
      ll ans = 1e18;
      for (int i = 0; i < k; i++) {
        ans = min(ans, sum[i]);
      }
      cout << ans << endl;
    } else if (cordp.size() == 0) {
      int len = cordm.size();
      vector<ll> sum(k);
      for (int i = 0; i < len; i += k) {
        for (int j = 0; j < k; j++) {
          if (i + j >= len - 1) {
            sum[j] = sum[j] + cordm[len - 1];
          } else if (i + j + k >= len && i + j != len - 1) {
            sum[j] = sum[j] + cordm[i + j] * 2 + cordm[len - 1];
          } else {
            sum[j] = sum[j] + cordm[i + j] * 2;
          }
        }
      }
      ll ans = 1e18;
      for (int i = 0; i < k; i++) {
        ans = min(ans, sum[i]);
      }
      cout << ans << endl;
    } else {
      int len = cordp.size();
      vector<ll> sum(k);
      for (int i = 0; i < len; i += k) {
        for (int j = 0; j < k; j++) {
          if (i + j >= len - 1) {
            sum[j] = sum[j] + cordp[len - 1];
          } else if (i + j + k >= len && i + j != len - 1) {
            sum[j] = sum[j] + cordp[i + j] * 2 + cordp[len - 1];
          } else {
            sum[j] = sum[j] + cordp[i + j] * 2;
          }
        }
      }
      ll ans = 1e18;
      for (int i = 0; i < k; i++) {
        ans = min(ans, sum[i]);
      }
      int len2 = cordm.size();
      vector<ll> sum2(k);
      for (int i = 0; i < len2; i += k) {
        for (int j = 0; j < k; j++) {
          if (i + j >= len2 - 1) {
            sum2[j] = sum2[j] + cordm[len2 - 1];
          } else if (i + j + k >= len2 && i + j != len2 - 1) {
            sum2[j] = sum2[j] + cordm[i + j] * 2 + cordm[len2 - 1];
          } else {
            sum2[j] = sum2[j] + cordm[i + j] * 2;
          }
        }
      }
      ll ans2 = 1e18;
      for (int i = 0; i < k; i++) {
        ans2 = min(ans, sum2[i]);
      }
      ll ans3 = 1e18;
      ans3 = min(ans + ans2 + cordp[len - 1], ans + ans2 + cordm[len2 - 1]);
      cout << ans3 << endl;
    }
  }
  return 0;
}
