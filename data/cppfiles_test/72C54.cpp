#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int _runtimeTerror_() {
  pair<int, int> x = {1, 1}, y = {1, 1e9};
  int xd = 1, yd = -1;
  auto get = [&](pair<int, int> a) {
    cout << "? " << a.first << " " << a.second << "\n";
    cout << flush;
    int x;
    cin >> x;
    return x;
  };
  auto tmp = get(x);
  auto tmp2 = get(y);
  if (tmp > tmp2) {
    swap(x, y);
    swap(xd, yd);
    swap(tmp, tmp2);
  }
  int lo = 1, hi = 1e9 - 1;
  pair<int, int> ans = {-1, -1};
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    x.second += xd * mid;
    auto f = get(x);
    if (f == tmp) {
      ans = x;
      x.second -= xd * mid;
      break;
    } else if (f > tmp) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
    x.second -= xd * mid;
  }
  int mid = (x.second + ans.second) / 2;
  int l = 1 + get({1, mid});
  int r = 1e9 - get({1e9, mid});
  int u = 1e9 - get({(l + r) / 2, 1e9});
  int d = 1 + get({(l + r) / 2, 1});
  cout << "! " << l << " " << d << " " << r << " " << u << "\n";
  cout << flush;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
