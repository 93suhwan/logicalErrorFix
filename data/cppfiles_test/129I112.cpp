#include <bits/stdc++.h>
using namespace std;
const long double err = 1e-7;
const long double pi = 3.1415926535897932384626433832795;
const long long rem = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  for (long long te = 1; te <= tt; te++) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool v = 1;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i] != i + 1) {
        if (2 * (i + 1) < a[i]) {
          cnt++;
        } else {
          v = 0;
          break;
        }
      }
    }
    if (v)
      cout << cnt << "\n";
    else
      cout << -1 << "\n";
  }
}
