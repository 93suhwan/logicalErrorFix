#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char v[n - 2][2];
    for (int i = 0; i < n - 2; i++)
      for (int j = 0; j < 2; j++) {
        cin >> v[i][j];
      }
    if (n == 3) {
      if (v[0][0] == 'a')
        cout << "b";
      else
        cout << "a";
      cout << v[0][0];
      cout << v[0][1];
      cout << endl;
    } else {
      cout << v[0][0];
      for (int i = 0; i < n - 3; i++) {
        if (v[i][1] != v[i + 1][0]) {
          cout << v[i][1];
          cout << v[i + 1][0];
        } else
          cout << v[i][1];
      }
      cout << v[n - 3][1];
      cout << endl;
    }
  }
  return 0;
}
