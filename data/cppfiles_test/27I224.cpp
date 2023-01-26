#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    int flag = 0, p = 0;
    for (int i = 0; i < s2.length(); i++) {
      if (i % 2 == 0) {
        while (s1[p] != s2[i] || p % 2 != 1) {
          p++;
          if (p >= s1.length()) break;
        }
      } else {
        while (s1[p] != s2[i] || p % 2 != 0) {
          p++;
          if (p >= s1.length()) break;
        }
      }
      if (p >= s1.length()) break;
      if (i == s2.length() - 1) flag = 1;
    }
    p = 0;
    for (int i = 0; i < s2.length(); i++) {
      if (i % 2 == 1) {
        while (s1[p] != s2[i] || p % 2 != 1) {
          p++;
          if (p >= s1.length()) break;
        }
      } else {
        while (s1[p] != s2[i] || p % 2 != 0) {
          p++;
          if (p >= s1.length()) break;
        }
      }
      if (p >= s1.length()) break;
      if (i == s2.length() - 1) flag = 1;
    }
    if (s2.length() == 0 || flag == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
