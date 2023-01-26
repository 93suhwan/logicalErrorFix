#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fxp(long long a, long long b) {
  assert(b >= 0);
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res % mod;
}
inline long long minv(long long x) { return fxp(x, mod - 2); }
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int mXn = 1;
const long long inf = 1e18;
string s1, s2;
int get() {
  int i = 0, j = 0;
  int n = s1.size(), m = s2.size();
  int ans = 0;
  while (i < n && j < m) {
    if (s1[i] != s2[j]) {
      ans++;
      i++;
    } else
      i++, j++;
  }
  if (j == m) {
    ans += (n - 1 - i + 1);
  }
  if (i == n) {
    ans += (m - 1 - j + 1);
  }
  return ans;
}
signed main() {
  c_p_c();
  long long x = 1;
  vector<string> b;
  while (1) {
    string tmp = to_string(x);
    if (tmp.size() > 12) break;
    b.push_back(tmp);
    x *= 2;
  }
  int T;
  cin >> T;
  for (long long tc = 1; tc <= T; tc++) {
    string a;
    cin >> a;
    s1 = a;
    int ans = 1e9;
    for (auto x : b) {
      s2 = x;
      int cans = get();
      ans = min(ans, cans);
    }
    cout << ans << '\n';
  }
}
