#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
const long long X = 998244353;
void solve() {
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  long long ct = 0;
  for (long long i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      ct += 2;
    } else if (s1[i] == '0') {
      if (i < n - 1 && s1[i + 1] == s2[i + 1] && s1[i + 1] == '1') {
        ct += 2;
        i++;
      } else {
        ct++;
      }
    } else {
      if (i < n - 1 && s1[i + 1] == s2[i + 1] && s1[i + 1] == '0') {
        ct += 2;
        i++;
      }
    }
  }
  cout << ct << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
