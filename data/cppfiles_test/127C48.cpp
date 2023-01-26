#include <bits/stdc++.h>
using namespace std;
long long ceilAB(long long a, long long b) { return (a + b - 1) / b; }
long long Pow(long long c, long long d) {
  return d == 0 ? 1 : c * pow(c, d - 1);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
void solve() {
  int t1;
  cin >> t1;
  while (t1--) {
    int i, j, k, n, m, x, y, z, c = 0, cnt = 0, c2 = 0, c3 = 0;
    string s, s1, s2, s3, s4, t;
    cin >> s >> t;
    int len = s.size();
    sort(s.begin(), s.end());
    if (t[0] != 'a' || t[1] != 'b') {
      cout << s << '\n';
      continue;
    }
    int a[29] = {0};
    for (i = 0; i < len; i++) {
      a[s[i] - 'a']++;
    }
    if (a[1] == 0 || a[2] == 0 || a[0] == 0) {
      cout << s << '\n';
      continue;
    }
    if (t[1] == 'b') {
      for (i = 0; i < a[0]; i++) {
        cout << 'a';
      }
      for (i = 0; i < a[2]; i++) {
        cout << 'c';
      }
      a[2] = 0;
      char ch = 'b';
      for (i = 1; i < 27; i++, ch++) {
        for (j = 0; j < a[i]; j++) {
          cout << ch;
        }
      }
      cout << '\n';
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
