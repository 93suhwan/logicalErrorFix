#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      sum += s[i] - '0';
    }
    long long count = 0;
    for (long long i = 0; i < n; ++i) {
      if (s[i] != '0') {
        ++count;
      }
    }
    if (s[n - 1] != '0') {
      --count;
    }
    cout << sum + count << endl;
  }
}
