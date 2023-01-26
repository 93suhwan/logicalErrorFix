#include <bits/stdc++.h>
using namespace std;
long long rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long mod = 1e9 + 7;
const long long N = 300050;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    n -= 2;
    string s[n], final = "";
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    long long ok = 0;
    final.push_back(s[0][0]);
    for (long long i = 1; i < n; i++) {
      if (s[i - 1][1] != s[i][0]) {
        final.push_back(s[i - 1][1]);
        final.push_back(s[i][0]);
        ok++;
      } else {
        final.push_back(s[i][0]);
      }
    }
    final.push_back(s[n - 1][1]);
    if (ok == 0) {
      final.push_back(s[n - 1][1]);
    }
    cout << final << '\n';
  }
  return 0;
}
