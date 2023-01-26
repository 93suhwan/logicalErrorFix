#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  c_p_c();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long x;
    cin >> x;
    for (long long i = 0; i < n - 1; i++) {
      long long k;
      cin >> k;
      x &= k;
    }
    cout << x << endl;
  }
  return 0;
}
