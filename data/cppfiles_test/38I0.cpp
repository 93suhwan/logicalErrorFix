#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
bool findans(long long mid, long long n) {
  bool ans = false, ans1 = false, ans2;
  if (n <= 0) {
    return true;
  }
  if (n - ((mid / 15) * 6) <= 0) {
    return true;
  }
  if (mid < 20) {
    return false;
  }
  if (mid >= 25) {
    long long minus = mid / 25, count = minus * 10;
    ans = findans(mid - (minus)*25, n - count);
    if (ans) {
      return true;
    }
  }
  if (mid >= 20) {
    long long minus2 = mid / 20, count2 = minus2 * 8;
    ans1 = findans(mid - (minus2)*20, n - count2);
    if (ans1) return true;
  }
  return findans(mid - (mid / 15) * 15, n - ((mid / 15) * 6));
}
void solve() {
  long long n;
  cin >> n;
  long long l = 15, r = 25000000000050000;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (findans(mid, n)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}
