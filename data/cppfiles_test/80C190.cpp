#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    char field[n];
    for (int i = 0; i < n; i++) {
      cin >> field[i];
    }
    bool solved = false;
    for (int i = n / 2; i < n; i++) {
      if (field[i] == '0') {
        solved = true;
        cout << "1 " << i + 1 << " 1 " << i << endl;
        break;
      }
    }
    if (!solved) {
      for (int i = 0; i < n / 2; i++) {
        if (field[i] == '0') {
          solved = true;
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
          break;
        }
      }
    }
    if (!solved) {
      cout << "1 " << (n - n % 2) << " 1 " << n / 2 << endl;
    }
    t--;
  }
}
