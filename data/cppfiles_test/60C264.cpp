#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long INF = 9 * 1e18;
using namespace std;
void solve() {
  long long n, cur;
  cin >> n;
  vector<long long> freq(32);
  for (long long i = 0; i < n; i++) {
    cin >> cur;
    long long a = 0;
    while (cur != 0) {
      if (cur % 2 != 0) {
        freq[a]++;
      }
      cur >>= 1;
      a++;
    }
  }
  long long ans = 0, a = 1;
  for (int i = 0; i < 32; i++) {
    if (freq[i] == n) {
      ans += a;
    }
    a <<= 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q = 1;
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
