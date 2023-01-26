#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int persons;
    if (n % m == 0) {
      persons = n / m;
      while (k--) {
        int counter = 1;
        for (int i = 0; i < m; i++) {
          cout << n / m << " ";
          for (int j = 0; j < persons; j++) {
            cout << counter << " ";
            counter++;
          }
          cout << '\n';
        }
      }
    } else {
      persons = n / m + 1;
      int shift = 0;
      while (k--) {
        int counter = 1;
        for (int i = 0; i < m - 1; i++) {
          cout << persons << " ";
          for (int j = 0; j < persons; j++) {
            cout << ((counter + shift) % n == 0 ? n : ((counter + shift) % n))
                 << " ";
            counter++;
          }
          cout << '\n';
        }
        cout << persons - 1 << " ";
        for (int i = 0; i < persons - 1; i++) {
          cout << ((counter + shift) % n == 0 ? n : ((counter + shift) % n))
               << " ";
          counter++;
        }
        shift += persons;
        cout << '\n';
      }
    }
  }
  return 0;
}
