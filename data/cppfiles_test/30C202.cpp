#include <bits/stdc++.h>
using namespace std;
const long long mxN = 2e5 + 4;
const long long mod = 1e9 + 7;
const long long INF = 1e17;
using Matrix = vector<vector<long long>>;
using vll = vector<long long>;
using cd = complex<double>;
const double PI = acos(-1);
clock_t begtime = clock();
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long flag = 0;
  long long ans = 1e9;
  for (long long i = 0; i < 26; i++) {
    long long l = 0, r = n - 1;
    long long cnt = 0, p = 1;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        if (s[l] - 'a' == i) {
          cnt++;
          l++;
        } else if (s[r] - 'a' == i) {
          r--;
          cnt++;
        } else {
          p = 0;
          break;
        }
      }
    }
    if (p) {
      flag = 1;
      ans = min(ans, cnt);
    }
  }
  cout << (flag == 0 ? -1 : ans) << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
