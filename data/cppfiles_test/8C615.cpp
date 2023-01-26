#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (((n / 3 + 1) * 1 + (n / 3) * 2) == n) {
      cout << n / 3 + 1 << " " << n / 3 << "\n";
    } else if (((n / 3) * 1 + (n / 3 + 1) * 2) == n) {
      cout << n / 3 << " " << n / 3 + 1 << "\n";
    } else {
      cout << n / 3 << " " << n / 3 << "\n";
    }
  }
  return 0;
}
