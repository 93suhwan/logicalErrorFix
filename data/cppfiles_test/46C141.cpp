#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vi = vector<int>;
using pl = pair<long long, long long>;
using vpl = vector<pl>;
using vl = vector<long long>;
long long tt = 1;
void fastread() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void input(bool ok) {
  if (ok) cin >> tt;
}
void print(bool ok, long long i) {
  if (ok) cout << "Case " << i << ": " << '\n';
}
void pre(long long a) { cout << fixed << setprecision(a); }
long long bit(long long x) { return __builtin_popcountll(x); }
void prefix_sum(long long a[], long long n, long long b[]) {
  partial_sum(a, a + n, b);
}
long long random(long long x) { return rand() % x; }
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
const long long N = 1e5 + 5;
const long long M = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long MX = LLONG_MAX;
const long long MN = LLONG_MIN;
const unsigned long long MXX = ULLONG_MAX;
const long double P = acos(-1.0);
const char cn[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
const string sn[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const string alp1 = "abcdefghijklmnopqrstuvwxyz";
const string alp2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const long long dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
const long long cx[] = {-1, -1, 1, 1}, cy[] = {-1, 1, 1, -1};
const long long dcx[] = {-1, 0, 1, 0, -1, -1, 1, 1},
                dcy[] = {0, 1, 0, -1, -1, 1, 1, -1};
void set_up() { return; }
void solve() {
  long long n;
  cin >> n;
  long long a[n], mx = -1;
  for (long long i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
  long long cnt = 0, cur = -1;
  for (long long i = n - 1; i >= 0; i--) {
    if (a[i] == mx) break;
    if (a[i] > cur) cnt++;
    cur = max(cur, a[i]);
  }
  cout << cnt << '\n';
  return;
}
signed main() {
  fastread();
  set_up();
  input(1);
  long long i = 1;
  do {
    print(0, i);
    solve();
    i++;
  } while (i <= tt);
  exit(0);
}
