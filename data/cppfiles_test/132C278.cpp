#include <bits/stdc++.h>
using namespace std;
int b[10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 7; i++) {
      cin >> b[i];
    }
    sort(b + 1, b + 7 + 1);
    cout << b[1] << " " << b[2] << " " << b[7] - b[1] - b[2] << "\n";
  }
  return 0;
}
