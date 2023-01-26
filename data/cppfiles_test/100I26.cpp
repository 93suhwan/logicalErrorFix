#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t, n, sum, min;
  cin >> t;
  while (t--) {
    cin >> n;
    sum = 0;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    min = a[0];
    sum = a[0];
    for (long long i = 1; i < n; i++) {
      a[i] -= sum;
      if (min <= (a[i])) {
        min = a[i];
      } else {
        break;
      }
      sum += a[i];
    }
    cout << min << '\n';
  }
}
