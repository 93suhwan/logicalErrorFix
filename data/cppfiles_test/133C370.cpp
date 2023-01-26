#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    long long int n;
    cin >> n;
    string a, b;
    int s = 0;
    for (int i = 0; i < n - 2; i++) {
      cin >> a;
      if (i == 0) {
        cout << a[0];
      } else {
        if (b[1] != a[0]) {
          cout << b[1] << a[0];
          s = 1;
        } else {
          cout << b[1];
        }
      }
      b = a;
    }
    cout << a[1];
    if (s == 0) {
      cout << "a";
    }
    cout << "\n";
  }
  return 0;
}
