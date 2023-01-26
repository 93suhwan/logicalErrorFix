#include <bits/stdc++.h>
using namespace std;
const long long md = 998244353;
vector<bool> p(300006, 1);
long long mx(vector<long long> &a) {
  long long n = a.size();
  long long l = 0, r = n;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (a[m] < a[0])
      r = m;
    else
      l = m;
  }
  return l;
}
bool f(vector<long long> &a, long long i, long long j, long long t) {
  if (i > j) return false;
  if (t > a[j] || t < a[i]) return false;
  while (i <= j) {
    long long m = (i + j) / 2;
    if (a[m] > t)
      j = m - 1;
    else if (a[m] < t)
      i = m + 1;
    else
      return true;
  }
  return false;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long l = 0, r = 0, u = 0, d = 0;
  string s;
  cin >> s;
  long long x = 0, y = 0;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'U')
      y--;
    else if (s[i] == 'D')
      y++;
    else if (s[i] == 'R') {
      x++;
    } else
      x--;
    if ((max(r, x) - min(l, x) + 1 > m) || (max(d, y) - min(u, y) + 1 > n)) {
      break;
    }
    l = min(l, x);
    r = max(r, x);
    u = min(u, y);
    d = max(d, y);
  }
  cout << 1 - u << " " << 1 - l << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
