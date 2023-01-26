#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 200005, K = 10, MOD = 1e9 + 7;
int t, n, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    string s = to_string(n);
    int len = s.length();
    ll val = 0;
    if (k == 1) {
      int d = s[0] - '0';
      if (d == 9)
        val = 1000000005;
      else {
        ++d;
        for (int i = 0; i < len; ++i) {
          val = val * 10 + d;
        }
      }
    } else {
      int d = s[0] - '0';
      if (d == 9)
        val = 1000000005;
      else {
        ++d;
        for (int i = 0; i < len; ++i) {
          val = val * 10 + (i == 0 ? d : 0);
        }
      }
    }
    for (int i = 0; i < len; ++i) {
      if (i != len - 1 && s[i + 1] == '9') continue;
      ll vl2 = 0;
      vector<char> dv(10, 0);
      for (int j = 0; j <= i; ++j) {
        dv[s[j] - '0'] = 1;
      }
      int cnt = 0;
      for (int j = 0; j < 10; ++j) {
        cnt += dv[j];
      }
      if (i == len - 1) {
        val = n;
        break;
      }
      if (cnt > k) break;
      if (cnt == k) {
        for (int j = 0; j <= i; ++j) {
          vl2 = vl2 * 10 + (s[j] - '0');
        }
        int mn = 0;
        while (!dv[mn]) ++mn;
        int lg = s[i + 1] - '0' + 1;
        while (lg < 10 && !dv[lg]) ++lg;
        if (lg == 10) continue;
        vl2 = vl2 * 10 + lg;
        for (int j = i + 2; j < len; ++j) {
          vl2 = vl2 * 10 + mn;
        }
        val = min(val, vl2);
      } else {
        for (int j = 0; j <= i; ++j) {
          vl2 = vl2 * 10 + (s[j] - '0');
        }
        vl2 = vl2 * 10 + s[i + 1] - '0' + 1;
        int mn = 0;
        if (cnt == k - 1)
          while (!dv[mn]) ++mn;
        for (int j = i + 2; j < len; ++j) {
          vl2 = vl2 * 10 + mn;
        }
        val = min(val, vl2);
      }
    }
    cout << val << '\n';
  }
  return 0;
}
