#include <bits/stdc++.h>
using namespace std;
int main() {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    string s;
    cin >> s;
    int times = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'N') {
        times += 1;
      } else
        times += 0;
    }
    if (times == 1) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
  return 0;
}
