#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    int boro_line = n / m + 1;
    int x = boro_line * (n % m);
    int baki = m - (n % m);
    int num = 1, p = 1;
    while (k--) {
      for (int i = 0; i < (n % m); i++) {
        cout << boro_line << " ";
        for (int j = 0; j < boro_line; j++) {
          if (num > n) num = 1;
          cout << num++ << " ";
        }
        cout << "\n";
        ;
        p = num;
      }
      for (int i = 0; i < baki; i++) {
        cout << n / m << " ";
        for (int i = 0; i < n / m; i++) {
          if (p > n) p = 1;
          cout << p++ << " ";
        }
        cout << "\n";
        ;
      }
    }
    cout << "\n";
    ;
  }
}
