#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == 'A') {
        a++;
      }
      if (str[i] == 'B') {
        b++;
      }
      if (str[i] == 'C') {
        c++;
      }
    }
    if (b == (a + c)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
