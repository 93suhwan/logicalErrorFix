#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1;
    } else {
      for (int i = 2; i <= n + 1; i++) {
        cout << i << " ";
      }
    }
    cout << endl;
  }
}
