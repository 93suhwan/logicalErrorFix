#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    if (n == 3) {
      cout << "()()()\n";
      cout << "((()))\n";
      cout << "(()())\n";
    } else {
      for (int j = 0; j < n; ++j) {
        cout << "(";
        int flag = 1;
        int l = 1;
        int r = 1;
        for (int k = 0; k < 2 * n - 2; ++k) {
          int ri = rand() % 2;
          if ((flag == 0) && (l != n)) {
            cout << "(";
            flag++;
            l++;
          } else {
            if ((ri == 0) && (l != n)) {
              cout << "(";
              flag++;
              l++;
            } else if ((ri == 1) && (r != n)) {
              cout << ")";
              flag--;
              r++;
            } else if ((ri == 0) && (l == n)) {
              if (r != n) {
                cout << ")";
                flag--;
                r++;
              }
            } else if ((ri == 1) && (r == n)) {
              if (l != n) {
                cout << "(";
                flag++;
                l++;
              }
            }
          }
        }
        cout << ")\n";
      }
    }
  }
}
