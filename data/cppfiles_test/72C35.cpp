#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ld = long double;
template <typename T>
void _(const char* s, T h) {
  cerr << s << " = " << h << "\n";
}
template <typename T, typename... Ts>
void _(const char* s, T h, Ts... t) {
  int b = 0;
  while (((b += *s == '(') -= *s == ')') != 0 || *s != ',') cerr << *s++;
  cerr << " = " << h << ",";
  _(s + 1, t...);
}
struct init {
  init() {
    cin.tie(0);
    iostream::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(5);
  }
  ~init() {}
} init;
template <typename T, typename U>
void upx(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
void upn(T& x, U y) {
  if (x > y) x = y;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll D = 4, dx[] = {+1, 0, -1, 0}, dy[] = {0, +1, 0, -1};
ll ask(ll x, ll y) {
  cout << "? " << x << ' ' << y << endl;
  ll r;
  cin >> r;
  assert(r != -1);
  return r;
}
int32_t main() {
  const ll m = 1e9;
  ll a = ask(1, 1);
  ll b = ask(m, 1);
  ll sum = m + 1 - b + a;
  if (sum % 2 == 0) {
    ll xm = sum / 2;
    ll yl = ask(xm, 1) + 1;
    ll xl = a + 2 - yl;
    ll xr = xm + (xm - xl);
    ll yr = m - ask(xm, m);
    cout << "! " << xl << ' ' << yl << ' ' << xr << ' ' << yr << endl;
  } else {
    ll xm = sum / 2;
    ll yl = ask(xm, 1) + 1;
    ll xl = a + 2 - yl;
    ll xr = xm + (xm - xl) + 1;
    ll yr = m - ask(xm, m);
    cout << "! " << xl << ' ' << yl << ' ' << xr << ' ' << yr << endl;
  }
  return 0;
}
