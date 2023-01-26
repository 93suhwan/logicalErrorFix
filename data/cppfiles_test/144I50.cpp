#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int x = n / m + 1, y = n / m, bas = 1, ind = 1;
    for (int i = 0; i < k; i++, bas += x, bas %= n) {
      if (n % m != 0) ind = bas;
      for (int j = 0; j < n % m; j++) {
        cout << x << " ";
        int b = 0;
        while (b < x) {
          if (ind == n + 1) ind = 1;
          cout << ind << " ";
          ind++;
          b++;
        }
        cout << endl;
      }
      for (int j = 0; j < m - n % m; j++) {
        cout << y << " ";
        int b = 0;
        while (b < y) {
          if (ind == n + 1) ind = 1;
          cout << ind << " ";
          ind++;
          b++;
        }
        cout << endl;
      }
    }
  }
}
