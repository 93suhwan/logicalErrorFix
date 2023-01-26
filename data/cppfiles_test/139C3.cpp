#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 == 0) {
      int mid = n / 2;
      int i;
      for (i = 0; i < mid; i++) {
        if (s[i] != s[mid + i]) {
          cout << "NO" << endl;
          break;
        }
      }
      if (i == mid) cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
