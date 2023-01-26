#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    int x = 0;
    int j = 1;
    while (x != k) {
      if (j % 3 != 0 && j % 10 != 3) {
        x++;
      }
      j++;
    }
    cout << j - 1 << "\n";
  }
}
