#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      sum += (s[i] - '0');
      if (s[i] != '0' && i < n - 1) {
        sum++;
      }
    }
    cout << sum << "\n";
  }
  return 0;
}
