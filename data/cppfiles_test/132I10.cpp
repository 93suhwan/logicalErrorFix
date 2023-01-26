#include <bits/stdc++.h>
using namespace std;
int main() {
  int b[6];
  int n;
  cin >> n;
  int a1, a2, a3;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> b[j];
    }
    a1 = b[6] - b[4];
    a2 = b[6] - b[3];
    a3 = b[6] - b[5];
    cout << a3 << " " << a2 << " " << a1;
    if (i != n - 1) cout << "\n";
  }
  return 0;
}
