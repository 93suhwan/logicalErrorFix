#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2004;
long long n, m;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    n = 10;
    s = " " + s;
    long long c[3];
    c[1] = c[0] = 0;
    bool check = 0;
    for (long long i = 1; i <= 10; i++) {
      if (s[i] != '?') {
        c[i % 2] += s[i] - 48;
      } else {
        if (i % 2 == 1) {
          if (c[1] >= c[0]) c[1]++;
        } else if (c[0] >= c[1])
          c[0]++;
      }
      long long m1 = (10 - i) / 2;
      long long m2 = (10 - i + 1) / 2;
      if (c[1] > c[0] + m2 || c[0] > c[1] + m1) {
        cout << i << endl;
        check = 1;
        break;
      }
    }
    if (!check) cout << 10 << endl;
  }
  return 0;
}
