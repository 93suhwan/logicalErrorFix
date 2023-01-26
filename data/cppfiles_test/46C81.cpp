#include <bits/stdc++.h>
using namespace std;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<long long int, long long int>;
using pd = pair<db, db>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<long long int>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
template <class T>
int upb(V<T>& a, const T& b) {
  return int(upper_bound(begin(a), end(a), b) - begin(a));
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long int BIG = 1e18;
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};
mt19937 rng(0);
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
long long int cdiv(long long int a, long long int b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
long long int fdiv(long long int a, long long int b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  ++hi;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U first) {
  --lo;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <class T, class U>
void erase(T& t, const U& u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(it);
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n + 1], i, flag = 0, maxi = 0, temp = 0, dg = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    if (a[i] > maxi) {
      maxi = a[i];
      temp = i;
    }
  }
  dg = n - 1;
  while (a[dg] != maxi) {
    i = dg - 1;
    while (i >= 0 && (a[i] <= a[dg])) i--;
    dg = i;
    flag++;
  }
  cout << flag << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
