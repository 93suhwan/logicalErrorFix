#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, sum = 0, ans = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n * 2; i++) {
      if (i % 2 == 0)
        cout << '(';
      else
        cout << ')';
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (i == j)
          cout << "(())";
        else
          cout << "()";
      }
      cout << endl;
    }
  }
}
