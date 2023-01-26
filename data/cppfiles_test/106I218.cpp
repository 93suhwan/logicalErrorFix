#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    for (int ii = 1; ii <= n; ii++) {
      for (int iii = 1; iii <= ii + 2; iii++) {
        cout << 1;
      }
      cout << ' ';
    }
    cout << endl;
  }
  return 0;
}
