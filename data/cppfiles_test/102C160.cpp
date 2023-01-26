#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using vi = vector<int>;
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
void cdb(int n, db m) { cout << fixed << setprecision(n) << m; }
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
const db eps = 1e-6;
const db PI = acos((db)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  int up = 0, down = 0, left = 0, right = 0;
  int r = 0, c = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'U') c++;
    if (s[i] == 'D') c--;
    if (s[i] == 'L') r--;
    if (s[i] == 'R') r++;
    if (c > 0) up = max(c, up);
    if (c < 0) down = min(c, down);
    if (r > 0) right = max(r, right);
    if (r < 0) left = min(r, left);
    if (up - down + 1 > n) {
      if (s[i] == 'U')
        up--;
      else
        down++;
      break;
    }
    if (right - left + 1 > m) {
      if (s[i] == 'L')
        left++;
      else
        right--;
      break;
    }
  }
  cout << (n - abs(down)) << ' ' << (m - right) << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
