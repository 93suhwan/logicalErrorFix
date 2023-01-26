#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n > 9) {
      cout << (n - 9) / 10 + 1 << endl;
      continue;
    }
    cout << n / 9 << endl;
  }
}
