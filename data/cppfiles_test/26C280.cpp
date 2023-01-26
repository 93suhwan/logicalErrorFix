#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long sum = 1;
  for (long long i = 1; i < (2 * n) + 1; i++) {
    if (i != 2) sum = (sum * (i)) % 1000000007;
  }
  cout << sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
