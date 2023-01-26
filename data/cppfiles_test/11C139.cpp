#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<string> v(n);
  long long ans = 0;
  for (long long i = 0; i < n; i++) cin >> v[i];
  for (long long C = 0; C < 5; C++) {
    char c = C + 'a';
    vector<long long> freq(n, 0);
    for (long long i = 0; i < n; i++) {
      for (char x : v[i]) {
        if (x == c)
          freq[i]++;
        else
          freq[i]--;
      }
    }
    sort(freq.rbegin(), freq.rend());
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += freq[i];
      if (sum <= 0) {
        ans = max(ans, i);
        break;
      }
    }
    if (sum > 0) ans = max(ans, n);
  }
  cout << ans << endl;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
