#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long a, b;
  cin >> a;
  for (b = 0; b < a; b++) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] != '0') {
        sum++;
        sum = sum + (s[i] - '0');
      }
    }
    if (s[n - 1] != '0') {
      sum -= 1;
    }
    cout << sum << endl;
  }
  return 0;
}
