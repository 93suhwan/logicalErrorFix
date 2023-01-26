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
    long long ind = 0;
    for (long long j = 0; j < n; j++) {
      cin >> a[j];
      if (a[j] >= mx) {
        mx = a[j];
        ind = j;
      }
    }
    cout << max(0LL, mx - ind - 1) << endl;
  }
}
