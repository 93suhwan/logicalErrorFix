#include <bits/stdc++.h>
using namespace std;
void fast(void) __attribute__((constructor));
void fast(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n / 2; ++i) cout << "a";
  if (n > 1) cout << 'b';
  for (long long i = 0; i < n / 2 - 1; ++i) cout << "a";
  if (n & 1) cout << 'c';
}
signed main(void) {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
