#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c = n / 2;
    if (n % 2 == 0) {
      if ((n / 2) % 2 != 0) {
        int c = n / 2;
        for (int i = 0; i < c; i++) {
          cout << "a";
        }
        cout << "b";
        for (int i = 0; i < c - 1; i++) {
          cout << "a";
        }
      } else {
        int c = n / 2 - 1;
        for (int i = 0; i < c; i++) {
          cout << "a";
        }
        cout << "b";
        for (int i = 0; i < c - 1; i++) {
          cout << "a";
        }
        cout << "cd";
      }
    } else {
      int c = (n - 1) / 2 - 1;
      for (int i = 0; i < c; i++) {
        cout << "a";
      }
      cout << "b";
      for (int i = 0; i < c - 1; i++) {
        cout << "a";
      }
      cout << "cdz";
    }
    cout << endl;
  }
}
