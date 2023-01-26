#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int x = n / 3;
  if (n % 3 == 0) cout << x << " " << x << "\n";
  if (n % 3 == 1) cout << x + 1 << " " << x << "\n";
  if (n % 3 == 2) cout << x << " " << x + 1 << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
