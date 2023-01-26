#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, k, A, sem, sk, si, sum;
  string s, c;
  cin >> n;
  while (n--) {
    cin >> s;
    cin >> c;
    for (int i = 0; i < s.length(); i++) {
      k = 0;
      A = i;
      count = 0;
      sum = 0;
      if (c[k] == s[i]) {
        while (c[k] == s[i] && i < s.length() && k < c.length()) {
          count++;
          k++;
          i++;
          sem = count;
          if (c[k] == s[i - 2]) {
            sk = k;
            si = i - 2;
            while (c[sk] == s[si] && sk < c.length() && si >= 0) {
              sk++;
              si--;
              sem++;
            }
          }
          if (sum < sem) {
            sum = sem;
          }
        }
      }
      if (sum == c.length()) {
        break;
      }
      i = A;
    }
    if (sum == c.length()) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
