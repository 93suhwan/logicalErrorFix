#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> randGen;
void init_code() {}
void solve() {
  long long x, n;
  cin >> x >> n;
  if (x % 2) {
    if (n <= 0) {
      cout << x << "\n";
      return;
    }
    x++;
    long long cn = n;
    n--;
    if (n <= 0) {
      cout << x << "\n";
      return;
    }
    long long tm = n % 4;
    n -= (tm);
    x += 4 * (n / 4);
    long long cc = 0;
    for (long long i = n + 2; i < n + 2 + tm; i++) {
      if (cc <= 1)
        x -= i;
      else
        x += i;
      cc++;
    }
    cout << x << "\n";
  } else {
    if (n <= 0) {
      cout << x << "\n";
      return;
    }
    x--;
    long long cn = n;
    n--;
    if (n <= 0) {
      cout << x << "\n";
      return;
    }
    long long tm = n % 4;
    n -= (tm);
    x += -4 * (n / 4);
    long long cc = 0;
    for (long long i = n + 2; i < n + 2 + tm; i++) {
      if (cc <= 1)
        x += i;
      else
        x -= i;
      cc++;
    }
    cout << x << "\n";
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
