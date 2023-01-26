#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<long long>;
const ll mod = 1e9 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int a = 1, b = 1, c = n, d = m;
  int i = 0;
  while (i < n) {
    char u = s[i];
    if (u == 'L') {
      if (d == 1) break;
      b--;
      d--;
    } else if (u == 'R') {
      if (b == m) break;
      b++;
      d++;
    } else if (u == 'D') {
      if (a == n) break;
      a++;
      c++;
    } else {
      if (c == 1) break;
      a--;
      c--;
    }
    if (a <= 0) a = 1;
    if (b <= 0) b = 1;
    if (c > n) c = n;
    if (d > m) d = m;
    i++;
  }
  i--;
  while (i >= 0) {
    char u = s[i];
    if (u == 'L') {
      b++;
    } else if (u == 'R') {
      b--;
    } else if (u == 'D') {
      a--;
    } else {
      a++;
    }
    i--;
  }
  cout << a << ' ' << b << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(15) << fixed;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
