#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 0) cout << "0 0" << endl;
    if (n == 1) cout << "1 0" << endl;
    if (n == 2) cout << "0 1" << endl;
    if (n >= 3) {
      if (n % 3 == 0) {
        cout << n / 3 << " " << n / 3 << endl;
      } else if (n % 3 == 1) {
        cout << n / 3 + 1 << " " << n / 3 << endl;
      } else if (n % 3 == 2) {
        cout << n / 3 << " " << n / 3 + 1 << endl;
      }
    }
  }
  return 0;
}
