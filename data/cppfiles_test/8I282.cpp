#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, tmp, c1 = 0, c2 = 0;
    cin >> n;
    if (n == 1) {
      c1 = 1;
      cout << c1 << " " << c2 << "\n";
      continue;
    }
    if (n == 2) {
      c2 = 1;
      cout << c1 << " " << c2 << "\n";
      continue;
    }
    tmp = n / 3;
    if (n % 2 == 0) {
      if (tmp % 2 == 0) {
        c1 = tmp;
        c2 = (n - tmp) / 2;
      } else {
        c1 = tmp++;
        c2 = (n - tmp) / 2;
      }
    } else {
      if (tmp % 2 == 0) {
        c1 = tmp++;
        c2 = (n - tmp) / 2;
      } else {
        c1 = tmp;
        c2 = (n - tmp) / 2;
      }
    }
    cout << c1 << " " << c2 << "\n";
  }
}
