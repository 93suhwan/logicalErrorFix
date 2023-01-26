#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, flag = 0, i;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (i = 0; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        cout << "NO" << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) cout << "YES" << endl;
  }
}
