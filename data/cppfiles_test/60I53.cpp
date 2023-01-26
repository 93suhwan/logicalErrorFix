#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long low(a[0]);
    for (long long i = 1; i < n; i++) {
      low = min(a[i], low);
    }
    long long res(low);
    for (long long i = 0; i < n; i++) {
      res = min(res, low & a[i]);
    }
    cout << res << '\n';
  }
}
