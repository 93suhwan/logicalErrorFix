#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  ;
  for (long long i = 0; i < t; i++) {
    ;
    long long n;
    cin >> n;
    ;
    vector<long long> a(n);
    long long mx = 0;
    long long ans = 0;
    long long ind = 1;
    for (long long j = 0; j < n; j++) {
      cin >> a[j];
      ind = j + ans + 1;
      ans += max(0LL, a[j] - ind);
    }
    cout << ans << endl;
  }
}
