#include <bits/stdc++.h>
using namespace std;
long long mod = 10e9 + 7;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << " " << 2 * (n / 3) << "\n";
    } else {
      cout << n / 3 << " " << (n / 3) + 1 << "\n";
    }
  }
  return 0;
}
