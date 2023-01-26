#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    float sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    cout << ceil(sum / n) - floor(sum / n) << "\n";
  }
  return 0;
}
