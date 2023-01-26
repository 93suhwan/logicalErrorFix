#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<string> a(n);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    string res = "abcde";
    long long int ans = 0;
    for (long long int i = 0; i < 5; i++) {
      vector<long long int> f(n, 0);
      for (long long int j = 0; j < n; j++) {
        long long int cnt = 0;
        for (long long int k = 0; k < a[j].length(); k++) {
          if (a[j][k] == res[i]) {
            cnt++;
          } else {
            cnt--;
          }
        }
        f[j] = cnt;
      }
      sort(f.begin(), f.end(), greater<long long int>());
      long long int sum = 0;
      long long int len = 0;
      for (long long int j = 0; j < n; j++) {
        if (sum + f[j] > 0) {
          sum += f[j];
          len++;
        } else {
          break;
        }
      }
      ans = max(ans, len);
    }
    cout << ans << "\n";
  }
  return 0;
}
