#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n;
  cin >> n;
  long long ee = 0, eo = 0, oe = 0, oo = 0;
  for (int i = 0; i < (n); i++) {
    int x, y;
    cin >> x >> y;
    assert(x % 2 == 0 && y % 2 == 0);
    x /= 2;
    y /= 2;
    if (x % 2) {
      if (y % 2) {
        oo++;
      } else {
        oe++;
      }
    } else {
      if (y % 2) {
        eo++;
      } else {
        ee++;
      }
    }
  }
  long long ans = 0;
  ans += oo * (oo - 1) * (oo - 2) / 6;
  ans += oe * (oe - 1) * (oe - 2) / 6;
  ans += eo * (eo - 1) * (eo - 2) / 6;
  ans += ee * (ee - 1) * (ee - 2) / 6;
  ans += oo * (oo - 1) * (n - oo) / 2;
  ans += oe * (oe - 1) * (n - oe) / 2;
  ans += eo * (eo - 1) * (n - eo) / 2;
  ans += ee * (ee - 1) * (n - ee) / 2;
  cout << ans << "\n";
}
