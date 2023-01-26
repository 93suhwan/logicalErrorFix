#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)steady_clock::now().time_since_epoch().count());
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class func>
T first_true(T lo, T hi, func first) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class func>
T last_true(T lo, T hi, func first) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remove_duplicates(vector<T>& vec) {
  sort((vec).begin(), (vec).end());
  vec.erase(unique((vec).begin(), (vec).end()), end(vec));
}
void setIO(str S = "") {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(15);
  if ((int)((S).size()) > 0) {
    freopen(S.c_str(), "r", stdin);
    freopen(S.c_str(), "w", stdout);
  }
}
void run_case(int tc = 0) {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a\n";
    return;
  }
  if (n % 2 == 0) {
    cout << string(n / 2, 'a') + string(1, 'b') + string(n / 2 - 1, 'a')
         << "\n";
    return;
  }
  cout << string(n / 2, 'a') + "bs" + string(n / 2 - 1, 'a') << "\n";
}
int32_t main() {
  setIO();
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; ++t) run_case(t);
}
