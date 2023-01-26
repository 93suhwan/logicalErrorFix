#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
string alp = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, x = -1, y = 0, z = 0, ans = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        x = i;
      }
    }
    if (x == -1) {
      cout << -1 << "\n";
      continue;
    }
    for (long long i = 1; i <= x + 1; i++) {
      cout << i << " ";
    }
    cout << n + 1 << " ";
    for (long long i = x + 2; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
