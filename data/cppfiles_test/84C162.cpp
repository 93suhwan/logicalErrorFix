#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    if (n == 1) cout << s << "\n";
    if (n == 2) cout << s / 2 << "\n";
    if (n > 2) {
      if (n % 2 == 0) cout << s / (n - (n / 2) + 1) << "\n";
      if (n % 2 == 1) cout << s / (n - (n / 2)) << "\n";
    }
  }
  return 0;
}
