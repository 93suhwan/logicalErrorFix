#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t-- > 0) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n / 2 - 1; ++i) cout << 'x';
    cout << 'd';
    for (long long i = 0; i < n / 2; ++i) cout << 'x';
    if (n % 2) cout << 'z';
    cout << "\n";
  }
  return 0;
}
