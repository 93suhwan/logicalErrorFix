#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, N = 3e5 + 6;
long long n, k, t;
void solve() {
  cin >> n >> k;
  long long t = 1;
  while (t * 10 <= n) t *= 10;
  while (k > 1) {
    while (n - t < k) t /= 10;
    cout << t << " ";
    n -= t;
    k--;
  }
  cout << n;
}
int main() {
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
}
