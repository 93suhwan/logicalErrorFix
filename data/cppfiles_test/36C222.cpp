#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long m = n / 2;
    for (long long i = 0; i < n; i++) {
      if (i < m) {
        cout << "a";
      } else if (i == m) {
        cout << "b";
      } else if (i < n - 1)
        cout << "a";
      else if (i == n - 1 && n & 1)
        cout << "c";
      else
        cout << "a";
    }
    cout << '\n';
  }
  return 0;
}
