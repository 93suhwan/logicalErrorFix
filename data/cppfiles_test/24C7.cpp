#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
void solve() {
  int n;
  cin >> n;
  int sum = n / 10;
  if (n % 10 == 9) sum++;
  cout << sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
