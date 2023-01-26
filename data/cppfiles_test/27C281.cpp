#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, z, m = 0, l1, l2, k = 0;
    string s1, s2;
    cin >> s1 >> s2;
    l1 = s1.size();
    l2 = s2.size() - 1;
    for (x = l1 - 1; x >= 0; x--) {
      if (l2 == 0 && s1[x] == s2[0] && m % 2 == 0) {
        k = 1;
        break;
      }
      if (s2[l2] == s1[x] && m % 2 == 0) {
        l2--;
        m = 0;
      } else {
        m++;
      }
    }
    if (k)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
