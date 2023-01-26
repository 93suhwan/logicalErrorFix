#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int m = t;
  while (t--) {
    cout << m - t << " ";
    string a;
    cin >> a;
    int b[26] = {0}, i, j, s = 0, l = a.length();
    for (i = 0; i < l; i++) {
      b[a[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
      if (b[i] > 2) s += (b[i] - 2);
    }
    cout << (l - s) / 2 << endl;
  }
  return 0;
}
