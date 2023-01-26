#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
long long t;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    long long n;
    string s;
    cin >> n >> s;
    s += 'B';
    long long p = 0;
    while (p < n && s[p] == '?') ++p;
    long long q = p;
    for (--q; q >= 0; --q) {
      if (s[q + 1] == 'B')
        s[q] = 'R';
      else
        s[q] = 'B';
    }
    for (; p < n; ++p) {
      if (s[p] != '?') continue;
      if (s[p - 1] == 'B')
        s[p] = 'R';
      else
        s[p] = 'B';
    }
    for (long long i = 0; i < n; ++i) cout << s[i];
    cout << endl;
  }
  return 0;
}
