#include <bits/stdc++.h>
bool ispoweroftwo(long long int n) { return n & (!(n & (n - 1))); }
using namespace std;
void solve() {
  long long int l, r;
  cin >> l >> r;
  if (r - l == 1)
    cout << 1 << "\n";
  else
    cout << (r - 1) / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n = 1;
  cin >> n;
  while (n--) solve();
  return 0;
}
