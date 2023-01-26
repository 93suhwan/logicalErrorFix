#include <bits/stdc++.h>
using namespace std;
long long a[2 * 100000][5];
long long tot[2 * 100000];
long long f(long long i, long long n) {
  long long k = 0;
  vector<long long> v;
  for (k = 0; k < n; k++) v.push_back(a[k][i] - (tot[k] - a[k][i]));
  sort(v.begin(), v.end(), greater<long long>());
  long long cur = 0, count = 0;
  for (auto it : v) {
    cur += it;
    if (cur <= 0)
      break;
    else
      count++;
  }
  return count;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, j, ans = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
      tot[i] = 0;
      for (j = 0; j < 5; j++) a[i][j] = 0;
    }
    for (i = 0; i < n; i++) {
      string s;
      cin >> s;
      tot[i] = s.length();
      for (j = 0; j < s.length(); j++) {
        a[i][s[j] - 'a']++;
      }
    }
    for (i = 0; i < 5; i++) ans = max(ans, f(i, n));
    cout << ans << endl;
  }
  return 0;
}
