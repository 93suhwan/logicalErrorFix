#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a = sqrt(n);
  long long p = pow(a + 1, 2);
  if (p - n > a) {
    cout << n - pow(a, 2) << " " << a + 1 << "\n";
    return;
  }
  cout << a + 1 << " " << p - n + 1 << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
