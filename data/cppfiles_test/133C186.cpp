#include <bits/stdc++.h>
using namespace std;
bool prime(long long p) {
  for (long long i = 2; i <= sqrt(p); i++) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<string> d(n);
    for (int j = 0; j + 2 < n; j++) {
      cin >> d[j];
    }
    bool fl = false;
    for (int j = 0; j + 3 < n; j++) {
      if (d[j][1] != d[j + 1][0]) {
        int z = 0;
        while (j >= z) {
          cout << d[z][0];
          z++;
        }
        cout << d[j][1];
        int y = 1 + j;
        while (n - 2 > y) {
          cout << d[y][0];
          y++;
        }
        cout << d[n - 3][1] << '\n';
        fl = true;
      }
    }
    if (fl == false) {
      for (int j = 0; j + 2 < n; j++) {
        cout << d[j][0];
      }
      cout << d[n - 3][1] << d[n - 3][1] << '\n';
    }
  }
}
