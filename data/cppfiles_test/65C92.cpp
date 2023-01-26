#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
using ld = long double;
template <typename T>
void _(const char *s, T h) {
  cerr << s << " = " << h << "\n";
}
template <typename T, typename... Ts>
void _(const char *s, T h, Ts... t) {
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
void upx(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
void upn(T &x, U y) {
  if (x > y) x = y;
}
mt19937 rng(300);
const ll N = 201010;
pair<ll, char> a[N];
void go(ll &l, ll &r, ll len) {
  cout << a[r].first << ' ' << a[r].second << '\n';
  r++;
  for (ll i = 0; i < (len - 1); ++i) {
    cout << a[l].first << ' ' << a[l].second << '\n';
    l--;
  }
}
int32_t main() {
  ll n;
  cin >> n;
  for (ll i = 0; i < (n); ++i) cin >> a[i].first;
  sort(a, a + n);
  string second;
  cin >> second;
  a[n - 1].second = second[n - 1];
  for (ll i = n - 2; i >= 0; --i) {
    if (a[i + 1].second == 'R')
      a[i].second = 'L';
    else
      a[i].second = 'R';
  }
  ll h = 1;
  for (ll i = 0; i < (n - 1); ++i) h += second[i] != second[i + 1];
  ll l = n - h - 1, r = n - h;
  ll first = 0;
  for (ll i = 0; i < (n); ++i) {
    if (second[i] != second[first]) {
      go(l, r, i - first);
      first = i;
    }
  }
  go(l, r, n - first);
  return 0;
}
