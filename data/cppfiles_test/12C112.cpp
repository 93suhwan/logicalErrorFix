#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (m % 2 == 0) {
      if ((k - m / 2) >= 0 && (k - m / 2) % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (k <= (((n * m) / 2) - n / 2) && (k) % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
