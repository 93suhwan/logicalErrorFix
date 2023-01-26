#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    int flag = 0;
    for (long i = 1; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        flag = 1;
        break;
      }
    }
    if (s2[n - 1] == '1') {
      flag = 1;
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
