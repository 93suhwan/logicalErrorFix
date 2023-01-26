#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = "*" + a;
    b = "*" + b;
    vector<long long> dp_pat(2 * (n + 1), 0);
    vector<long long> dp_sol(2 * (n + 1), 0);
    dp_pat[n] = 1;
    for (long long i = 1; i <= n; i++) {
      vector<long long> ndp_pat(2 * (n + 1), 0);
      vector<long long> ndp_sol(2 * (n + 1), 0);
      if (b[i] != '1') {
        if (a[i] != '1') {
          for (int j = 0; j <= 2 * n + 1; j++) {
            ndp_pat[j] += dp_pat[j];
            ndp_pat[j] %= 1000000007;
            ndp_sol[j] += dp_sol[j];
            ndp_sol[j] %= 1000000007;
          }
        }
        if (a[i] != '0') {
          int ccol = i % 2;
          for (int j = 0; j <= 2 * n + 1; j++) {
            if (ccol == 0) {
              if (1 <= j && j <= n) {
                ndp_pat[j - 1] += dp_pat[j];
                ndp_pat[j - 1] %= 1000000007;
                ndp_sol[j - 1] += dp_sol[j];
                ndp_sol[j - 1] %= 1000000007;
                ndp_sol[j - 1] += (1000000007 - i) * dp_pat[j];
                ndp_sol[j - 1] %= 1000000007;
              } else if (n < j) {
                ndp_pat[j - 1] += dp_pat[j];
                ndp_pat[j - 1] %= 1000000007;
                ndp_sol[j - 1] += dp_sol[j];
                ndp_sol[j - 1] %= 1000000007;
                ndp_sol[j - 1] += i * dp_pat[j];
                ndp_sol[j - 1] %= 1000000007;
              }
            } else {
              if (n <= j && j <= 2 * n) {
                ndp_pat[j + 1] += dp_pat[j];
                ndp_pat[j + 1] %= 1000000007;
                ndp_sol[j + 1] += dp_sol[j];
                ndp_sol[j + 1] %= 1000000007;
                ndp_sol[j + 1] += (1000000007 - i) * dp_pat[j];
                ndp_sol[j + 1] %= 1000000007;
              } else if (j < n) {
                ndp_pat[j + 1] += dp_pat[j];
                ndp_pat[j + 1] %= 1000000007;
                ndp_sol[j + 1] += dp_sol[j];
                ndp_sol[j + 1] %= 1000000007;
                ndp_sol[j + 1] += i * dp_pat[j];
                ndp_sol[j + 1] %= 1000000007;
              }
            }
          }
        }
      }
      if (b[i] != '0') {
        if (a[i] != '1') {
          int ccol = (1 - i % 2);
          for (int j = 0; j <= 2 * n + 1; j++) {
            if (ccol == 0) {
              if (1 <= j && j <= n) {
                ndp_pat[j - 1] += dp_pat[j];
                ndp_pat[j - 1] %= 1000000007;
                ndp_sol[j - 1] += dp_sol[j];
                ndp_sol[j - 1] %= 1000000007;
                ndp_sol[j - 1] += (1000000007 - i) * dp_pat[j];
                ndp_sol[j - 1] %= 1000000007;
              } else if (n < j) {
                ndp_pat[j - 1] += dp_pat[j];
                ndp_pat[j - 1] %= 1000000007;
                ndp_sol[j - 1] += dp_sol[j];
                ndp_sol[j - 1] %= 1000000007;
                ndp_sol[j - 1] += i * dp_pat[j];
                ndp_sol[j - 1] %= 1000000007;
              }
            } else {
              if (n <= j && j <= 2 * n) {
                ndp_pat[j + 1] += dp_pat[j];
                ndp_pat[j + 1] %= 1000000007;
                ndp_sol[j + 1] += dp_sol[j];
                ndp_sol[j + 1] %= 1000000007;
                ndp_sol[j + 1] += (1000000007 - i) * dp_pat[j];
                ndp_sol[j + 1] %= 1000000007;
              } else if (j < n) {
                ndp_pat[j + 1] += dp_pat[j];
                ndp_pat[j + 1] %= 1000000007;
                ndp_sol[j + 1] += dp_sol[j];
                ndp_sol[j + 1] %= 1000000007;
                ndp_sol[j + 1] += i * dp_pat[j];
                ndp_sol[j + 1] %= 1000000007;
              }
            }
          }
        }
        if (a[i] != '0') {
          for (int j = 0; j <= 2 * n + 1; j++) {
            ndp_pat[j] += dp_pat[j];
            ndp_pat[j] %= 1000000007;
            ndp_sol[j] += dp_sol[j];
            ndp_sol[j] %= 1000000007;
          }
        }
      }
      dp_pat.swap(ndp_pat);
      dp_sol.swap(ndp_sol);
    }
    cout << dp_sol[n] << '\n';
  }
  return 0;
}
