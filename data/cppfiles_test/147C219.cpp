#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int val = 0;
    for (auto kk : s) {
      if (kk == 'N') {
        val++;
      }
    }
    if (val != 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}
