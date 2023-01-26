#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &a, U b) {
  a = (a > b ? b : a);
}
template <typename T, typename U>
inline void amax(T &a, U b) {
  a = (a > b ? a : b);
}
void solve() {
  int n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << " " << n / 3 << '\n';
  } else {
    int cnt = n / 3;
    n -= n / 3 * 3;
    cout << cnt + (n == 1) << " " << cnt + (n == 2) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
