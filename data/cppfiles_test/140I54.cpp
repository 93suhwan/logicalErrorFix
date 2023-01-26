#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n == pow(10, 9))
    cout << floor(pow(n, 1.0 / 2)) + floor(pow(n, 1.0 / 3)) -
                floor(pow(n, 1.0 / 6)) + 1
         << '\n';
  else
    cout << floor(pow(n, 1.0 / 2)) + floor(pow(n, 1.0 / 3)) -
                floor(pow(n, 1.0 / 6))
         << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
