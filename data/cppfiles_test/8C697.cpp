#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  long long n;
  while (t--) {
    cin >> n;
    if (n % 3 == 1) {
      cout << (n / 3 + 1) << " " << n / 3 << '\n';
    } else if (n % 3 == 2) {
      cout << n / 3 << " " << (n / 3 + 1) << '\n';
    } else if (n % 3 == 0) {
      cout << n / 3 << " " << n / 3 << '\n';
    }
  }
  return 0;
}
