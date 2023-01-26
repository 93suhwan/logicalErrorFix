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
  if (ok) cout << "Case #" << i << ": ";
}
void pre(long long a) { cout << fixed << setprecision(a); }
void bit(long long x) { __builtin_popcountll(x); }
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
vector<bool> pr(20000 + 1, true);
void set_up() {
  pr[0] = pr[1] = false;
  for (long long i = 2; i * i <= 20000; i++) {
    if (pr[i]) {
      if (i * i <= 20000) {
        for (long long j = i * i; j <= 20000; j += i) pr[j] = false;
      }
    }
  }
  return;
}
void solve() {
  long long n, sum = 0;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (!pr[sum]) {
    cout << n << '\n';
    for (long long i = 1; i <= n; i++) cout << i << " ";
    cout << '\n';
  } else {
    long long pos = 0;
    for (long long i = 0; i < n; i++) {
      if (!pr[sum - a[i]]) {
        pos = i + 1;
        break;
      }
    }
    cout << n - 1 << '\n';
    for (long long i = 1; i <= n; i++) {
      if (i == pos) continue;
      cout << i << " ";
    }
    cout << '\n';
  }
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
