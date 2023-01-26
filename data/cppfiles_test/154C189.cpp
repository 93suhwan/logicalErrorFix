#include <bits/stdc++.h>
struct ch {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b > a) {
    swap(a, b);
  }
  if (c > b) {
    swap(c, b);
  }
  if (b > a) {
    swap(a, b);
  }
  if (a - c == b) {
    cout << "YES"
         << "\n";
  } else if (a == b && c % 2 == 0) {
    cout << "YES"
         << "\n";
  } else if (c == b && a % 2 == 0) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
