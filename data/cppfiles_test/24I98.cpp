#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    if (stoi(n) < 9) {
      cout << 0 << "\n";
    } else if (stoi(n) == 9) {
      cout << 1 << "\n";
    } else {
      for (int i = 0; i < n.size() - 1; i++) {
        cout << n[i];
      }
      cout << "\n";
    }
  }
  return 0;
}
