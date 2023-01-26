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
    long long int c_one = 0, w_one = 0, c_zero = 0, w_zero = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        corr++;
        if (a[i] == '1')
          c_one += 1;
        else
          c_zero += 1;
      } else {
        wron++;
        if (a[i] == '1')
          w_one += 1;
        else
          w_zero += 1;
      }
    }
    if (corr == 1 && c_one == 1) {
      cout << "1\n";
      continue;
    }
    long long int ans_wron = 0, ans_corr = 0;
    bool wron_pos = false, corr_pos = false;
    if (wron % 2 == 0) {
      if ((w_one == w_zero)) {
        ans_wron = wron;
        wron_pos = true;
      }
    }
    if (corr % 2 != 0) {
      if ((c_one == c_zero + 1ll)) {
        ans_corr = corr;
        corr_pos = true;
      }
    }
    long long int final = 1e17;
    if (wron_pos) {
      final = min(final, ans_wron);
    }
    if (corr_pos) {
      final = min(final, ans_corr);
    }
    if (final == 1e17)
      cout << "-1";
    else
      cout << final;
    cout << "\n";
  }
  return 0;
}
