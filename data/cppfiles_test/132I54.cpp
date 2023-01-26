#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int b[7];
    for (int i = 0; i < 7; i++) {
      cin >> b[i];
    }
    cout << (b[6] - b[5]) << " ";
    cout << (b[6] - b[4]) << " ";
    cout << (b[6] - ((b[6] - b[5]) + (b[6] - b[4])));
  }
}
