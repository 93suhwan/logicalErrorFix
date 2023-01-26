#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long n;
    cin >> n;
    string st = "";
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    for (long long i = 1; i <= n; i++) {
      st = st + "11";
      cout << st + "1"
           << " ";
    }
    cout << endl;
  }
}
