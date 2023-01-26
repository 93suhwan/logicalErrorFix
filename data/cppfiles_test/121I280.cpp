#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "0\n";
      continue;
    }
    long long int corr = 0, wron = 0;
    bool c_one = false, w_one = false, c_zero = false, w_zero = false;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        corr++;
        if (a[i] == '1')
          c_one = true;
        else
          c_zero = true;
      } else {
        wron++;
        if (a[i] == '1')
          w_one = true;
        else
          w_zero = true;
      }
    }
    if (corr == 1 && c_one == 1) {
      cout << "1\n";
      continue;
    }
    long long int ans_wron = 0, ans_corr = 0;
    bool wron_pos = false, corr_pos = false;
    if (wron % 2 == 0) {
      if (w_one && w_zero) {
        ans_wron = wron;
        wron_pos = true;
      }
    }
    if (corr % 2 != 0) {
      if (c_one && c_zero) {
        ans_corr = corr;
        corr_pos = true;
      }
    }
    long long int final = 1e15;
    if (wron_pos) {
      final = min(final, ans_wron);
    }
    if (corr_pos) {
      final = min(final, ans_corr);
    }
    if (final == 1e15)
      cout << "-1";
    else
      cout << final;
    cout << "\n";
  }
  return 0;
}
