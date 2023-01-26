#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    long long dp[n];
    memset(dp, 0, sizeof(dp));
    map<long long, vector<long long>> make_pair, mn;
    for (long long i = 0; i < n; i++) {
      long long x;
      if (s[i] == '-')
        x = -1;
      else
        x = 1;
      long long y;
      if (i & 1)
        y = -1;
      else
        y = 1;
      long long prod = x * y;
      dp[i] = prod;
      if (i) dp[i] += dp[i - 1];
      if (prod > 0) {
        make_pair[dp[i]].push_back(i);
      } else {
        mn[dp[i]].push_back(i);
      }
    }
    for (long long i = 0; i < q; i++) {
      long long l, r;
      cin >> l >> r;
      l--;
      r--;
      long long ans = dp[r];
      if (l) ans -= dp[l - 1];
      ans = abs(ans);
      if (ans) {
        if (ans & 1)
          ans = 1;
        else
          ans = 2;
      }
      cout << ans << "\n";
      if (ans) {
        if (ans == 2) {
          cout << r + 1 << " ";
          r--;
        }
        long long val = dp[r];
        if (l) val -= dp[l - 1];
        long long tofind = val / 2;
        if (l) tofind += dp[l - 1];
        long long ind;
        if (val > 0) {
          tofind++;
          ind = lower_bound(make_pair[tofind].begin(), make_pair[tofind].end(),
                            l) -
                make_pair[tofind].begin();
          ind = make_pair[tofind][ind];
        } else {
          tofind--;
          ind = lower_bound(mn[tofind].begin(), mn[tofind].end(), l) -
                mn[tofind].begin();
          ind = mn[tofind][ind];
        }
        cout << ind + 1 << "\n";
      }
    }
  }
  return 0;
}
