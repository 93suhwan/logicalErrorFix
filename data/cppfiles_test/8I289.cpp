#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ceilVal = 1 + ((n - 1) / 3);
    long long floatt = n / 3;
    if (max(floatt, ceilVal) == floatt) {
      cout << floatt << " " << ceilVal % 1000000007 << endl;
    } else {
      cout << ceilVal % 1000000007 << " " << floatt << endl;
    }
  }
  return 0;
}
