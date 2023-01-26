#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> randGen;
void init_code() {}
void solve() {
  long long x, n;
  cin >> x >> n;
  long long cp = x;
  long long tc = 10;
  long long cn = 1;
  while (tc--) {
    if (x % 2) {
      x += cn;
    } else {
      x -= cn;
    }
    cout << cp - x << "\n";
    cp = x;
    cn++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init_code();
  long long t = 1;
  while (t--) solve();
  return 0;
}
