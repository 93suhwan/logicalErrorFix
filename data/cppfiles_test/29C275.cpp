#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long zero = 0, one = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] == 0)
      zero++;
    else if (a[i] == 1)
      one++;
  }
  long long k = 1;
  while (zero != 0) {
    k *= 2;
    zero--;
  }
  k *= one;
  cout << k << endl;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
