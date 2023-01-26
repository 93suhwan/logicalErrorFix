#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2) {
      cout << "NO" << endl;
    } else {
      bool check = true;
      for (int i = 0; i < (n / 2); i++) {
        if (s[i] != s[n / 2 + i]) {
          check = false;
        }
      }
      if (check) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
