#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
void inp(T& x) {
  cin >> x;
}
template <class H, class... T>
void inp(H& h, T&... t) {
  inp(h);
  inp(t...);
}
template <class A>
void inp(vector<A>& x) {
  for (auto& a : x) inp(a);
}
void deb_out() { cerr << endl; }
template <typename Head, typename... Tail>
void deb_out(Head H, Tail... T) {
  cerr << ' ' << H;
  deb_out(T...);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1000000007;
const char nl = '\n';
void solve() {
  long long l, r;
  inp(l, r);
  if (r % 2 == 0) {
    if (l > r / 2 + 1)
      cout << r % l << nl;
    else
      cout << r % (r / 2 + 1) << nl;
  } else {
    if (l > (r + 1) / 2)
      cout << r % l << nl;
    else
      cout << r % ((r + 1) / 2) << nl;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t = 1;
  inp(t);
  while (t--) solve();
  return 0;
}
