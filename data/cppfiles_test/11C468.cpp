#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll N = 1e9 + 9, N1 = 1e5 + 7;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s[n];
    for (long long i = 0; i < n; i++) cin >> s[i];
    long long ans = 0;
    for (long long i = 0; i < 5; i++) {
      vector<pair<long long, string>> v;
      char y = 'a' + i;
      for (long long i = 0; i < n; i++) {
        long long a = 0, b = 0;
        for (long long j = 0; j < (long long)s[i].size(); j++) {
          if (s[i][j] == y)
            a++;
          else
            b++;
        }
        v.push_back({a - b, s[i]});
      }
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      long long sum = 0;
      for (long long i = 0; i < n; i++) {
        sum += v[i].first;
        if (sum > 0) {
          ans = max(ans, i + 1);
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
