#include <bits/stdc++.h>
using namespace std;
void solve(long long testcase) {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    string s = "";
    long long f = 0, c = 0;
    while (s.length() < 2 * n) {
      if (f != i) {
        s += '(';
        f++;
        c++;
      } else {
        if (c == n)
          s += ')';
        else {
          s += ')';
          f--;
        }
      }
    }
    cout << s << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long x = 1;
  cin >> x;
  for (long long i = 1; i <= x; i++) solve(i);
  return 0;
}
