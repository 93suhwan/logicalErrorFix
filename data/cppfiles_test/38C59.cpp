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
  }
  return (ans || ans1);
}
void solve() {
  long long n;
  cin >> n;
  if (n > 6)
    cout << ((n + 1) / 2) * 5 << endl;
  else
    cout << 15 << endl;
}
