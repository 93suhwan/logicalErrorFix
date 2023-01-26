#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    bool chk = true;
    string s1, s2;
    cin >> s1 >> s2;
    for (int j = 0; j < n; j++) {
      if (s1[j] == '1' && s2[j] == '1') {
        cout << "NO\n";
        chk = false;
        break;
      }
    }
    if (chk) cout << "YES\n";
  }
  return 0;
}
