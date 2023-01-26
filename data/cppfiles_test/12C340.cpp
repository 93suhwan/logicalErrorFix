#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 == 0 && m % 2 == 0) {
      if (k % 2 == 0)
        cout << "Yes";
      else
        cout << "No";
    } else if (n % 2 != 0 && m % 2 == 0) {
      if (k >= m / 2 && (k - m / 2) % 2 == 0)
        cout << "Yes";
      else
        cout << "No";
    } else {
      int l = n * m / 2 - k;
      if (l >= n / 2 && (l - n / 2) % 2 == 0)
        cout << "Yes";
      else
        cout << "No";
    }
    cout << endl;
  }
  return 0;
}
