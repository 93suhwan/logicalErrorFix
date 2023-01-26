#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626;
const long long mod = 1000000007;
void solve() {
  long long n;
  string s;
  cin >> n >> s;
  long long j = 0;
  while (j < n and s[j] == '?') j++;
  if (j == n) {
    for (long long i = 0; i < n; i++)
      if (i & 1)
        s[i] = 'R';
      else
        s[i] = 'B';
    cout << s << endl;
    return;
  }
  for (long long i = j - 1; i >= 0; i--) {
    if (s[i + 1] == 'R')
      s[i] = 'B';
    else
      s[i] = 'R';
  }
  for (long long i = j; i < n; i++) {
    if (s[i] != '?') continue;
    if (s[i - 1] == 'R')
      s[i] = 'B';
    else
      s[i] = 'R';
  }
  cout << s << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
