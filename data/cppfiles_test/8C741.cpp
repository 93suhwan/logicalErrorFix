#include <bits/stdc++.h>
using namespace std;
int which_coin_more(int n) { return (n % 3); }
void solve() {
  int n;
  cin >> n;
  int a[2] = {n / 3, n / 3};
  if (which_coin_more(n) == 1)
    a[0]++;
  else if (which_coin_more(n) == 2)
    a[1]++;
  cout << a[0] << " " << a[1] << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
