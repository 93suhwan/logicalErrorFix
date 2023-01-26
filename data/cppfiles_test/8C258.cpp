#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (abs((n - ((n / 3) * 2)) - (((n / 3) * 2) / 2)) <= 1)
      cout << n - ((n / 3) * 2) << " " << (((n / 3) * 2) / 2) << endl;
    else {
      cout << n - ((n / 3) * 2) - 2 << " " << (((n / 3) * 2) / 2) + 1 << endl;
    }
  }
}
