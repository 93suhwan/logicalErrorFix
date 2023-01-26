#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, sum = 0;
    string s;
    cin >> n >> s;
    for (i = 0; i < s.length() - 1; i++) {
      if (s[i] > 0) {
        sum = sum + s[i] + 1;
      }
      cout << sum << endl;
    }
    cout << sum + s[n - 1] << endl;
  }
  return 0;
}
