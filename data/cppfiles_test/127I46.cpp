#include <bits/stdc++.h>
using namespace std;
long long ceilAB(long long a, long long b) { return (a + b - 1) / b; }
long long Pow(long long c, long long d) {
  return d == 0 ? 1 : c * pow(c, d - 1);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
const int mx = 1e6;
int a[mx];
void solve() {
  int t1;
  cin >> t1;
  while (t1--) {
    int i, j, k, n, m, x, y, z, c = 0, cnt = 0, c2 = 0, c3 = 0;
    string s, s1, s2, s3, s4, t;
    cin >> s >> t;
    int len = s.size();
    sort(s.begin(), s.end());
    for (i = 0; i < len; i++) {
      if (s[i] == 'a') {
        s1 = s1 + s[i];
      } else if (s[i] == 'b') {
        s2 = s2 + s[i];
        c2++;
      } else if (s[i] == 'c') {
        s3 = s3 + s[i];
        c3++;
      } else {
        s4 = s4 + s[i];
      }
    }
    if (s1.size() == 0) {
      cout << s << '\n';
      continue;
    }
    cout << s1;
    if (t[1] == 'b') {
      if (c3 > 1) {
        cout << 'c';
        c3--;
      }
      cout << s2;
      for (i = 1; i <= c3; i++) {
        cout << 'c';
      }
      cout << s4 << '\n';
    } else {
      cout << s2 << s3 << s4 << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
