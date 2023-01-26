#include <bits/stdc++.h>
using namespace std;
const int max_size = 1e5 + 10;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << 2 << " " << n - 3 << " " << 1 << "\n";
    return;
  } else {
    for (int i = 2; i < n; i++) {
      if (gcd(i, (n - i - 1)) == 1) {
        cout << i << " " << (n - i - 1) << " " << 1 << "\n";
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
