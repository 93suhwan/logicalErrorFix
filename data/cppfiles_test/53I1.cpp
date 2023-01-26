#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  long long p = 0;
  for (long long i = 0; i < n; i++)
    if (s[i] != c) p = 1;
  if (p == 0)
    cout << 0 << endl;
  else {
    if (s[n - 1] == c) {
      cout << 1 << endl << n << endl;
      return;
    } else {
      if (s[n - 1] != c)
        cout << 2 << endl << n - 1 << " " << n << endl;
      else {
        cout << 1 << endl;
        long long b = 0;
        for (long long i = 0; i < n - 2; i++) {
          if (s[i] == c) b = i + 1;
        }
        cout << b << endl;
      }
    }
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
