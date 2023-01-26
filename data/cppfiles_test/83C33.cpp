#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MAX_SIZE = 1000005;
const long long int MAXN = 100000;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long int> ans(n);
    vector<vector<long long int>> pf(n + 1, vector<long long int>(n + 1, 0));
    for (long long int j = n - 1; j >= 1; j--) {
      for (long long int i = j - 1; i >= 0; i--) {
        if (s[i] == s[j]) {
          pf[i][j] = pf[i + 1][j + 1] + 1;
          pf[j][i] = pf[j + 1][i + 1] + 1;
        }
      }
    }
    ans[0] = n;
    for (long long int i = 1; i < n; i++) {
      ans[i] = n - i;
      for (long long int j = 0; j < i; j++) {
        if (s[j] < s[i]) {
          ans[i] = max(ans[i], n - i + ans[j]);
        } else if (s[i] == s[j]) {
          if (i + pf[i][j] < n && s[j + pf[i][j]] < s[i + pf[i][j]]) {
            ans[i] = max(ans[i], n - i - pf[i][j] + ans[j]);
          }
        }
      }
    }
    long long int m = ans[0];
    for (long long int i = 1; i < n; i++) {
      m = max(m, ans[i]);
    }
    cout << m << '\n';
  }
  return 0;
}
