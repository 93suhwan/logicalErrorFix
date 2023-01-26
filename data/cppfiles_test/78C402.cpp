#include <bits/stdc++.h>
bool ispoweroftwo(long long int n) { return n & (!(n & (n - 1))); }
using namespace std;
void solve() {
  int l, r;
  cin >> l >> r;
  int a, b = r;
  a = r / 2 + 1;
  if (a < l) a = l;
  if (a > r) a = r;
  cout << b % a << "\n";
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
