#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k = 0, sum1 = 0, sum2 = 0, mnoz = 0, k1 = 0, k2 = 0;
    string s;
    cin >> s;
    k = 1;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == s[i + 1]) {
        k++;
      } else {
        if (s[i] == '0')
          mnoz = 1;
        else if (s[i] == '1')
          mnoz = 0;
        sum1 = sum1 + (k * mnoz);
        k = 1;
      }
      if (s[i] == '0')
        k1 = 1;
      else if (s[i] == '1')
        k2 = 1;
    }
    if (k1 == 0 and k2 == 1)
      sum2 = 0;
    else if (k1 == 1 and k2 == 0)
      sum2 = 1;
    else if (k1 == 1 and k2 == 1)
      sum2 = 2;
    if (s == "101")
      cout << 1;
    else
      cout << max(sum1, sum2) << endl;
  }
}
