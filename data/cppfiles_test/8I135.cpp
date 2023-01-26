#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int d = n / 3;
    int m = n % 3;
    if (m % 2 == 0) {
      cout << d << " " << d + 1 << endl;
    } else {
      cout << d + 1 << " " << d << endl;
    }
  }
  return 0;
}
