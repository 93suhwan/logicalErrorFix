#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t;
  cin >> t;
  while (t--) {
    long int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      if (i + (2 * (i + 1)) == n) {
        cout << i << " " << i + 1 << endl;
      } else if ((i + 1) + (2 * (i)) == n) {
        cout << i << " " << i + 1 << endl;
      } else if (i + (2 * (i)) == n) {
        cout << i << " " << i << endl;
      } else if (i == n) {
        cout << i << " "
             << "0" << endl;
      }
    }
  }
}
