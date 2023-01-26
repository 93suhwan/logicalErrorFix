#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, cnt = 0;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s.length() % 2 != 0) {
      cout << "NO" << endl;
    } else {
      for (int j = 0; j < s.length() / 2; j++) {
        if (s[i] != s[i + (s.length() / 2)]) {
          cout << "NO" << endl;
          cnt++;
          break;
        }
      }
      if (cnt == 0) {
        cout << "YES" << endl;
      }
    }
  }
}
