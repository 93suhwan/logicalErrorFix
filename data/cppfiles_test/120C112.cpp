#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long max_n = 200005, max_bit = 30;
long long prefix[max_n][max_bit];
void prep() {
  for (long long i = 1; i < max_n; i++) {
    for (long long bit = 0; bit < max_bit; bit++)
      prefix[i][bit] = prefix[i - 1][bit] + ((i >> bit) & 1);
  }
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long max_rem = 0;
  for (long long bit = 0; bit < max_bit; bit++)
    max_rem = max(max_rem, prefix[r][bit] - prefix[l - 1][bit]);
  cout << (r - l + 1) - max_rem << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  prep();
  long long t;
  cin >> t;
  while (t--) solve();
}
