#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> randGen;
void init_code() {}
void solve() {
  long long x, n;
  cin >> x >> n;
  long long og = x;
  long long rm = n % 4;
  long long nm = n - n % 4;
  long long cn = 0, tmp = 0;
  for (long long i = nm + 1; i < nm + 1 + rm; i++) {
    if (cn == 1 or cn == 2)
      tmp += i;
    else
      tmp -= i;
    cn++;
  }
  if (x % 2) {
    cout << x - tmp << "\n";
  } else {
    cout << x + tmp << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init_code();
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
