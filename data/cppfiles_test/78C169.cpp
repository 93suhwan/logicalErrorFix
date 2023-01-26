#include <bits/stdc++.h>
using namespace std;
int Power(int base, int exp) {
  int ans = 1;
  while (exp > 0) {
    if (exp & 1) ans = (1LL * ans * base) % 1000000007;
    exp = exp >> 1;
    base = (1LL * base * base) % 1000000007;
  }
  return ans;
}
void solve() {
  long long int l, r;
  cin >> l >> r;
  long long int x = r / 2;
  if (x >= l) {
    if (r % 2 == 0)
      cout << x - 1 << '\n';
    else
      cout << x << '\n';
  } else
    cout << r % l << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int q = 1;
  cin >> q;
  while (q--) solve();
}
