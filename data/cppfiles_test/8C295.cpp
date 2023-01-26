#include <bits/stdc++.h>
using namespace std;
void s_y() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1 0\n";
  } else if (n == 2) {
    cout << "0 1\n";
  } else if (n == 3) {
    cout << "1 1\n";
  } else {
    if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << "\n";
    } else if ((n - 2) % 3 == 0) {
      cout << (n - 2) / 3 << " " << ((n - 2) / 3) + 1 << "\n";
    } else {
      cout << ((n - 1) / 3) + 1 << " " << ((n - 1) / 3) << "\n";
    }
  }
}
int main() {
  s_y();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
