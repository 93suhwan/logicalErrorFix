#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = n; i; i--) {
      string s = "";
      int t = i;
      for (int j = 1; j <= i; j++) cout << '(';
      for (int j = t + 1; j <= n + n; j++) {
        if (t)
          cout << ')', t--;
        else
          t++, cout << '(';
      }
      cout << endl;
    }
  }
}
