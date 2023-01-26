#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, sum = 0;
  string s;
  while (t--) {
    cin >> n;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] != 0) {
        sum += s[i] - '0';
        if (i != n - 1) sum++;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
