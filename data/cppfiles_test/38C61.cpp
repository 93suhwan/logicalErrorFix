#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n % 2 == 1) ++n;
    if (n <= 6) {
      cout << 15 << endl;
      continue;
    }
    cout << n / 2 * 5 << endl;
  }
  return 0;
}
