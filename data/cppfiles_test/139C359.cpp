#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size(), sum = 0;
    for (int i = 0; i < n / 2; i++) {
      sum = (s[i] - s[i + n / 2]);
      if (sum != 0) {
        sum = 1;
        break;
      }
    }
    if (sum == 0 && n % 2 == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
